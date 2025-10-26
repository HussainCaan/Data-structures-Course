#include <iostream>
using namespace std;
class nodes
{
public:
    int data, key;
    nodes *next, *prev;
    nodes()
    {

        key = 0;
        data = 0;
        next = NULL;
        prev = NULL;
    }
    void productfunc(int k, int d)
    {
        data = d;
        key = k;
        next = NULL;
        prev = NULL;
    }
};
class List
{
public:
    nodes *head;
    nodes *n1;
    List()
    {
        head = NULL;
    }
    List(nodes *n)
    {
        head = n;
    }
    nodes *checkproduct(int k)
    {
        nodes *temp = NULL;
        nodes *ptr = head;
        do
        {
            if (ptr->key == k)
            {
                temp = ptr;
            }
            ptr = ptr->next;
        } while (ptr != head);
        return temp;
    }
    void AddProduct(int data, int key)
    {
        n1 = new nodes;
        n1->productfunc(data, key);
        if (head == NULL)
        {
            head = n1;
            cout << "node added as first Product\n";
        }
        else
        {
            if (checkproduct(n1->key) != NULL)
            {
                cout << "node with same id already exist\n";
            }
            else
            {
                nodes *temp = head;
                while (temp->next != NULL)
                {
                    temp = temp->next;
                }
                temp->next = n1;
                n1->prev = temp;
            }
        }
    }
    void splitnodes()
    {
        nodes *current = head;
        nodes *evenHead, *oddHead;
        while (current != NULL)
        {
            if (current->data % 2 == 0)
            {
                if (evenHead == NULL)
                {
                    evenHead = new nodes;
                    evenHead->productfunc(current->key, current->data);
                }
                else
                {
                    nodes *temp = evenHead;
                    while (temp->next != NULL)
                    {
                        temp = temp->next;
                    }
                    temp->next = new nodes;
                    temp->next->prev = temp;
                    temp->next->productfunc(current->key, current->data);
                }
            }
            else
            {
                if (oddHead == NULL)
                {
                    oddHead = new nodes;
                    oddHead->productfunc(current->key, current->data);
                }
                else
                {
                    nodes *temp = oddHead;
                    while (temp->next != NULL)
                    {
                        temp = temp->next;
                    }
                    temp->next = new nodes;
                    temp->next->prev = temp;
                    temp->next->productfunc(current->key, current->data);
                }
            }

            current = current->next;
        }

        cout << "Even List: ";
        displayList(evenHead);

        cout << "Odd List: ";
        displayList(oddHead);
    }
    void displayList(nodes *head)
    {
        while (head != NULL)
        {
            cout << "( " << head->key << ", " << head->data << " ) --> ";
            head = head->next;
        }
        cout << "NULL\n";
    }
    void showProducts()
    {
        if (head == NULL)
        {
            cout << "No linked list connected\n";
        }
        else
        {
            nodes *ptr = head;
            cout << "List is\n";
            while (ptr != NULL)
            {
                cout << "( " << ptr->key << ", " << ptr->data << " --> ";
                ptr = ptr->next;
            }
        }
    }
    ~List()
    {
        delete n1;
    }
};
int main()
{
    int k = 0, d = 0;
    List l;

    for (int i = 0; i < 10; i++)
    {
        k++;
        d += 10;
        l.AddProduct(k, d);
    }
    cout << "List before splitting\n";
    l.showProducts();

    l.splitnodes();
    return 0;
}