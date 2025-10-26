#include <iostream>

using namespace std;

class Node
{
public:
    char data;
    Node *next;

    Node(char d)
    {
        data = d;
        next = NULL;
    }
};

class Stack
{
private:
    Node *top;

public:
    Stack() : top(nullptr) {}

    void push(char c)
    {
        Node *newNode = new Node(c);
        newNode->next = top;
        top = newNode;
    }

    char pop()
    {
        if (isEmpty())
        {
            cout << "Stack is empty" << endl;
            return '\0';
        }
        char popped = top->data;
        Node *temp = top;
        top = top->next;
        delete temp;
        return popped;
    }

    char peek()
    {
        if (isEmpty())
        {
            cout << "Stack is empty" << endl;
            return '\0';
        }
        return top->data;
    }

    bool isEmpty()
    {
        return top == nullptr;
    }
};

bool isValid(string s)
{
    Stack st;

    for (char c : s)
    {
        if (c == '(' || c == '[' || c == '{')
        {
            st.push(c);
        }
        else
        {
            if (st.isEmpty())
            {
                return false;
            }

            char topChar = st.pop();
            if ((c == ')' && topChar != '(') ||
                (c == ']' && topChar != '[') ||
                (c == '}' && topChar != '{'))
            {
                return false;
            }
        }
    }

    return st.isEmpty();
}

int main()
{

    cout << "1 is For True and 0 is For False\n";
    cout << isValid("()") << endl;
    cout << isValid("()[]{}") << endl;
    cout << isValid("(]") << endl;
    cout << isValid("({ }]") << endl;

    return 0;
}
