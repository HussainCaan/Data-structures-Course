#include <iostream>
#include <algorithm>

using namespace std;

struct Node
{
    int data;
    Node *left, *right;
    int height;
};

class AVLTree
{
public:
    Node *root;

    AVLTree()
    {
        root = nullptr;
    }

    int height(Node *node)
    {
        if (node == nullptr)
            return 0;
        return node->height;
    }

    int max(int a, int b)
    {
        return (a > b) ? a : b;
    }

    Node *rightRotate(Node *y)
    {
        Node *x = y->left;
        Node *T2 = x->right;

        // Perform rotation
        x->right = y;
        y->left = T2;

        // Update heights
        y->height = max(height(y->left), height(y->right)) + 1;
        x->height = max(height(x->left), height(x->right)) + 1;

        // Return new root
        return x;
    }

    Node *leftRotate(Node *x)
    {
        Node *y = x->right;
        Node *T2 = y->left;

        // Perform rotation
        y->left = x;
        x->right = T2;

        // Update heights
        x->height = max(height(x->left), height(x->right)) + 1;
        y->height = max(height(y->left), height(y->right)) + 1;

        // Return new root
        return y;
    }

    int getBalance(Node *node)
    {
        if (node == nullptr)
            return 0;
        return height(node->left) - height(node->right);
    }

    Node *insert(Node *root, int key)
    {
        Node *newNode = new Node;
        newNode->data = key;
        newNode->left = nullptr;
        newNode->right = nullptr;
        newNode->height = 1;

        if (root == nullptr)
        {
            return newNode;
        }

        Node *parent = nullptr;
        Node *current = root;

        // Find the parent of the new node
        while (current != nullptr)
        {
            parent = current;
            if (key < current->data)
                current = current->left;
            else if (key > current->data)
                current = current->right;
            else // Duplicate keys are not allowed in BST
                return root;
        }

        // Insert the new node at appropriate position
        if (key < parent->data)
            parent->left = newNode;
        else
            parent->right = newNode;

        // Update height of the parent node
        parent->height = 1 + max(height(parent->left), height(parent->right));

        // Perform rotations if necessary to balance the tree
        int balance = getBalance(parent);

        // Left Left Case
        if (balance > 1 && key < parent->left->data)
            return rightRotate(parent);

        // Right Right Case
        if (balance < -1 && key > parent->right->data)
            return leftRotate(parent);

        // Left Right Case
        if (balance > 1 && key > parent->left->data)
        {
            parent->left = leftRotate(parent->left);
            return rightRotate(parent);
        }

        // Right Left Case
        if (balance < -1 && key < parent->right->data)
        {
            parent->right = rightRotate(parent->right);
            return leftRotate(parent);
        }

        return root;
    }

    void display(Node *node)
    {
        if (node == nullptr)
            return;
        display(node->left);
        cout << node->data << " ";
        display(node->right);
    }
};

int main()
{
    AVLTree avl;
    int keys[] = {10, 20, 30, 40, 50, 25};
    int n = sizeof(keys) / sizeof(keys[0]);

    for (int i = 0; i < n; i++)
        avl.root = avl.insert(avl.root, keys[i]);

    cout << "Inorder traversal of the constructed AVL tree is: ";
    avl.display(avl.root);

    return 0;
}
