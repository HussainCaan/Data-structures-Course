#include <iostream>
using namespace std;
#define capaccity 100
class arraylist
{
public:
    int *array, *temp, full = 0;
    arraylist(arraylist &list1)
    {
        if (isempty())
        {
            cout << "--------------------First list is empty------------\n";
        }
        else
        {
            for (int i = 0; i < list1.full; i++)
            {
                this->array[i] = list1.array[i];
            }
            cout << "Array Copied successfully!! This is the copied array\n";
        }
    }
    arraylist() {} // Default Constructor
    void createList(int size)
    {
        array = new int[size];
        temp = array;
    }

    bool isfull(int size)
    {
        if (full == size)
        {
            return true;
        }
        return false;
    }
    bool isempty()
    {
        if (full == 0)
        {
            return true;
        }
        return false;
    }
    void appendValue(int val, int size)
    {
        if (isfull(size))
        {
            cout << "-----------------------Array is already full---------------\n";
        }
        else
        {
            *temp = val;
            temp++;
            full++;
            cout << "---------------------Value appended succecfully----------------------\n";
        }
    }
    void Insert(int val, int pos, int size)
    {
        if (isfull(size))
        {
            cout << "-----------------------Array is already full---------------\n";
        }
        else
        {
            int *ptr = temp;
            int templength = full;
            while (templength != pos)
            {
                *(ptr + 1) = *ptr;
                templength--;
                ptr--;
            }
            *(ptr + 1) = *ptr;
            *ptr = val;
            full++;
            cout << "Value inserted at the specified positon\n";
        }
    }
    int getValue(int pos)
    {
        if (isempty())
        {
            cout << "--------------------Array is empty------------\n";
        }
        else if (pos < 1 || pos > full)
        {
            cout << "--------------------Enter a valid Position----------------\n";
        }
        else
        {
            return array[pos];
        }
    }
    void display()
    {
        if (isempty())
        {
            cout << "--------------------Array is empty------------\n";
        }
        else
        {
            cout << "Current array is\n";
            for (int i = 0; i < full; i++)
            {
                cout << "\t" << array[i] << endl;
            }
        }
    }
    void UpdateValue(int pos, int val)
    {
        if (isempty())
        {
            cout << "--------------------Array is empty------------\n";
        }
        else if (pos < 1 || pos > full)
        {
            cout << "--------------------Enter a valid Position----------------\n";
        }
        else
        {
            int *tempptr = array;
            for (int i = 0; i < full; i++)
            {
                if (i == pos)
                {
                    *tempptr = val;
                }
                tempptr++;
            }
            cout << "-----------------Value inserted at the specific Postion---------------\n";
        }
    }
    int DeterminePosition(int val)
    {
        if (isempty())
        {
            cout << "--------------------Array is empty------------\n";
        }
        else
        {
            int *tempptr = array;
            for (int i = 0; i < full; i++)
            {
                if (*tempptr == val)
                {
                    return i;
                }
                tempptr++;
            }
            return 0;
        }
    }
    void removeAtSpecificPosition(int pos)
    {
        if (isempty())
        {
            cout << "--------------------Array is empty------------\n";
        }
        else if (pos < 1 || pos > full)
        {
            cout << "--------------------Enter a valid Position----------------\n";
        }
        else
        {
            int *tempptr = array;
            for (int i = 0; i < full; i++)
            {
                if (i == pos - 1)
                {
                    for (int j = i; j < full; j++)
                    {
                        *tempptr = *(tempptr + 1);
                        tempptr++;
                    }
                    full--;
                    break;
                }
                tempptr++;
            }
        }
    }
    void bubbleSort()
    {
        if (isempty() || full == 1)
        {
            cout << "Array is already sorted or empty\n";
            return;
        }

        for (int i = 0; i < full - 1; ++i)
        {
            for (int j = 0; j < full - i - 1; ++j)
            {
                if (array[j] > array[j + 1])
                {
                    int temp = array[j];
                    array[j] = array[j + 1];
                    array[j + 1] = temp;
                }
            }
        }
        cout << "Array sorted in ascending order\n";
    }

    int getlength()
    {
        return full;
    }
    void clearingArray()
    {
        full = 0;
        cout << "----------------------Array is Cleared Successfully------------------\n";
    }
    ~arraylist()
    {
        cout << "------------------Class Memory Cleared------------------\n";
        delete[] array;
    }
};
int main()
{
    int option, size;
    arraylist *list1 = new arraylist;
    do
    {
        cout << "Selection an option\n";
        cout << "1:For creating new empty List\n";
        cout << "2:For Copying one list to another\n";
        cout << "3:For Clearing a list\n";
        cout << "4:For appending element\n";
        cout << "5:For inserting at specific position\n";
        cout << "6:For removing at specific position\n";
        cout << "7:For getting value of specific position\n";
        cout << "8:For updating value of specific position\n";
        cout << "9:For determining position of specific value\n";
        cout << "10:For length of the list\n";
        cout << "11:For printing all elements of the list\n";
        cout << "12:For sorting all elements of the list\n";
        cout << "13:For checking is full or not\n";
        cout << "14:For Exiting\n";
        cin >> option;

        if (option == 1)
        {
            cout << "Enter the size of array you want to create\n";
            cin >> size;
            list1->createList(size);
            cout << "Array intialized succecfully\n";
        }
        else if (option == 2)
        {
            arraylist *list2(list1);
            list2->display();
        }
        else if (option == 3)
        {
            list1->clearingArray();
        }
        else if (option == 4)
        {
            int value;
            cout << "Enter the value you want to append to the array\n";
            cin >> value;
            list1->appendValue(value, size);
        }
        else if (option == 5)
        {
            int value, position;
            cout << "Enter the value you want to insert\n";
            cin >> value;
            cout << "Enter the Position of the index you want to insert value\n";
            cin >> position;
            list1->Insert(value, position, size);
        }
        else if (option == 6)
        {
            int pos;
            cout << "Enter the Position you want to remove it's value\n";
            cin >> pos;
            list1->removeAtSpecificPosition(pos);
        }
        else if (option == 7)
        {
            int search, result;
            cout << "Enter the position of the value you want to get\n";
            cin >> search;
            result = list1->getValue(search);
            if (result != 0)
            {
                cout << "Value at Postion " << search << " is " << result << endl;
            }
        }
        else if (option == 8)
        {
            int update, val;
            cout << "Enter Positon you want to update it's value\n";
            cin >> update;
            cout << "Enter value you want to update\n";
            cin >> val;
            list1->UpdateValue(update, val);
        }
        else if (option == 9)
        {
            int value, result;
            cout << "Enter the value you want to find it's Position\n";
            cin >> value;
            result = list1->DeterminePosition(value);
            if (result != 0)
            {
                cout << "Value not Found in the array\n";
            }
            else
            {
                cout << "Position of the Value is " << result << endl;
            }
        }
        else if (option == 10)
        {
            int result;
            result = list1->getlength();
            cout << "Length of the current array is " << result << endl;
        }
        else if (option == 11)
        {
            list1->display();
        }
        else if (option == 12)
        {
            list1->bubbleSort();
            list1->display();
        }
        else if (option == 13)
        {
            if (list1->isfull(size))
            {
                cout << "----------------------Array is Full-------------------\n";
            }
            else
            {
                cout << "-----------------Array is not full yet-----------------\n";
            }
        }
        else if (option == 14)
        {
            delete list1;
            cout << "-----------------------Main Memory Cleared-----------------------\n";
            break;
        }
        else
        {
            cout << "------------------Invalid Option Selected------------------\n";
        }
    } while (option != 14);
    return 0;
}