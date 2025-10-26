#include <iostream>
#include <string>
using namespace std;
char *subSentence(char *input, int start, int end, int length)
{
    if (end < start || start < 0)
    {
        cout << "Invalid indeces\n";
        return nullptr;
    }
    // cout << "Hello\n";
    char *str = new char[100];
    int index = 0;
    for (start; start <= end; start++)
    {
        str[index] = input[start];
        index++;
        // cout << str << " ";
    }
    str[index] = '\0';
    return str;
}
int main()
{
    const int maxsize = 100;
    int length = 0;
    char str[maxsize];
    int start, end;
    cout << "Enter the sentence\n";
    cin.getline(str, maxsize);
    cout << str;
    cout << "\nEnter the start index\n";
    cin >> start;
    cout << "Enter the end index\n";
    cin >> end;
    int i = 0;
    while (str[i] != '\0')
    {
        length++;
        i++;
    }
    // cout << length << endl;

    char *result = subSentence(str, start, end, length);
    if (result != nullptr)
    {
        cout << "Extracted substring: " << result << endl;
        delete[] result;
    }
    else
    {
        cout << "Invalid indices or input string." << endl;
    }
    return 0;
}