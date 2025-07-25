#include <iostream>
using namespace std;

// Define a node structure for the BST
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

// BST class
class BST {
private:
    Node* root;

    // Helper for insertion
    Node* insert(Node* node, int val) {
        if (node == nullptr)
            return new Node(val);

        if (val < node->data)
            node->left = insert(node->left, val);
        else if (val > node->data)
            node->right = insert(node->right, val);

        return node;
    }

    // Helper for inorder traversal
    void inorder(Node* node) {
        if (node == nullptr) return;

        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }

    // Helper for search
    bool search(Node* node, int key) {
        if (node == nullptr)
            return false;
        if (node->data == key)
            return true;
        if (key < node->data)
            return search(node->left, key);
        else
            return search(node->right, key);
    }

public:
    BST() {
        root = nullptr;
    }

    void insert(int val) {
        root = insert(root, val);
    }

    void inorder() {
        cout << "Inorder Traversal: ";
        inorder(root);
        cout << endl;
    }

    void search(int key) {
        if (search(root, key))
            cout << key << " found in the BST.\n";
        else
            cout << key << " not found in the BST.\n";
    }
};

int main() {
    BST tree;

    // Insert elements
    tree.insert(50);
    tree.insert(30);
    tree.insert(70);
    tree.insert(20);
    tree.insert(40);
    tree.insert(60);
    tree.insert(80);

    // Display inorder traversal (should be sorted)
    tree.inorder();

    // Search for some elements
    tree.search(60);  // should be found
    tree.search(25);  // should not be found

    return 0;
}
