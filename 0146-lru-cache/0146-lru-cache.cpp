class LRUCache {
private:
    struct Node {
        int key, val;
        Node *prev, *next;
        Node(int k, int v) : key(k), val(v), prev(nullptr), next(nullptr) {}
    };

    int cap;
    unordered_map<int, Node*> mp;
    Node *head, *tail;

    void removeNode(Node* n) {
        n->prev->next = n->next;
        n->next->prev = n->prev;
    }

    void addFront(Node* n) {
        n->next = head->next;
        n->prev = head;
        head->next->prev = n;
        head->next = n;
    }

public:
    LRUCache(int capacity) {
        cap = capacity;
        head = new Node(0,0);
        tail = new Node(0,0);
        head->next = tail; 
        tail->next = head; 
    }
    
    int get(int key) {
        auto it = mp.find(key);
        if(it== mp.end()) return -1;
        Node *n = it->second;
        removeNode(n);
        addFront(n); //mark most recent used
        return n->val;

    }
    
    void put(int key, int value) {
        auto it = mp.find(key);
        if(it!= mp.end()){
            Node*n = it->second;
            n->val = value;
            removeNode(n);
            addFront(n);
            return;
        }
        if ((int)mp.size() == cap) { // full: evict LRU (node just before tail)
            Node* lru = tail->prev;
            removeNode(lru);
            mp.erase(lru->key);
            delete lru;
        }
        Node* n = new Node(key, value);
        addFront(n);
        mp[key] = n;
    }
};



/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */