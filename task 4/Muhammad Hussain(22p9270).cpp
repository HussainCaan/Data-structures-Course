#include <iostream>
using namespace std;
class Students
{
    int StudentID;
    double CGPA;
    string name;
    Students *next;

public:
    Students()
    {
        StudentID = 0;
        CGPA = 0;
        name = "N-A";
        next = NULL;
    }
    Students(int Studentid, double cgpa, string Name)
    {
        this->StudentID = Studentid;
        this->CGPA = cgpa;
        this->name = Name;
        next = NULL;
    }
    int getStudentID()
    {
        return StudentID;
    }
    Students *getNext()
    {
        return next;
    }
    void nextfunc(Students *n)
    {
        next = n;
    }
    double getcgpa()
    {
        return CGPA;
    }
    string getname()
    {
        return name;
    }
};
class list
{
    Students *head, *curr;

public:
    list()
    {
        head = NULL;
    }
    Students *traversing(int k)
    {
        Students *ptr = head;
        Students *temp = NULL;
        while (ptr != NULL)
        {
            if (ptr->getStudentID() == k)
            {
                temp = ptr;
            }
            ptr = ptr->getNext();
        }
        // cout << temp << endl;
        return temp;
    }
    void appendNode(Students *n)
    {
        if (traversing(n->getStudentID()) != NULL)
        {
            cout << "Students already exists\n";
        }
        else
        {
            if (head == NULL)
            {
                head = n;
                curr = head;
                cout << "Students appended as head Students\n";
            }
            else
            {
                Students *ptr = head;
                while (ptr->getNext() != NULL)
                {
                    ptr = ptr->getNext();
                    curr = curr->getNext();
                }
                ptr->nextfunc(n);
                cout << "Student Added to database\n";
            }
        }
    }
    void removeStudent(int id)
    {
        Students *temp = head, *temp2 = NULL, *temp3 = NULL;
        while (temp != NULL)
        {
            if (temp->getNext()->getStudentID() == id)
            {
                temp2 = temp;
            }
            if (temp->getStudentID() == id)
            {
                temp3 = temp;
            }
            else if (temp2 != NULL && temp3 != NULL)
            {
                temp2->nextfunc(temp3->getNext());
                delete temp3;
                cout<<"Student Removed\n";
                break;
            }
            temp = temp->getNext();
        }
    }
    void StudentSearch(int id)
    {
        Students *temp = head;
        int count = 0;
        while (temp != NULL)
        {
            if (temp->getStudentID() == id)
            {
                cout << "Name of the student is " << temp->getname() << endl;
                cout << "CGPA of the student is " << temp->getcgpa() << endl;
                cout << "id of the student is " << temp->getStudentID() << endl;
                count++;
            }
            temp = temp->getNext();
        }
        if (count == 0)
        {
            cout << "Id not matched to anyone in database\n";
        }
    }
    double CgpaCalculator()
    {
        double total, average;
        int count = 0;
        Students *temp = head;
        while (temp != NULL)
        {
            total += temp->getcgpa();
            count++;
            temp = temp->getNext();
        }
        average = total / count;
        return average;
    }
    void showList()
    {
        // cout << "List is : ";
        if (head == NULL)
        {
            cout << "No linked list connected\n";
        }
        else
        {
            Students *ptr = head;
            cout << "List is\n";
            while (ptr != NULL)
            {
                cout << "(Student ID is " << ptr->getStudentID() << ", Student CGPA is " << ptr->getcgpa() << ", Student Name is " << ptr->getname() << " ) --> \n";
                ptr = ptr->getNext();
            }
        }
    }
};
int main()
{
    list s;
    int id;
    double cpga;
    string name;
    int option;
    do
    {
        cout << "Select an Option\n";
        cout << "1:For Adding a student\n";
        cout << "2:For removing a student\n";
        cout << "3:For searching a student\n";
        cout << "4:For displaying all students\n";
        cout << "5:Calculate average CGPA\n";
        cout << "6:For exiting\n";
        cin >> option;

        if (option == 1)
        {
            cout << "\nEnter the student id\n";
            cin >> id;
            cout << "Enter the name of student\n";
            cin >> name;
            cout << "Enter the CGPA of the student\n";
            cin >> cpga;
            Students *n1 = new Students(id, cpga, name);
            s.appendNode(n1);
        }
        else if (option == 2)
        {
            int searchid;
            cout << "Enter the ID of the student you want to remove\n";
            cin >> searchid;
            s.removeStudent(searchid);
        }
        else if (option == 3)
        {
            int searchid;
            cout << "Enter the ID of the student you want to search\n";
            cin >> searchid;
            s.StudentSearch(searchid);
        }
        else if (option == 4)
        {
            s.showList();
        }
        else if (option == 5)
        {
            double average;
            average = s.CgpaCalculator();
            cout << "Average CGPA of students is " << average << endl;
        }

    } while (option != 6);

    return 0;
}