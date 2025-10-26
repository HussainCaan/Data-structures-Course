#include <iostream>
using namespace std;
class node
{
public:
    string item;
    node *next;
    node *prev;

    node()
    {
        item = "N/A";
        next = NULL;
        prev = NULL;
    }
    node(string name)
    {
        item = name;
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
    void addItem(string Product)
    {
        n = new node(Product);
        if (top == NULL)
        {
            top = n;
            cout << "First Item added to the Queue\n";
        }
        else
        {
            top->next = n;
            n->prev = top;
            top = n;
            cout << Product << " added to the Queue\n";
        }
    }
    void removeItem()
    {
        if (top == NULL)
        {
            cout << "Order List is already Empty\n";
        }
        else
        {
            node *temp = top;
            top = top->prev;
            delete temp;
            cout << "Item removed From the list\n";
        }
    }
    void showCurrentItem()
    {
        if (top == NULL)
        {
            cout << "Order List is already Empty\n";
        }
        else
        {
            cout << "Current Item ordered is " << top->item;
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
    int choice;
    do
    {
        cout << "What do you want to do\n";
        cout << "1: For adding new orders\n";
        cout << "2: Remove current order\n";
        cout << "3: Display current order\n";
        cout << "4: Exiting Program\n";
        cin >> choice;
        if (choice == 1)
        {
            int option;
            cout << "what do you want to Select Order\n";
            cout << "1: For Chicken Karahi ---> Price Rs 1600\n";
            cout << "2: For Biryani ---> Price Rs 350\n";
            cout << "3: For Mutton karahi ---> Price Rs 1800\n";
            cout << "4: For Pasta ----> Price Rs 400";
            cout << "5: For Macrioni ---> Price Rs 500\n";
            cin >> option;
            if (option == 1)
            {
                q.addItem("Chicken Karahi");
            }
            else if (option == 2)
            {
                q.addItem("Biryani");
            }
            else if (option == 3)
            {
                q.addItem("Mutton Karahi");
            }
            else if (option == 4)
            {
                q.addItem("Pasta");
            }
            else if (option == 5)
            {
                q.addItem("Macroni");
            }
        }
        else if (choice == 2)
        {
            q.removeItem();
        }
        else if (choice == 3)
        {
            q.showCurrentItem();
        }
    } while (choice != 4);

    return 0;
}