class LFUCache {
private:
    struct Node {
        int key, val, cnt;
        Node *prev, *next;
        Node(int k, int v) : key(k), val(v), cnt(1), prev(nullptr), next(nullptr) {}
    };

    struct List {
        int size;
        Node *head, *tail;
        List() {
            head = new Node(0, 0);
            tail = new Node(0, 0);
            head->next = tail;
            tail->prev = head;
            size = 0;
        }
        void addFront(Node* n) {
            n->next = head->next;
            n->prev = head;
            head->next->prev = n;
            head->next = n;
            size++;
        }
        void removeNode(Node* n) {
            n->prev->next = n->next;
            n->next->prev = n->prev;
            size--;
        }
    };

    unordered_map<int, Node*> keyNode;
    unordered_map<int, List*> freqList;
    int maxSize, minFreq, curSize;

    void updateFreq(Node* n) {
        List* old = freqList[n->cnt];
        old->removeNode(n);
        if (n->cnt == minFreq && old->size == 0) minFreq++;
        n->cnt++;
        if (!freqList.count(n->cnt)) freqList[n->cnt] = new List();
        freqList[n->cnt]->addFront(n);
    }

public:
    LFUCache(int capacity) {
        maxSize = capacity;
        minFreq = 0; 
        curSize = 0;
        
    }
    
    int get(int key) {
        auto it = keyNode.find(key);
        if (it == keyNode.end()) return -1;
        Node* n = it->second;
        updateFreq(n);
        return n->val;
        
    }
    
    void put(int key, int value) {
        if (maxSize == 0) return;

        auto it = keyNode.find(key);
        if (it != keyNode.end()) {          // existing: update value + freq
            Node* n = it->second;
            n->val = value;
            updateFreq(n);
            return;
        } 
        if (curSize == maxSize) {  
                    
            List* l = freqList[minFreq];
            Node* last = l->tail->prev;
            keyNode.erase(last->key);
            l->removeNode(last);
            delete last;
            curSize--;
        }
        curSize++;
        minFreq = 1;                        // new node always has freq 1
        Node* n = new Node(key, value);
        if (!freqList.count(1)) freqList[1] = new List();
        freqList[1]->addFront(n);
        keyNode[key] = n;
    }

};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */