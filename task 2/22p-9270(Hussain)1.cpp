#include <iostream>
using namespace std;
int calculateAverageStock(int *arr, int size);
int criticalProducts(int *arr, int averagestock, int size);
int BestSellingProduct(int *arr, int size);
int secondBestSellingProduct(int *arr, int size);
void sortingarray(int *arr, int size);
int main()
{
    int size, averagestock, lowProducts, TopSelled, SecondBestSelled;

    cout << "-------------------------------------------\n";
    cout << "  Welcome to Inventory Management system\n";
    cout << "-------------------------------------------\n";
    cout << "Enter the size of the inventory\n";
    cin >> size;
    // size = 5;
    int *inventory = new int[size];

    for (int i = 0; i < size; i++)
    {
        inventory[i] = rand() % 35;
    }
    averagestock = calculateAverageStock(inventory, size);
    cout << "Average stock in Inventory is " << averagestock << endl;
    lowProducts = criticalProducts(inventory, averagestock, size);
    cout << "Critical Products in the inventory are " << lowProducts << endl;
    TopSelled = BestSellingProduct(inventory, size);
    cout << "Top selled Product in the inventory are " << TopSelled << endl;
    SecondBestSelled = secondBestSellingProduct(inventory, size);
    cout << "Second best selled Product in the inventory are " << SecondBestSelled << endl;
    sortingarray(inventory, size);
    delete[] inventory;

    return 0;
}
int calculateAverageStock(int *arr, int size)
{
    int total = 0;
    int *ptr = arr;
    // cout << "in function\n";
    for (ptr; ptr < arr + size; ptr++)
    {
        cout << *ptr << endl;
        total = total + (*ptr);
    }
    int average = total / size;
    return average;
}
int criticalProducts(int *arr, int averagestock, int size)
{
    int count = 0;
    int *ptr = arr;

    for (ptr; ptr < arr + size; ptr++)
    {
        if (*ptr < averagestock)
        {
            count++;
        }
    }
    return count;
}
int BestSellingProduct(int *arr, int size)
{
    int *ptr = arr;
    int *topselled = arr;
    for (ptr; ptr < arr + size; ptr++)
    {
        if (*topselled > *ptr)
        {
            *topselled = *ptr;
            // cout<<*topselled<<endl;
        }
    }
    // cout<<*topselled<<endl;
    return *topselled;
}
int secondBestSellingProduct(int *arr, int size)
{
    int *ptr = arr;
    int *topselled = arr;
    int *secondbest = arr;
    for (ptr; ptr < arr + size; ptr++)
    {
        if (*topselled > *ptr)
        {
            *topselled = *ptr;
        }
    }

    for (ptr; ptr < arr + size; ptr++)
    {
        if (*secondbest > *ptr)
        {
            if (*ptr != *topselled)
            {
                *secondbest = *ptr;
            }
        }
    }

    return *secondbest;
}
void sortingarray(int *arr, int size)
{
    int *ptr = arr;
    int *ptr2 = arr + 1;
    for (ptr; ptr < arr + size; ptr++)
    {
        for (ptr2; ptr2 < arr + size; ptr2++)
        {
            if (*ptr > *ptr2)
            {
                int *temp = ptr;
                *ptr = *ptr2;
                *ptr2 = *temp;
            }
        }
    }
    cout << "Array after sorting\n";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << endl;
    }
}