#include <iostream>
using namespace std;
class node
{
public:
    int pos, value;
    node *next;
    node()
    {
        pos = 0;
        value = 0;
        next = NULL;
    }
    node(int pos, int value)
    {
        this->pos = pos;
        this->value = value;
        next = NULL;
    }
};
class list
{
public:
    node *head, *curr;
    int length = 0;
    list()
    {
        head = NULL;
        length = 0;
    }
    void append(node *n)
    {

        if (n->pos < 1 || n->pos > length + 1)
        {
            cout << "Invalid Position\n";
        }
        else if (head == NULL)
        {
            head = n;
            length++;
            curr = head;
            cout << "Node Appended as head node\n";
        }
        else
        {
            curr->next = n;
            curr = curr->next;
            length++;
            cout << "Node Appended\n";
        }
    }
    void reverse()
    {
        node *temp1 = NULL, *temp2 = NULL;
        while (head != NULL)
        {
            temp2 = head->next;
            head->next = temp1;
            temp1 = head;
            head = temp2;
        }
        head = curr;
    }
    void showList()
    {
        if (1==2)
        {
            cout << "No linked list connected\n";
        }
        else
        {
            node *ptr = head;
            cout << "List is\n";
            for (int i = 0; i < length; i++)
            {
                cout << "( " << ptr->pos << "," << ptr->value << " ) --> ";
                cout << "Current Node position is " <<curr->pos<< endl;
                ptr = ptr->next;
            }
            
        }
    }
};
int main()
{
    list s;
    int key1 = 0, data1 = 0;
    for (int i = 0; i < 6; i++)
    {
        // cout << "\nEnter the key\n";
        // cin >> key1;
        // cout << "Enter the data\n";
        // cin >> data1;
        key1++;
        data1 += 10;
        node *n1 = new node(key1, data1);
        s.append(n1);
        // s.showList();
    }
    s.reverse();
    cout<<"LL after reverse\n";
    s.showList();
    return 0;
}