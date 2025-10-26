#include <iostream>
using namespace std;

int main()
{
    int arr[12] = {1, 2, 3, 4, 5, 6, 7, 8, 9,10,11,12};
    int *ptr = arr, *temp = new int; 
    int count1 = 0, count2 = 0, k = 4;
    
    for (int i = 0; i < 12; i++)
    {
        while (count1 < k - 2)
        {
            *temp = *(ptr + k - 1);
            *(ptr + k - 1) = *ptr;
            *ptr = *temp;
            count1++;
            ptr++;
        }
        ptr++;
        count2++;
        if (count2 == k)
        {
            count1 = 0;
            ptr += 2;
        }
    }
    delete temp;
    for (int i = 0; i < 10; i++)
    {
        cout << arr[i] << endl;
    }

    return 0;
}