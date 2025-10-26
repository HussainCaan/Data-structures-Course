#include <iostream>
using namespace std;
class node
{
public:
    char sent;
    node *next;
    node()
    {
        sent = ' ';
        next = NULL;
    }
    node(char ch)
    {
        sent = ch;
        next = NULL;
    }
};
class str
{
public:
    node *head, *curr;
    str()
    {
        head = NULL;
        curr = NULL;
    }
    str(node *n)
    {
        head = n;
        curr = n;
    }
    void insert(char character)
    {
        node *n = new node(character);
        node *temp;
        if (head == NULL)
        {
            head = temp;
            curr = temp;
            cout << "Appended\n";
        }
        else
        {
            temp = head;
            while (temp->next != NULL)
            {
                temp = temp->next;
                curr = curr->next;
            }
            temp->next = n;
            curr->next = n;
        }
    }
    void headvowel()
    {
        insert('-');
        insert('w');
        insert('a');
        insert('y');
    }
    void novowel()
    {
        insert('-');
        insert('w');
        insert('a');
        insert('y');
    }
    void headnotvowel()
    {
        insert('-');
        node *temp = head;
        while (temp->sent != 'A' || temp->sent != 'E' || temp->sent != 'I' || 'O' || temp->sent != 'U' || temp->sent != 'Y' || temp->sent != 'a' || temp->sent != 'e' || temp->sent != 'i' || 'o' || temp->sent != 'u' || temp->sent != 'y')
        {
            head = head->next;
            curr->next = temp;
            temp = head;
        }
        if (temp->sent != 'A' || temp->sent != 'E' || temp->sent != 'I' || 'O' || temp->sent != 'U' || temp->sent != 'Y' || temp->sent != 'a' || temp->sent != 'e' || temp->sent != 'i' || 'o' || temp->sent != 'u' || temp->sent != 'y')
        {
            cout << "No vowels\n";
            novowel();
        }
        else
        {
            insert('a');
            insert('y');
        }
    }
    void display()
    {
        node *ptr = head;
        while (ptr->next != NULL)
        {
            cout << ptr->sent;
            ptr = ptr->next;
        }
    }
};
int main()
{
    char input[50];
    cout << "Enter the word\n";
    cin >> input;
    str s;
    int i = 0;
    while (input[i] != '\0')
    {
        s.insert(input[i]);
        i++;
    }
    if (input[0] == 'A' || input[0] == 'E' || input[0] == 'I' || 'O' || input[0] == 'U' || input[0] == 'Y' || input[0] == 'a' || input[0] == 'e' || input[0] == 'i' || 'o' || input[0] == 'u' || input[0] == 'y')
    {
        s.headvowel();
    }
    else if (input[0] != 'A' || input[0] != 'E' || input[0] != 'I' || 'O' || input[0] != 'U' || input[0] != 'Y' || input[0] != 'a' || input[0] != 'e' || input[0] != 'i' || 'o' || input[0] != 'u' || input[0] != 'y')
    {
        s.headnotvowel();
    }
    s.display();

    return 0;
}