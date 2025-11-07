#include <iostream>
using namespace std;

struct Node {
    int key;
    int degree;
    Node* parent;
    Node* child;
    Node* sibling;

    Node(int k) : key(k), degree(0), parent(nullptr), child(nullptr), sibling(nullptr) {}
};

class BinomialHeap {
private:
    Node* head;

    // Merge two binomial heaps root lists into one sorted by degree
    Node* mergeRootLists(Node* h1, Node* h2) {
        if (!h1) return h2;
        if (!h2) return h1;

        Node* head = nullptr;
        Node* tail = nullptr;
        Node* a = h1;
        Node* b = h2;

        if (a->degree <= b->degree) {
            head = a;
            a = a->sibling;
        } else {
            head = b;
            b = b->sibling;
        }
        tail = head;

        while (a && b) {
            if (a->degree <= b->degree) {
                tail->sibling = a;
                a = a->sibling;
            } else {
                tail->sibling = b;
                b = b->sibling;
            }
            tail = tail->sibling;
        }

        tail->sibling = (a) ? a : b;
        return head;
    }

    // Link trees of same degree: make y a child of x
    void linkTrees(Node* y, Node* x) {
        y->parent = x;
        y->sibling = x->child;
        x->child = y;
        x->degree++;
    }

    // Union of two binomial heaps
    Node* unionHeaps(Node* h1, Node* h2) {
        Node* newHead = mergeRootLists(h1, h2);
        if (!newHead) return nullptr;

        Node* prev = nullptr;
        Node* curr = newHead;
        Node* next = curr->sibling;

        while (next != nullptr) {
            if ((curr->degree != next->degree) ||
                (next->sibling != nullptr && next->sibling->degree == curr->degree)) {
                prev = curr;
                curr = next;
            } else {
                if (curr->key <= next->key) {
                    curr->sibling = next->sibling;
                    linkTrees(next, curr);
                } else {
                    if (prev == nullptr) {
                        newHead = next;
                    } else {
                        prev->sibling = next;
                    }
                    linkTrees(curr, next);
                    curr = next;
                }
            }
            next = curr->sibling;
        }
        return newHead;
    }

    // Recursive function to find minimum root node
    Node* getMinRootNode() {
        Node* y = nullptr;
        Node* x = head;
        int minKey = INT32_MAX;
        while (x != nullptr) {
            if (x->key < minKey) {
                minKey = x->key;
                y = x;
            }
            x = x->sibling;
        }
        return y;
    }

    // Reverse linked list of root nodes
    Node* reverseList(Node* node) {
        Node* prev = nullptr;
        Node* current = node;
        Node* next;
        while (current != nullptr) {
            current->parent = nullptr;
            next = current->sibling;
            current->sibling = prev;
            prev = current;
            current = next;
        }
        return prev;
    }

    // Find node with given key (used in decreaseKey and deleteKey)
    Node* findNode(Node* root, int key) {
        if (!root) return nullptr;
        if (root->key == key) return root;

        Node* res = findNode(root->child, key);
        if (res) return res;
        return findNode(root->sibling, key);
    }

    // Bubble up the node to restore heap property after decrease key
    void bubbleUp(Node* node) {
        while (node->parent && node->key < node->parent->key) {
            swap(node->key, node->parent->key);
            node = node->parent;
        }
    }

public:
    BinomialHeap() : head(nullptr) {}

    // Insert a key by creating a new Binomial heap containing just this key and union it
    void insert(int key) {
        Node* newNode = new Node(key);
        head = unionHeaps(head, newNode);
    }

    // Get minimum key in the heap
    int getMin() {
        Node* minNode = getMinRootNode();
        if (!minNode) throw runtime_error("Heap is empty");
        return minNode->key;
    }

    // Extract minimum key node and return its key
    int extractMin() {
        if (!head) throw runtime_error("Heap is empty");

        // Find min node and its previous node
        Node* minNode = head;
        Node* minPrev = nullptr;
        Node* curr = head;
        Node* prev = nullptr;
        int minKey = minNode->key;

        while (curr) {
            if (curr->key < minKey) {
                minKey = curr->key;
                minNode = curr;
                minPrev = prev;
            }
            prev = curr;
            curr = curr->sibling;
        }

        // Remove minNode from root list
        if (!minPrev)
            head = minNode->sibling;
        else
            minPrev->sibling = minNode->sibling;

        // Reverse minNode's children and union with root list
        Node* childReversed = reverseList(minNode->child);
        head = unionHeaps(head, childReversed);

        int minValue = minNode->key;
        delete minNode;
        return minValue;
    }

    // Decrease key of a node from oldKey to newKey
    void decreaseKey(int oldKey, int newKey) {
        if (newKey > oldKey) {
            cout << "New key is greater than current key\n";
            return;
        }
        Node* node = findNode(head, oldKey);
        if (!node) {
            cout << "Key not found\n";
            return;
        }
        node->key = newKey;
        bubbleUp(node);
    }

    // Delete a node with given key from heap
    void deleteKey(int key) {
        decreaseKey(key, INT32_MIN);
        extractMin();
    }

    // Union with another binomial heap
    void unionWith(BinomialHeap& other) {
        head = unionHeaps(head, other.head);
        other.head = nullptr;
    }

    void display() {
        cout << "Root list (key(degree)):\n";
        Node* curr = head;
        while (curr) {
            cout << curr->key << "(" << curr->degree << ") -> ";
            curr = curr->sibling;
        }
        cout << "NULL\n";
    }
};

int main() {
    BinomialHeap bh1;
    bh1.insert(10);
    bh1.insert(20);
    bh1.insert(30);
    cout << "Binomial Heap after insertion:\n";
    bh1.display();

    bh1.decreaseKey(20, 5);
    cout << "After decreasing key 20 to 5:\n";
    bh1.display();

    cout << "Extract min: " << bh1.extractMin() << "\n";
    bh1.display();

    bh1.deleteKey(30);
    cout << "After deleting key 30:\n";
    bh1.display();

    BinomialHeap bh2;
    bh2.insert(7);
    bh2.insert(3);

    cout << "Second Heap:\n";
    bh2.display();

    bh1.unionWith(bh2);
    cout << "After union of two heaps:\n";
    bh1.display();

    return 0;
}
