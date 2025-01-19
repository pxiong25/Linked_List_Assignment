#include <iostream>
using namespace std;


struct Node {
    int row, col, value;
    Node* next;          // to the next node

    Node(int r, int c, int v) { // to initialize a node
        row = r;
        col = c;
        value = v;
        next = NULL;
    }
};


class SparseMatrix {
private:
    Node* head;

public:
    SparseMatrix() { //to initialize the list
        head = NULL;
    }

    void addNode(int row, int col, int value) {
        Node* newNode = new Node(row, col, value);
        if (head == NULL) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    // cout sparse matrix
    void display() {
        cout << "Row | Col | Value" << endl;
        cout << "-----------------" << endl;
        Node* temp = head;
        while (temp != NULL) { // Traverse the list
            cout << temp->row << "   | " << temp->col << "   | " << temp->value << endl;
            temp = temp->next; // Move to the next node
        }
    }
};

int main() {
    // original matrix
    int matrix[4][5] = {
        {0, 0, 3, 0, 4},
        {0, 0, 5, 7, 0},
        {0, 0, 0, 0, 0},
        {0, 2, 6, 0, 0}
    };

    // cout original matrix
    cout << "Original Matrix:" << endl;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 5; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }


    SparseMatrix sparseMatrix;


    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 5; j++) {
            if (matrix[i][j] != 0) {
                sparseMatrix.addNode(i, j, matrix[i][j]);
            }
        }
    }

    // cout the sparse matrix representation
    cout << "\nSparse Matrix Representation:" << endl;
    sparseMatrix.display();

    return 0;
}
