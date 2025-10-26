#include <iostream>
using namespace std;
class node
{
public:
    int data;
    string department;
    node *left, *right;

    node()
    {
        data = 0;
        left = NULL;
        right = NULL;
    }
    node(int data)
    {
        data = data;
        left = NULL;
        right = NULL;
    }
};
class BST
{
public:
    node *root;
    BST()
    {
        root = NULL;
    }
    void insert(int value)
    {
        node *newNode = new node(value);
        if (root == NULL)
        {
            root = newNode;
            return;
        }
        node *current = root;
        while (true)
        {
            if (value < current->data)
            {
                if (current->left == NULL)
                {
                    current->left = newNode;
                    break;
                }
                current = current->left;
            }
            else
            {
                if (current->right == NULL)
                {
                    current->right = newNode;
                    break;
                }
                current = current->right;
            }
        }
    }
    int path(node *root, int key1, int key2)
    {
        int count = 0;
        node *key1node = checkifNodeExist(root, key1);
        node *key2node = checkifNodeExist(root, key2);

        if (key1node == NULL && key2node == NULL)
        {
            if (key1 == key2)
            {
                return 0;
            }
            if (root->data == key1)
            {
                return count + 1;
            }
            if (root->data == key2)
            {
                return count + 1;
            }
            if (key1 < root->data)
            {

                count = path(root->left, key1, key2);
                return count;
            }
            if (key1 > root->data)
            {
                count = path(root->right, key1, key2);
                return count;
            }
            if (key2 < root->data)
            {
                count = path(root->left, key1, key2);
                return count;
            }
            if (key2 > root->data)
            {
                count = path(root->right, key1, key2);
                return count;
            }
            return count;
        }
        else
        {
            cout << "The given node is not present in the tree\n";
        }
    }
    node *checkifNodeExist(node *rootnode, int val)
    {
        if (rootnode == NULL || rootnode->data == val)
            return rootnode;

        if (val > rootnode->data)
            return checkifNodeExist(rootnode->right, val);
        else
            return checkifNodeExist(rootnode->left, val);
    }
    void inOrderTraversal(node *root1)
    {
        if (root1 != nullptr)
        {
            inOrderTraversal(root1->left);
            cout << root1->data << " ";
            inOrderTraversal(root1->right);
        }
    }
};
int main()
{
    BST tree;
    tree.insert(10);
    tree.insert(20);
    tree.insert(5);
    tree.insert(15);
    tree.insert(8);

    int count = tree.path(tree.root, 5, 15);
    cout << count;
    return 0;
}