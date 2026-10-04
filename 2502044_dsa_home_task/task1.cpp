#include <iostream>
#include <string>
using namespace std;

struct Node
{
    int patientID;
    string patientName;
    int patientAge;
    Node* next;
};

Node* head = NULL;

void addPatient()
{
    Node* newNode = new Node;

    cout << "Enter Patient ID: ";
    cin >> newNode->patientID;

    cout << "Enter Patient Name: ";
    cin >> newNode->patientName;

    cout << "Enter Patient Age: ";
    cin >> newNode->patientAge;

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

    cout << "Patient added successfully.\n";
}
void addEmergencyPatient()
{
    Node* newNode = new Node;

    cout << "Enter Patient ID: ";
    cin >> newNode->patientID;

    cout << "Enter Patient Name: ";
    cin >> newNode->patientName;

    cout << "Enter Patient Age: ";
    cin >> newNode->patientAge;

    newNode->next = head;
    head = newNode;

    cout << "Emergency patient added at beginning.\n";
}

// Search patient
void searchPatient()
{
    int id;

    cout << "Enter Patient ID to search: ";
    cin >> id;

    Node* temp = head;

    while (temp != NULL)
    {
        if (temp->patientID == id)
        {
            cout << "\nPatient Found!\n";
            cout << "ID: " << temp->patientID << endl;
            cout << "Name: " << temp->patientName << endl;
            cout << "Age: " << temp->patientAge << endl;
            return;
        }

        temp = temp->next;
    }

    cout << "Patient does not exist.\n";
}

// Remove patient
void removePatient()
{
    int id;

    cout << "Enter Patient ID to remove: ";
    cin >> id;

    if (head == NULL)
    {
        cout << "Patient does not exist.\n";
        return;
    }

    if (head->patientID == id)
    {
        Node* temp = head;
        head = head->next;
        delete temp;

        cout << "Patient removed successfully.\n";
        return;
    }

    Node* temp = head;

    while (temp->next != NULL)
    {
        if (temp->next->patientID == id)
        {
            Node* deleteNode = temp->next;
            temp->next = temp->next->next;

            delete deleteNode;

            cout << "Patient removed successfully.\n";
            return;
        }

        temp = temp->next;
    }

    cout << "Patient does not exist.\n";
}

void displayPatients()
{
    if (head == NULL)
    {
        cout << "No waiting patients.\n";
        return;
    }

    Node* temp = head;

    cout << "\nWaiting Patients:\n";

    while (temp != NULL)
    {
        cout << "ID: " << temp->patientID
             << ", Name: " << temp->patientName
             << ", Age: " << temp->patientAge << endl;

        temp = temp->next;
    }
}
int main()
{
    int choice;
    do
    {
        cout << "    HOSPITAL EMERGENCY SYSTEM ";
        cout << "1. Add Patient at End\n";
        cout << "2. Add Emergency Patient at Beginning\n";
        cout << "3. Search Patient\n";
        cout << "4. Remove Patient\n";
        cout << "5. Display All Patients\n";
        cout << "6. Exit\n";

        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            addPatient();
            break;

        case 2:
            addEmergencyPatient();
            break;

        case 3:
            searchPatient();
            break;

        case 4:
            removePatient();
            break;

        case 5:
            displayPatients();
            break;

        case 6:
            cout << "Program ended.\n";
            break;

        default:
            cout << "Invalid choice.\n";
        }

    } while (choice != 6);

    return 0;
}