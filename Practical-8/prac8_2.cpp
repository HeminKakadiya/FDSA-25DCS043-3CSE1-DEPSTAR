#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node* left;
    Node* right;

    Node(int value)
    {
        data = value;
        left = NULL;
        right = NULL;
    }
};

class BST
{
public:
    Node* insert(Node* root, int value)
    {
        if(root == NULL)
        {
            return new Node(value);
        }

        if(value < root->data)
        {
            root->left = insert(root->left, value);
        }
        else if(value > root->data)
        {
            root->right = insert(root->right, value);
        }

        return root;
    }

    void inorder(Node* root)
    {
        if(root == NULL)
        {
            return;
        }

        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
};

int main()
{
    BST tree;
    Node* root = NULL;

    int numberOfBooks;

    cout << "Enter number of book codes:" << endl;
    cin >> numberOfBooks;

    cout << "Enter book codes:" << endl;

    for(int i = 0; i < numberOfBooks; i++)
    {
        int bookCode;
        cin >> bookCode;

        root = tree.insert(root, bookCode);
    }

    cout << "Inorder sequence: ";
    tree.inorder(root);
    cout << endl;

    return 0;
}