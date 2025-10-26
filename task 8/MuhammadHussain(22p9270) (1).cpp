#include <iostream>
using namespace std;
int multiply(int a, int b)
{
    if (a == 0 || b == 0)
    {
        return 0;
    }
    else if (b == 1)
    {
        return a;
    }
    else if (a == 1)
    {
        return b;
    }
    else if (b > 0)
    {
        return a + multiply(a, b - 1);
    }
    else
    {
        return -a + multiply(a, b + 1);
    }
}

int main()
{
    int a, b;
    cout << "Enter the value of a\n";
    cin >> a;
    cout << "Enter the value of b\n";
    cin >> b;
    cout<< "result is "<<multiply(a,b)<<endl;

    return 0;
}
