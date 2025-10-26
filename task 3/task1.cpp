#include <iostream>
using namespace std;
class ArrayList
{
public:
    ArrayList *Start;
    ArrayList()
    {
        int *arr1 = new int[10];
    }
};
int main()
{
    string choice;

    do
    {
        int option;
        cout << "Selection and option\n";
        cout << "1:For creating new empty List\n";
        cout << "2:For Copying one list to another\n";
        cout << "3:For Clearing a list\n";
        cout << "4:For appending element\n";
        cout << "5:For inserting at specific position\n";
        cout << "6:For removing at specific position\n";
        cout << "7:For getting value of specific position\n";
        cout << "8:For updating value of specific position\n";
        cout << "9:For determining value of specific position\n";
        cout << "10:For length of the list\n";
        cout << "11:For printing all elements of the list\n";
        cout << "12:For reversing all elements of the list\n";
        cout << "13:For sorting all elements of the list\n";
        cout << "14:For checking is full or not\n";
        cout << "15:For checking is empty or not\n";
        cin >> option;

    } while (choice != "n" || choice != "N");

    return 0;
}