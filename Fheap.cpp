#include <iostream>
#include <cmath>
#include <unordered_map>
using namespace std;

struct Node {
    int key;
    int degree;
    bool mark;
    Node* parent;
    Node* child;
    Node* left;
    Node* right;

    Node(int k) : key(k), degree(0), mark(false), parent(nullptr), child(nullptr) {
        left = right = this;
    }
};

class FibonacciHeap {
private:
    Node* minNode;
    int n; // Number of nodes in the heap

    void link(Node* y, Node* x) {
        // Remove y from root list
        y->left->right = y->right;
        y->right->left = y->left;

        // Make y a child of x
        y->parent = x;
        if (x->child == nullptr) {
            x->child = y;
            y->right = y->left = y;
        } else {
            y->right = x->child;
            y->left = x->child->left;
            x->child->left->right = y;
            x->child->left = y;
        }
        x->degree++;
        y->mark = false;
    }

    void consolidate() {
        int D = static_cast<int>(log2(n)) + 1;
        Node* A[D];
        for (int i = 0; i < D; i++) A[i] = nullptr;

        Node* start = minNode;
        Node* w = minNode;
        if (!w) return;

        do {
            Node* x = w;
            int d = x->degree;
            Node* next = w->right;

            while (A[d]) {
                Node* y = A[d];
                if (x->key > y->key)
                    swap(x, y);
                link(y, x);
                A[d] = nullptr;
                d++;
            }
            A[d] = x;
            w = next;
        } while (w != start);

        minNode = nullptr;
        for (int i = 0; i < D; i++) {
            if (A[i]) {
                if (!minNode) {
                    minNode = A[i];
                    minNode->left = minNode->right = minNode;
                } else {
                    // Add A[i] to root list
                    A[i]->left = minNode;
                    A[i]->right = minNode->right;
                    minNode->right->left = A[i];
                    minNode->right = A[i];
                    if (A[i]->key < minNode->key)
                        minNode = A[i];
                }
            }
        }
    }

    void cut(Node* x, Node* y) {
        // Remove x from child list of y
        if (y->child == x) {
            if (x->right != x)
                y->child = x->right;
            else
                y->child = nullptr;
        }
        x->left->right = x->right;
        x->right->left = x->left;
        y->degree--;

        // Add x to root list
        x->left = minNode;
        x->right = minNode->right;
        minNode->right->left = x;
        minNode->right = x;
        x->parent = nullptr;
        x->mark = false;
    }

    void cascadingCut(Node* y) {
        Node* z = y->parent;
        if (z) {
            if (!y->mark)
                y->mark = true;
            else {
                cut(y, z);
                cascadingCut(z);
            }
        }
    }

public:
    FibonacciHeap() : minNode(nullptr), n(0) {}

    void insert(int key) {
        Node* node = new Node(key);
        if (!minNode) {
            minNode = node;
        } else {
            // Insert into root list
            node->left = minNode;
            node->right = minNode->right;
            minNode->right->left = node;
            minNode->right = node;
            if (key < minNode->key)
                minNode = node;
        }
        n++;
    }

    int getMin() {
        if (!minNode) throw runtime_error("Heap is empty");
        return minNode->key;
    }

    int extractMin() {
        if (!minNode) throw runtime_error("Heap is empty");

        Node* z = minNode;
        if (z) {
            // For each child of z, add to root list
            if (z->child) {
                Node* c = z->child;
                do {
                    Node* next = c->right;
                    // Add c to root list
                    c->left->right = c->right;
                    c->right->left = c->left;

                    c->left = minNode;
                    c->right = minNode->right;
                    minNode->right->left = c;
                    minNode->right = c;
                    c->parent = nullptr;

                    c = next;
                } while (c != z->child);
            }

            // Remove z from root list
            z->left->right = z->right;
            z->right->left = z->left;

            if (z == z->right)
                minNode = nullptr;
            else {
                minNode = z->right;
                consolidate();
            }
            n--;
        }
        int minKey = z->key;
        delete z;
        return minKey;
    }

    void decreaseKey(Node* x, int k) {
        if (!x) {
            cout << "Node not found\n";
            return;
        }
        if (k > x->key) {
            cout << "New key is greater than current key\n";
            return;
        }
        x->key = k;
        Node* y = x->parent;
        if (y && x->key < y->key) {
            cut(x, y);
            cascadingCut(y);
        }
        if (x->key < minNode->key)
            minNode = x;
    }

    // To find node with given key (inefficient)
    Node* findNode(Node* root, int key) {
        if (!root) return nullptr;
        Node* start = root;
        Node* x = root;
        do {
            if (x->key == key) return x;
            Node* res = findNode(x->child, key);
            if (res) return res;
            x = x->right;
        } while (x != start);
        return nullptr;
    }

    void decreaseKey(int oldKey, int newKey) {
        Node* node = findNode(minNode, oldKey);
        decreaseKey(node, newKey);
    }

    void displayRootList() {
        if (!minNode) {
            cout << "Heap is empty\n";
            return;
        }
        Node* curr = minNode;
        cout << "Root list keys: ";
        do {
            cout << curr->key << " ";
            curr = curr->right;
        } while (curr != minNode);
        cout << "\n";
    }
};

int main() {
    FibonacciHeap fh;

    fh.insert(10);
    fh.insert(3);
    fh.insert(7);
    fh.insert(17);
    fh.insert(24);

    cout << "Minimum key: " << fh.getMin() << "\n";
    fh.displayRootList();

    fh.decreaseKey(17, 2);
    cout << "After decreasing key 17 to 2:\n";
    cout << "Minimum key: " << fh.getMin() << "\n";
    fh.displayRootList();

    int minVal = fh.extractMin();
    cout << "Extracted minimum key: " << minVal << "\n";
    cout << "Minimum key after extraction: " << fh.getMin() << "\n";
    fh.displayRootList();

    return 0;
}
