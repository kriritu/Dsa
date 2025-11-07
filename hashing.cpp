#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class UniversalHash {
private:
    int a, b, p, m;

public:
    UniversalHash(int table_size) {
        m = table_size;
        p = 10000019; // A large prime number (larger than max key)
        srand(time(0)); // Seed for randomness
        a = 1 + rand() % (p - 1); // a in [1, p-1]
        b = rand() % p;           // b in [0, p-1]
    }

    int hash(int key) const {
        return ((long long)a * key + b) % p % m;
    }
};

int main() {
    UniversalHash hashFunc(10); // Hash table size = 10

    // Example keys
    int keys[] = {15, 25, 35, 45, 55};
    int n = sizeof(keys) / sizeof(keys[0]);

    cout << "Universal Hashing outputs:\n";
    for (int i = 0; i < n; ++i) {
        cout << "Key: " << keys[i] << " -> Hash: " << hashFunc.hash(keys[i]) << "\n";
    }

    return 0;
}
