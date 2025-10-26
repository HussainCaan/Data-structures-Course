#include <iostream>
using namespace std;
class node
{
public:
    int data, key;
    node *next;
    node()
    {
        data = 0;
        key = 0;
        next = NULL;
    }
    node(int d, int k)
    {
        data = d;
        key = k;
        next = NULL;
    }
};
class CircularLL
{
public:
    node *head, *curr = NULL;
    CircularLL()
    {
        head = NULL;
    }
    CircularLL(node *n)
    {
        head = n;
        curr = head;
    }
    void insert(int data, int pos)
    {
        node *n1 = new node(data, pos);
        if (pos == 1 && head == NULL)
        {
            head = n1;
            head->next = head;
            curr = head->next;
        }
        else if (pos == 1 && head != NULL)
        {
            n1->next = head;
            head = n1;
            curr->next = head;
        }
        else
        {
            node *temp = head;
            while (temp->key != pos)
            {
                temp = temp->next;
            }
            
        }
    }
};
int main()
{

    return 0;
}