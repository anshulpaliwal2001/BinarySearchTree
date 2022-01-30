#include <iostream>

using namespace std;

struct Node {
    int data;
    Node *left, *right;

    Node(int data) {
        this->data = data;
        right = left = nullptr;
    }

    Node(int data, Node *left, Node *right) : data(data), left(left), right(right) {}
};

class BST {

public:
    Node *root;

    BST()
    {
        root= nullptr;
    }

    void printBST(Node *root, int val)
    {
        if(root==nullptr)
            return;
        printBST(root->left,val);
        if(root->data==val)
            cout<<root->data<<"* ";
        else
            cout<<root->data<<" ";
        printBST(root->right,val);
    }
    Node* insert(Node *root, int val)
    {
        if(root== nullptr)
            return new Node(val);
        if(root->data>val)
            root->left=insert(root->left,val);
        else if(root->data < val)
            root->right=insert(root->right,val);
        return root;
    }





};



int main()
{
    BST b1;
    b1.root=b1.insert(b1.root,5);
    b1.insert(b1.root,6);
    b1.insert(b1.root,4);
    b1.insert(b1.root,2);
    b1.insert(b1.root,1);
    b1.printBST(b1.root,b1.root->data);

    return 0;
}

