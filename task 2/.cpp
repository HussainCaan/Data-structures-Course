#include <iostream>
using namespace std;
int main()
{

    int *ptr = new (nothrow) int(100);

    if (!ptr)
    {
        cout << "No memory allocations";
    }
    else
    {
        cout << *ptr << endl;
        delete ptr;
    }
    return 0;
}