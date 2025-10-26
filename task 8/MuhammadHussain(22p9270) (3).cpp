#include <iostream>
using namespace std;
class nodes
{
public:
    int data;
    nodes *left, *right;

    nodes()
    {
        data = 0;
        left = NULL;
        right = NULL;
    }
    nodes(int d)
    {
        data = d;
        left = NULL;
        right = NULL;
    }
};
class BST
{
public:
    nodes *root, *n1;
    BST()
    {
        root = NULL;
    }
    bool isTreeEmpty()
    {
        if (root == NULL)
        {
            return true;
        }
        return false;
    }
    void insert(int d)
    {
        n1 = new nodes(d);
        if (root == NULL)
        {
            root = n1;
            cout << "Root node inserted\n";
        }
        else
        {
            nodes *temp = root;
            while (temp != NULL)
            {
                if (n1->data == temp->data)
                {
                    cout << "No Duplicates are allowed! Insert another value\n";
                    return;
                }
                else if ((n1->data < temp->data) && (temp->left == NULL))
                {
                    temp->left = n1;
                    cout << "Value inserted to the left\n";
                    break;
                }
                else if (n1->data < temp->data)
                {
                    temp = temp->left;
                }
                else if ((n1->data > temp->data) && (temp->right == NULL))
                {
                    temp->right = n1;
                    cout << "Value inserted the right\n";
                    break;
                }
                else if (n1->data > temp->data)
                {
                    temp = temp->right;
                }
            }
        }
    }

    nodes *findNode(nodes *node, int value)
    {
        if (node == NULL || node->data == value)
            return node;

        if (value < node->data)
            return findNode(node->left, value);
        else
            return findNode(node->right, value);
    }
};
int main()
{
    BST OBJ;
    OBJ.insert(5);
    OBJ.insert(3);
    OBJ.insert(7);
    OBJ.insert(2);
    OBJ.insert(4);
    OBJ.insert(6);
    OBJ.insert(8);

    int value;
    cout << "Enter the value to find in the BST: ";
    cin >> value;
    nodes *foundNode = OBJ.findNode(OBJ.root, value);
    if (foundNode != NULL)
        cout << "Node with value " << value << " found in the BST." << endl;
    else
        cout << "Node with value " << value << " not found in the BST." << endl;

    return 0;
}