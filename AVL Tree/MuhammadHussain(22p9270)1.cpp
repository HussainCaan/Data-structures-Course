#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *left, *right;
    node()
    {
        data = 0;
        left = NULL;
        right = NULL;
    }
    node(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};
class BST
{
public:
    node *root, *n1;
    BST()
    {
        root = NULL;
    }
    void insert(int data)
    {
        n1 = new node(data);
        if (root == NULL)
        {
            root = n1;
            return;
        }
        else
        {
            node *current = root;

            while (true)
            {
                if (data > current->data)
                {
                    if (current->right == NULL)
                    {
                        current->right = n1;
                        break;
                    }
                    current = current->right;
                }
                else
                {
                    if (current->left == NULL)
                    {
                        current->left = n1;
                        break;
                    }
                    current = current->left;
                }
            }
        }
    }
    int height(node *r)
    {
        if (r == NULL)
        {
            return 0;
        }
        int lheight = height(r->left);
        int rheight = height(r->right);
        if (lheight > rheight)
            return (lheight + 1);
        else
            return (rheight + 1);
    }
    bool AVLORNOT(node *ro)
    {
        int lh, rh;
        if (ro == NULL)
        {
            return 1;
        }
        lh = height(ro->left);
        rh = height(ro->right);
        int result = lh - rh;
        cout << "result is " << result<<endl;
        if (result == -1 || result == 0 || result == 1)
        {
            return true;
        }
        return false;
    }
    ~BST()
    {
        delete n1;
    }
};
int main()
{
    int option;
    BST tree;
    do
    {
        cout << "What do you want to do?\n";
        cout << "1: For inserting value in a BST\n";
        cout << "2: For checking a BST or not\n";
        cout << "3: For Ending the program\n";
        cin >> option;
        if (option == 1)
        {
            int val;
            cout << "Enter the value you want to insert\n";
            cin >> val;
            tree.insert(val);
        }
        else if (option == 2)
        {
            if (tree.root == NULL)
            {
                cout << "Tree is not created yet\n";
            }
            else
            {
                if (tree.AVLORNOT(tree.root))
                {
                    cout << "AVL";
                    break;
                }
                else
                {
                    cout << "NOT AVL";
                    break;
                }
            }
        }

    } while (option != 3);

    return 0;
}