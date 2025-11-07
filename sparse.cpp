#include <iostream>
#include <vector>
using namespace std;

// Linked List Node for Sparse Matrix
struct Node {
    int row, col, value;
    Node* next;
    Node(int r, int c, int v) : row(r), col(c), value(v), next(nullptr) {}
};

// Sparse Matrix using Linked List
class SparseMatrixList {
public:
    Node* head;
    SparseMatrixList() : head(nullptr) {}

    void insert(int r, int c, int v) {
        Node* newNode = new Node(r, c, v);
        newNode->next = head;
        head = newNode;
    }

    void display(int rows, int cols) {
        // Reconstruct the full matrix from linked list
        vector<vector<int>> mat(rows, vector<int>(cols, 0));
        Node* curr = head;
        while (curr) {
            mat[curr->row][curr->col] = curr->value;
            curr = curr->next;
        }

        cout << "Matrix from Linked List representation:\n";
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j)
                cout << mat[i][j] << " ";
            cout << "\n";
        }
    }
};

// Sparse Matrix using Compressed Row Storage (CSR)
class SparseMatrixCSR {
public:
    vector<int> values;    // Non-zero elements
    vector<int> columns;   // Column indexes of elements
    vector<int> rowIndex;  // Index where each row starts in values and columns arrays
    int rows, cols;

    SparseMatrixCSR(int r, int c) : rows(r), cols(c) {
        rowIndex.resize(rows + 1, 0);
    }

    // Build CSR from dense matrix
    void buildFromMatrix(const vector<vector<int>>& mat) {
        for (int i = 0; i < rows; ++i) {
            rowIndex[i] = values.size();
            for (int j = 0; j < cols; ++j) {
                if (mat[i][j] != 0) {
                    values.push_back(mat[i][j]);
                    columns.push_back(j);
                }
            }
        }
        rowIndex[rows] = values.size();
    }

    void display() {
        cout << "Values: ";
        for (auto v : values) cout << v << " ";
        cout << "\nColumns: ";
        for (auto c : columns) cout << c << " ";
        cout << "\nRowIndex: ";
        for (auto r : rowIndex) cout << r << " ";
        cout << "\n";
    }

    // Reconstruct original matrix from CSR
    vector<vector<int>> reconstructMatrix() {
        vector<vector<int>> mat(rows, vector<int>(cols, 0));
        for (int i = 0; i < rows; ++i) {
            for (int j = rowIndex[i]; j < rowIndex[i+1]; ++j) {
                mat[i][columns[j]] = values[j];
            }
        }
        return mat;
    }
};

int main() {
    int rows = 4, cols = 5;
    vector<vector<int>> matrix = {
        {0, 0, 3, 0, 4},
        {0, 0, 5, 7, 0},
        {0, 0, 0, 0, 0},
        {0, 2, 6, 0, 0}
    };

    // Linked List Representation
    SparseMatrixList listRep;
    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j)
            if (matrix[i][j] != 0)
                listRep.insert(i, j, matrix[i][j]);

    listRep.display(rows, cols);

    // CSR Representation
    SparseMatrixCSR csrRep(rows, cols);
    csrRep.buildFromMatrix(matrix);
    csrRep.display();

    // Reconstruct and print matrix
    vector<vector<int>> reconstructed = csrRep.reconstructMatrix();
    cout << "Reconstructed matrix from CSR representation:\n";
    for (auto& row : reconstructed) {
        for (int val : row)
            cout << val << " ";
        cout << "\n";
    }

    return 0;
}
