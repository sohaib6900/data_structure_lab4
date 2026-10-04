#include <iostream>
#include <string>
using namespace std;

struct Node
{
    string courseCode;
    string courseName;
    int creditHours;
    Node* next;
};

void addAtBeginning(Node*& head)
{
    Node* newNode = new Node;

    cout << "Enter Course Code: ";
    cin >> newNode->courseCode;

    cout << "Enter Course Name: ";
    cin >> newNode->courseName;

    cout << "Enter Credit Hours: ";
    cin >> newNode->creditHours;

    newNode->next = head;
    head = newNode;

    cout << "Course added at beginning.\n";
}

void addAtEnd(Node*& head)
{
    Node* newNode = new Node;

    cout << "Enter Course Code: ";
    cin >> newNode->courseCode;

    cout << "Enter Course Name: ";
    cin >> newNode->courseName;

    cout << "Enter Credit Hours: ";
    cin >> newNode->creditHours;

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

    cout << "Course added at end.\n";
}

void searchCourse(Node* head)
{
    string code;

    cout << "Enter Course Code to search: ";
    cin >> code;

    Node* temp = head;

    while (temp != NULL)
    {
        if (temp->courseCode == code)
        {
            cout << "\nCourse Found!\n";
            cout << "Course Code: " << temp->courseCode << endl;
            cout << "Course Name: " << temp->courseName << endl;
            cout << "Credit Hours: " << temp->creditHours << endl;
            return;
        }

        temp = temp->next;
    }

    cout << "Course not found.\n";
}

void deleteCourse(Node*& head)
{
    string code;

    cout << "Enter Course Code to delete: ";
    cin >> code;

    if (head == NULL)
    {
        cout << "Course not found.\n";
        return;
    }

    if (head->courseCode == code)
    {
        Node* temp = head;
        head = head->next;

        delete temp;

        cout << "Course deleted successfully.\n";
        return;
    }

    Node* temp = head;

    while (temp->next != NULL)
    {
        if (temp->next->courseCode == code)
        {
            Node* deleteNode = temp->next;

            temp->next = temp->next->next;

            delete deleteNode;

            cout << "Course deleted successfully.\n";
            return;
        }

        temp = temp->next;
    }

    cout << "Course not found.\n";
}

void displayCourses(Node* head)
{
    if (head == NULL)
    {
        cout << "Course list is empty.\n";
        return;
    }

    Node* temp = head;

    while (temp != NULL)
    {
        cout << temp->courseCode;

        if (temp->next != NULL)
        {
            cout << " -> ";
        }

        temp = temp->next;
    }

    cout << endl;
}

void countCourses(Node* head)
{
    int count = 0;

    Node* temp = head;

    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }

    cout << "Total Courses: " << count << endl;
}

void concatenate(Node*& first, Node* second)
{
    if (first == NULL)
    {
        first = second;
        return;
    }

    Node* temp = first;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = second;
}

int main()
{
    Node* morning = NULL;
    Node* evening = NULL;

    int choice;

    do
    {
        cout << "\n===== UNIVERSITY COURSE MANAGEMENT =====\n";
        cout << "1. Add Course at Beginning\n";
        cout << "2. Add Course at End\n";
        cout << "3. Search Course\n";
        cout << "4. Delete Course\n";
        cout << "5. Display All Courses\n";
        cout << "6. Count Total Courses\n";
        cout << "7. Concatenate Another Course List\n";
        cout << "8. Exit\n";

        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            addAtBeginning(morning);
            break;

        case 2:
            addAtEnd(morning);
            break;

        case 3:
            searchCourse(morning);
            break;

        case 4:
            deleteCourse(morning);
            break;

        case 5:
            cout << "\nMorning Courses:\n";
            displayCourses(morning);

            cout << "\nEvening Courses:\n";
            displayCourses(evening);
            break;

        case 6:
            cout << "\nMorning Courses: ";
            countCourses(morning);

            cout << "Evening Courses: ";
            countCourses(evening);
            break;

        case 7:
            cout << "\nConcatenating Evening Courses...\n";

            concatenate(morning, evening);

            cout << "Combined Course List:\n";
            displayCourses(morning);

            evening = NULL;

            break;

        case 8:
            cout << "Program ended.\n";
            break;

        default:
            cout << "Invalid choice.\n";
        }

    } while (choice != 8);
    return 0;
}