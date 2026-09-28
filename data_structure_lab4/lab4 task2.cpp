#include <iostream>
using namespace std;

class Node
{
public:
    string patientID;
    Node* next;

    Node(string id)
    {
        patientID = id;
        next = NULL;
    }
};

class PatientQueue
{
private:
    Node* head;

public:
    PatientQueue()
    {
        head = NULL;
    }

    void addPatient(string id)
    {
        Node* newNode = new Node(id);

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

    void displayPatients()
    {
        Node* temp = head;

        while (temp != NULL)
        {
            cout << temp->patientID;

            if (temp->next != NULL)
                cout << " -> ";

            temp = temp->next;
        }

        cout << endl;
    }

    void removeFirstPatient()
    {
        if (head == NULL)
        {
            cout << "No patients in the queue." << endl;
            return;
        }

        Node* temp = head;

        cout << "Patient " << temp->patientID
             << " is being served." << endl;

        head = head->next;

        delete temp;
    }
};

int main()
{
    PatientQueue queue;

    queue.addPatient("P101");
    queue.addPatient("P102");
    queue.addPatient("P103");
    queue.addPatient("P104");

    cout << "Waiting Patients:" << endl;
    queue.displayPatients();

    cout << endl;

    queue.removeFirstPatient();

    cout << "\nUpdated Queue:" << endl;
    queue.displayPatients();

    return 0;
}
