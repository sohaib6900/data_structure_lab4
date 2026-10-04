#include <iostream>
#include <string>
using namespace std;
struct Node
{
    int rollNumber;
    string studentName;
    string attendance;
    Node* next;
};
Node* head = NULL;

void addStudent()
{
    Node* newNode = new Node;

    cout << "Enter Roll Number: ";
    cin >> newNode->rollNumber;

    cout << "Enter Student Name: ";
    cin >> newNode->studentName;

    cout << "Enter Attendance (Present/Absent): ";
    cin >> newNode->attendance;

    newNode->next = NULL;

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

    cout << "Student added successfully.\n";
}

void searchStudent()
{
    int roll;

    cout << "Enter Roll Number to search: ";
    cin >> roll;

    Node* temp = head;

    while (temp != NULL)
    {
        if (temp->rollNumber == roll)
        {
            cout << "\nStudent Found!\n";
            cout << "Roll Number: " << temp->rollNumber << endl;
            cout << "Name: " << temp->studentName << endl;
            cout << "Attendance: " << temp->attendance << endl;
            return;
        }

        temp = temp->next;
    }

    cout << "Student not found.\n";
}

void deleteStudent()
{
    int roll;

    cout << "Enter Roll Number to delete: ";
    cin >> roll;

    if (head == NULL)
    {
        cout << "Student not found.\n";
        return;
    }

    if (head->rollNumber == roll)
    {
        Node* temp = head;
        head = head->next;

        delete temp;

        cout << "Student deleted successfully.\n";
        return;
    }

    Node* temp = head;

    while (temp->next != NULL)
    {
        if (temp->next->rollNumber == roll)
        {
            Node* deleteNode = temp->next;
            temp->next = temp->next->next;

            delete deleteNode;

            cout << "Student deleted successfully.\n";
            return;
        }

        temp = temp->next;
    }

    cout << "Student not found.\n";
}

void displayStudents()
{
    if (head == NULL)
    {
        cout << "Attendance list is empty.\n";
        return;
    }

    Node* temp = head;

    cout << "\n===== ATTENDANCE LIST =====\n";

    while (temp != NULL)
    {
        cout << "Roll Number: " << temp->rollNumber
             << ", Name: " << temp->studentName
             << ", Attendance: " << temp->attendance << endl;

        temp = temp->next;
    }
}

void countPresent()
{
    int count = 0;

    Node* temp = head;

    while (temp != NULL)
    {
        if (temp->attendance == "Present" ||
            temp->attendance == "present")
        {
            count++;
        }

        temp = temp->next;
    }

    cout << "Total Students Present: " << count << endl;
}

int main()
{
    int choice;

    do
    {
        cout << "\n===== STUDENT ATTENDANCE SYSTEM =====\n";
        cout << "1. Add Student\n";
        cout << "2. Search Student\n";
        cout << "3. Delete Student\n";
        cout << "4. Display All Students\n";
        cout << "5. Count Students Present\n";
        cout << "6. Display Final Attendance List\n";
        cout << "7. Exit\n";

        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            addStudent();
            break;

        case 2:
            searchStudent();
            break;

        case 3:
            deleteStudent();
            break;

        case 4:
            displayStudents();
            break;

        case 5:
            countPresent();
            break;

        case 6:
            displayStudents();
            break;

        case 7:
            cout << "Program ended.\n";
            break;

        default:
            cout << "Invalid choice.\n";
        }

    } while (choice != 7);

    return 0;
}