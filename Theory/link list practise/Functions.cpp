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
            // cout<<"Current position"<<curr->pos<<endl;
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
    void insertInbetween(int pos, node *n)
    {
        if (pos < 1 || pos > length + 1)
        {
            cout << "Invalid Position\n";
        }
        else if (head == NULL)
        {
            cout << "list is empty you can't insert in between\n";
        }
        else
        {
            node *temp = head;
            int templength = length;
            while (temp->pos != pos - 1)
            {
                temp = temp->next;
                cout << temp->value << " " << temp->pos << endl;
                templength--;
            }
            node *secondtemp = temp->next;
            n->next = secondtemp;
            temp->next = n;
            
            cout << "Value inserted\n";
        }
    }
    void showList()
    {
        // cout << "List is : ";
        if (head == NULL)
        {
            cout << "No linked list connected\n";
        }
        else
        {
            node *ptr = head;
            cout << "List is\n";
            while (ptr != NULL)
            {
                cout << "( " << ptr->pos << "," << ptr->value << " ) --> ";
                cout << "Current Node position is " << curr->pos << endl;
                ptr = ptr->next;
            }
        }
    }
};
int main()
{
    list s;
    int key1, data1;
    for (int i = 0; i < 4; i++)
    {
        cout << "\nEnter the key\n";
        cin >> key1;
        cout << "Enter the data\n";
        cin >> data1;
        node *n1 = new node(key1, data1);
        s.append(n1);
        s.showList();
        if (i == 3)
        {
            int pos, value;
            cout << "Enter the position of node you want to insert\n";
            cin >> pos;
            cout << "Enter the value of node you want to insert\n";
            cin >> value;
            node *n1 = new node(pos, value);
            s.insertInbetween(pos, n1);
            s.showList();
        }
    }
    return 0;
}