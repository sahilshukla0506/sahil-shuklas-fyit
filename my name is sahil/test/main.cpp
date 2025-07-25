#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

int main() {
    int val;

    // Creating three nodes dynamically
    Node* x = new Node;
    Node* y = new Node;
    Node* z = new Node;

    cout << "Enter the 1st node: ";
    cin >> val;
    x->data = val;

    cout << "Enter the 2nd node: ";
    cin >> val;
    y->data = val;

    cout << "Enter the 3rd node: ";
    cin >> val;
    z->data = val;

    // Link the nodes
    x->next = y;
    y->next = z;
    z->next = nullptr;  // Mark the end of the list

    // Print the nodes
    cout << "1st node: " << x->data << endl;
    cout << "2nd node: " << x->next->data << endl;//y->data
    cout << "3rd node: " << x->next->next->data << endl;//z->data

    // Free memory
    delete x;
    delete y;
    delete z;

    return 0;
}
