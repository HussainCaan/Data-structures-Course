#include <iostream>
using namespace std;
class HashTable
{
private:
    int size;
    int capacity;
    int *table;

    int hash(int key)
    {
        return key % capacity;
    }

    void rehash()
    {
        int oldCapacity = capacity;
        capacity *= 2;
        int *oldTable = table;
        table = new int[capacity];
        for (int i = 0; i < capacity; ++i)
        {
            table[i] = -1; // Initialize new table with -1 (empty)
        }

        // Reinsert elements from old table into new table
        for (int i = 0; i < oldCapacity; ++i)
        {
            if (oldTable[i] != -1)
            {
                int newIndex = hash(oldTable[i]);
                while (table[newIndex] != -1)
                {
                    newIndex = (newIndex + 1) % capacity;
                }
                table[newIndex] = oldTable[i];
            }
        }

        delete[] oldTable;
    }

public:
    HashTable(int initialCapacity)
    {
        size = 0;
        capacity = initialCapacity;
        table = new int[capacity];
        for (int i = 0; i < capacity; ++i)
        {
            table[i] = -1; // Initialize table with -1 (empty)
        }
    }

    ~HashTable()
    {
        delete[] table;
    }

    void insert(int key, int minRange, int maxRange)
    {
        if (key < minRange || key > maxRange)
        {
            cout << "Key is outside the specified range. Insertion failed." << endl;
            return;
        }
        if ((double)size / capacity >= 0.7)
        {
            rehash();
        }
        int index = hash(key);
        while (table[index] != -1)
        {
            index = (index + 1) % capacity;
        }
        table[index] = key;
        size++;
    }

    bool search(int key)
    {
        int index = hash(key);
        int initialIndex = index;
        while (table[index] != -1)
        {
            if (table[index] == key)
            {
                return true;
            }
            index = (index + 1) % capacity;
            if (index == initialIndex)
            {
                break;
            }
        }
        return false;
    }
};

int main()
{
    HashTable ht(10);
    int choice, key, minRange, maxRange;
    cout << "Enter the minimum range: ";
    cin >> minRange;
    cout << "Enter the maximum range: ";
    cin >> maxRange;
    do
    {
        cout << "\n----------------------";
        cout << "\n1. Insert";
        cout << "\n2. Search";
        cout << "\n3. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter key to insert: ";
            cin >> key;
            ht.insert(key,minRange,maxRange);
            break;
        case 2:
            cout << "Enter key to search: ";
            cin >> key;
            cout << (ht.search(key) ? "Found" : "Not found") << endl;
            break;
        case 3:
            cout << "Exiting...";
            break;
        default:
            cout << "Invalid choice!";
        }
    } while (choice != 3);

    return 0;
}
