#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = nullptr;
    }
};

// Linked List class
class LinkedList {
private:
    Node* head;

public:
    LinkedList() {
        head = nullptr;
    }

    // Insert at end
    void insertAtEnd(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    // Display the list
    void display() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }

    // Delete node at given position (1-based index)
    void deleteAtPosition(int position) {
        if (head == nullptr || position <= 0) {
            cout << "Invalid position or empty list!\n";
            return;
        }

        // Delete head
        if (position == 1) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        // Traverse to the node before the one to delete
        Node* current = head;
        for (int i = 1; current != nullptr && i < position - 1; i++) {
            current = current->next;
        }

        // If position is invalid
        if (current == nullptr || current->next == nullptr) {
            cout << "Position out of bounds!\n";
            return;
        }

        // Delete the node
        Node* temp = current->next;
        current->next = temp->next;
        delete temp;
    }

    // Destructor to free memory
    ~LinkedList() {
        Node* current = head;
        while (current != nullptr) {
            Node* nextNode = current->next;
            delete current;
            current = nextNode;
        }
    }
};

// Main function to test
int main() {
    LinkedList list;

    list.insertAtEnd(10);
    list.insertAtEnd(20);
    list.insertAtEnd(30);
    list.insertAtEnd(40);

    cout << "Original List: ";
    list.display();

    list.deleteAtPosition(2);  // Deletes 20
    cout << "After deleting position 2: ";
    list.display();

    list.deleteAtPosition(1);  // Deletes 10
    cout << "After deleting position 1: ";
    list.display();

    list.deleteAtPosition(5);  // Invalid position
    return 0;
}
