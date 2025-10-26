#include <iostream>
using namespace std;
class node
{
public:
    int singleChar;
    node *next, *prev;
    node(int s)
    {
        singleChar = s;
        next = NULL;
        prev = NULL;
    }
};
class LinkL
{
public:
    node *top, *n1;
    int result;
    LinkL()
    {
        top = NULL;
    }
    void insert(string s)
    {
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] != '+' && s[i] != '-' && s[i] != '*' && s[i] != '/')
            {
                // cout << s[i];
                int val;
                val = s[i] - '0';
                n1 = new node(val);
                if (top == NULL)
                {
                    top = n1;
                }
                else
                {
                    top->next = n1;
                    n1->prev = top;
                    top = top->next;
                }
            }
            else
            {
                int pop2 = pop(); // Pop the second operand first
                int pop1 = pop(); // Pop the first operand second
                if (s[i] == '+')
                {
                    result = pop1 + pop2;
                }
                else if (s[i] == '-')
                {
                    result = pop2 - pop1;
                }
                else if (s[i] == '*')
                {
                    result = pop1 * pop2;
                }
                else if (s[i] == '/')
                {
                    result = pop1 / pop2;
                }
                n1 = new node(result);
                if (top == NULL)
                {
                    top = n1;
                }
                else
                {
                    top->next = n1;
                    n1->prev = top;
                    top = top->next;
                }
            }
        }
    }

    void display()
    {
        cout << "Result is " << result;
    }
    int pop()
    {
        node *temp;
        int val;
        temp = top;
        top = top->prev;
        temp->prev = NULL;
        val = temp->singleChar;
        delete temp;
        return val;
    }
};

int main()
{
    LinkL L;
    string exp = "345+-";
    L.insert(exp);
    L.display();
    return 0;
}