#include <iostream>
#include <queue>
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

class Tree
{
public:
    Node* buildTree()
    {
        int value;
        cin >> value;

        if(value == -1)
        {
            return NULL;
        }

        Node* root = new Node(value);
        root->left = buildTree();
        root->right = buildTree();

        return root;
    }

    void preorder(Node* root)
    {
        if(root == NULL)
        {
            return;
        }

        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
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

    void postorder(Node* root)
    {
        if(root == NULL)
        {
            return;
        }

        postorder(root->left);
        postorder(root->right);
        cout << root->data << " ";
    }

    void levelOrder(Node* root)
    {
        if(root == NULL)
        {
            return;
        }

        queue<Node*> nodes;
        nodes.push(root);

        while(!nodes.empty())
        {
            Node* current = nodes.front();
            nodes.pop();

            cout << current->data << " ";

            if(current->left != NULL)
            {
                nodes.push(current->left);
            }

            if(current->right != NULL)
            {
                nodes.push(current->right);
            }
        }

        cout << endl;
    }
};

int main()
{
    Tree tree;

    cout << "Enter tree nodes in preorder (-1 for NULL):" << endl;
    Node* root = tree.buildTree();

    cout << "Preorder: ";
    tree.preorder(root);
    cout << endl;

    cout << "Inorder: ";
    tree.inorder(root);
    cout << endl;

    cout << "Postorder: ";
    tree.postorder(root);
    cout << endl;

    cout << "Level Order: ";
    tree.levelOrder(root);

    return 0;
}