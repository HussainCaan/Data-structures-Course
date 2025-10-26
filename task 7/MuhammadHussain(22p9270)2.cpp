#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *next;
    node *prev;

    node(int d)
    {
        data = d;
        next = NULL;
        prev = NULL;
    }
};
class Queue
{
public:
    node *top, *n;
    Queue()
    {
        top = NULL;
    }

    void addItem(int d)
    {
        n = new node(d);
        if (top == NULL)
        {
            top = n;
            cout << "First Item added to the Queue\n";
        }
        else
        {
            node *temp = top;
            while (temp->prev != NULL)
            {
                temp = temp->prev;
            }
            temp->prev = n;
            n->next = temp;
            cout << d << " added to the Queue\n";
        }
    }
    void printQueue()
    {
        cout << "Output Queue: ";
        node *current = top;
        while (current != NULL)
        {
            cout << current->data << "->";
            current = current->prev;
        }
        cout << endl;
    }

    void duplicate()
    {
        node *current = top;
        node *current2 = top;
        while (current != NULL)
        {
            node *temp1 = top;
            if (current2 == top)
            {
                while (temp1->prev != NULL)
                {
                    temp1 = temp1->prev;
                }
                current2 = NULL;
                current = temp1;
            }
            int data = current->data;
            node *temp = current->prev;
            node *temp2 = current->next;
            for (int i = 1; i < data; i++)
            {
                node *newNode = new node(current->data);
                newNode->next = current;
                current->prev = newNode;
                newNode->prev = temp;
                // newNode->next = temp;
                // temp->prev = newNode;
                // if (temp != NULL)
                //     temp->prev = newNode;
                if (current == top)
                    top = newNode;
                current = newNode;
            }
            current = temp2;
        }
    }

    ~Queue()
    {
        delete n;
    }
};
int main()
{
    Queue q;
    q.addItem(1);
    q.addItem(2);
    q.addItem(3);
    q.printQueue();
    q.duplicate();
    q.printQueue();

    return 0;
}
