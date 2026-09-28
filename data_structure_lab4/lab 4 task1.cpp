#include <iostream>
using namespace std;

class Node
{
public:
    int rollNo;
    Node* next;

    Node(int roll)
    {
        rollNo = roll;
        next = NULL;
    }
};

class StudentList
{
private:
    Node* head;

public:
    StudentList()
    {
        head = NULL;
    }

    void addStudent(int roll)
    {
        Node* newNode = new Node(roll);

        if (head == NULL)
        {
            head = newNode;
        }
        else
        {
            Node* temp = head;

            while (temp->next != NULL)
            {
                temp = temp->next;
            }

            temp->next = newNode;
        }
    }

    void displayStudents()
    {
        Node* temp = head;

        cout << "Registered Students:" << endl;

        while (temp != NULL)
        {
            cout << temp->rollNo;

            if (temp->next != NULL)
                cout << " -> ";

            temp = temp->next;
        }

        cout << endl;
    }

    void searchStudent(int roll)
    {
        Node* temp = head;

        while (temp != NULL)
        {
            if (temp->rollNo == roll)
            {
                cout << "Student Found" << endl;
                return;
            }

            temp = temp->next;
        }

        cout << "Student Not Found" << endl;
    }
};

int main()
{
    StudentList students;

    students.addStudent(101);
    students.addStudent(105);
    students.addStudent(108);
    students.addStudent(112);

    students.displayStudents();

    int roll;

    cout << "\nEnter Roll Number to Search: ";
    cin >> roll;

    students.searchStudent(roll);

    return 0;
}
