#include <iostream>

using namespace std;

struct Node {
    int data;
    Node *left, *right;

    Node(int val) {
        data = val;
        right = left = nullptr;
    }
};

class BST {

public:

    Node *root;

    BST();

    Node *insertBST(Node *node, int val);

    void printInOrder(Node *node, int val);

    static Node *searchBST(Node *root, int val);

    static void keyExist(Node *node, int val);

    void printPreOrder(Node *node, int val);

    void printPostOrder(Node *node, int val);

};

void BST::printInOrder(Node *node, int val) {
    if (node == nullptr) {
        return;
    }
    printInOrder(node->left, val);      //left
    if (node->data == val)              //data
        cout << node->data << "* ";
    else
        cout << node->data << " ";
    printInOrder(node->right, val);     //right
}

Node *BST::insertBST(Node *node, int val) {
    if (node == nullptr) {
        return new Node(val);
    }
    if (val < node->data) {
        node->left = insertBST(node->left, val);
    } else if (val > node->data) {
        node->right = insertBST(node->right, val);
    }
    return node;
}

BST::BST() {
    root = nullptr;
}

Node *BST::searchBST(Node *root, int val) {
    if (root == nullptr)
        return nullptr;

    if (root->data == val)
        return root;

    if (root->data > val)
        return searchBST(root->left, val);
    return searchBST(root->right, val);
}

void BST::keyExist(Node *node, int val) {
    if (searchBST(node, val) == nullptr)
        cout << "Value " << val << " doesn't exist in BST";
    else
        cout << "Value " << val << " does exist in BST";
}

void BST::printPreOrder(Node *node, int val) {
    if (node == nullptr) {
        return;
    }
    if (node->data == val)              //data
        cout << node->data << "* ";
    else
        cout << node->data << " ";
    printInOrder(node->left, val);      //left

    printInOrder(node->right, val);     //right
}

void BST::printPostOrder(Node *node, int val) {
    if (node == nullptr) {
        return;
    }

    printInOrder(node->left, val);      //left

    printInOrder(node->right, val);     //right

    if (node->data == val)              //data
        cout << node->data << "* ";
    else
        cout << node->data << " ";
}


int main() {
    BST b1;                                     // Creating BST Object

    b1.root = b1.insertBST(b1.root, 5);         // Initialising first node

    b1.insertBST(b1.root, 1);                   // Add more
    b1.insertBST(b1.root, 3);
    b1.insertBST(b1.root, 4);
    b1.insertBST(b1.root, 2);
    b1.insertBST(b1.root, 7);
    //              5
    //           1    7
    //             3
    //            2 4
    b1.printPreOrder(b1.root, b1.root->data);    // print in order
    b1.keyExist(b1.root, 69);


    return 0;
}

