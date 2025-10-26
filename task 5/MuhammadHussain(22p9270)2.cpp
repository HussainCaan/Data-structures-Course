#include <iostream>
using namespace std;
class Products
{
public:
    int quantity, price, key;
    string name;
    Products *next, *prev;
    Products()
    {
        quantity = 0;
        key = 0;
        price = 0;
        name = "N-A";
        next = NULL;
        prev = NULL;
    }
    void productfunc(string d, int k, int q, int p)
    {
        name = d;
        key = k;
        price = p;
        quantity = q;
        next = NULL;
        prev = NULL;
    }
};
class List
{
public:
    Products *head;
    Products *n1;
    List()
    {
        head = NULL;
    }
    List(Products *n)
    {
        head = n;
    }
    Products *checkproduct(int k)
    {
        Products *temp = NULL;
        Products *ptr = head;
        while (ptr != NULL)
        {
            if (ptr->key == k)
            {
                temp = ptr;
            }
            ptr = ptr->next;
        }
        return temp;
    }
    void AddProduct(string name, int id, int quantity, int price)
    {
        n1 = new Products;
        n1->productfunc(name, id, quantity, price);
        if (head == NULL)
        {
            head = n1;
            cout << "Product added as first Product\n";
        }
        else
        {
            if (checkproduct(n1->key) != NULL)
            {
                cout << "Product with same ID already exists\n";
            }
            else
            {
                Products *temp = head;
                while (temp->next != NULL)
                {
                    temp = temp->next;
                }
                temp->next = n1;
                n1->prev = temp;
                cout << "Product Added\n";
            }
        }
    }
    void remove(int id)
    {
        if (head == NULL)
        {
            cout << "Link list is empty\n";
        }
        else
        {
            Products *temp1 = head, *temp2 = NULL;

            while (temp1 != NULL)
            {
                if (temp1->key == id)
                {
                    if (temp2 != NULL)
                    {
                        temp2->next = temp1->next;
                        if (temp1->next != NULL)
                            temp1->next->prev = temp2;
                    }
                    else
                    {
                        head = temp1->next;
                        if (head != NULL)
                            head->prev = NULL;
                    }

                    temp1->next = NULL;
                    temp1->prev = NULL;
                    delete temp1;

                    cout << "Product removed successfully\n";
                    return; // Exit the function after successful removal
                }
                else
                {
                    temp2 = temp1;
                    temp1 = temp1->next;
                }
            }
            cout << "Id not Found in the link List\n";
        }
    }
    void update(int id)
    {
        Products *temp1 = head;
        while (temp1 != NULL)
        {
            if (temp1->key == id)
            {
                int choice;
                cout << "What do you want to update in this product\n";
                cout << "1:Name\n";
                cout << "2:ID\n";
                cout << "3:Price\n";
                cout << "4:Quantity\n";
                cin >> choice;
                if (choice == 1)
                {
                    cout << "Enter the new name of the Product\n";
                    cin >> temp1->name;
                    cout << "Name Updated\n";
                    break;
                }
                else if (choice == 2)
                {
                    cout << "Enter the new Id of the Product\n";
                    cin >> temp1->key;
                    cout << "Key Updated\n";
                    break;
                }
                else if (choice == 3)
                {
                    cout << "Enter the new Price of the Product\n";
                    cin >> temp1->price;
                    cout << "Price Updated\n";
                    break;
                }
                else if (choice == 4)
                {
                    cout << "Enter the new quantity of the Product\n";
                    cin >> temp1->quantity;
                    cout << "Quantity Updated\n";
                    break;
                }
            }
            else
            {
                temp1 = temp1->next;
            }
        }
        cout << "Id not found is the link list\n";
    }
    void search(int id)
    {
        Products *temp1 = head;
        while (temp1 != NULL)
        {
            if (temp1->key == id)
            {
                cout << "Name of the Product is " << temp1->name << endl;
                cout << "ID of the Product is " << temp1->key << endl;
                cout << "price of the Product is " << temp1->price << endl;
                cout << "quantity of the Product is " << temp1->quantity << endl;
                break;
            }
            else
            {
                temp1 = temp1->next;
            }
        }
        cout << "ID not found\n";
    }
    void showProducts()
    {
        if (head == NULL)
        {
            cout << "No linked list connected\n";
        }
        else
        {
            Products *ptr = head;
            cout << "List is\n";
            while (ptr != NULL)
            {
                cout << "( " << ptr->key << ", " << ptr->name << ", " << ptr->quantity << ", " << ptr->price << " ) --> ";
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

    int option;
    List l;
    do
    {
        cout << "Choice one of the following\n";
        cout << "1:For Adding new product\n";
        cout << "2:For removing  product\n";
        cout << "3:For displaying  product\n";
        cout << "4:For Updating  product\n";
        cout << "5:For finding  product\n";
        cout << "6:For quitting \n";
        cin >> option;
        if (option == 1)
        {
            string name;
            int Id, price, quantity;
            cout << "Enter the name of the product\n";
            cin >> name;
            cout << "Enter the Id of the product\n";
            cin >> Id;
            cout << "Enter the Quantity of the product\n";
            cin >> quantity;
            cout << "Enter the Price of the Product\n";
            cin >> price;
            l.AddProduct(name, Id, quantity, price);
        }
        else if (option == 3)
        {
            l.showProducts();
        }
        else if (option == 2)
        {
            int id;
            cout << "Enter the id of the product you want to remove\n";
            cin >> id;
            l.remove(id);
        }
        else if (option == 4)
        {
            int id;
            cout << "Enter the ID of the Product you want to update it's value\n";
            cin >> id;
            l.update(id);
        }
        else if (option == 5)
        {
            int id;
            cout << "Enter the ID of the Product you want to search it's value\n";
            cin >> id;
            l.search(id);
        }

    } while (option != 6);

    return 0;
}