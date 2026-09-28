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

class Course
{
private:
    Node* head;

public:
    Course()
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

    void insertAtBeginning(int roll)
    {
        Node* newNode = new Node(roll);

        newNode->next = head;

        head = newNode;
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

    void displayStudents()
    {
        Node* temp = head;

        while (temp != NULL)
        {
            cout << temp->rollNo;

            if (temp->next != NULL)
                cout << " -> ";

            temp = temp->next;
        }

        cout << endl;
    }
};

int main()
{
    Course course;

    course.addStudent(22);
    course.addStudent(35);
    course.addStudent(41);
    course.addStudent(56);

    cout << "Initially:" << endl;
    course.displayStudents();

    cout << "\nA new student with Roll Number 18 joins the course." << endl;

    course.insertAtBeginning(18);

    cout << "\nAfter insertion:" << endl;
    course.displayStudents();

    return 0;
}
