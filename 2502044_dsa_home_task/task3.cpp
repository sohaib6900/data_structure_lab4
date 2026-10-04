#include <iostream>
#include <string>
using namespace std;
struct Node
{
    string orderID;
    string customerName;
    string foodItem;
    Node* next;
};

Node* head = NULL;

void addOrder()
{
    Node* newNode = new Node;

    cout << "Enter Order ID: ";
    cin >> newNode->orderID;

    cout << "Enter Customer Name: ";
    cin >> newNode->customerName;

    cout << "Enter Food Item: ";
    cin >> newNode->foodItem;

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

    cout << "Order added successfully.\n";
}

void addUrgentOrder()
{
    Node* newNode = new Node;

    cout << "Enter Urgent Order ID: ";
    cin >> newNode->orderID;

    cout << "Enter Customer Name: ";
    cin >> newNode->customerName;

    cout << "Enter Food Item: ";
    cin >> newNode->foodItem;

    newNode->next = head;
    head = newNode;

    cout << "Urgent order added at beginning.\n";
}

void displayOrders()
{
    if (head == NULL)
    {
        cout << "No pending orders.\n";
        return;
    }

    Node* temp = head;

    cout << "\n===== PENDING ORDERS =====\n";

    while (temp != NULL)
    {
        cout << "Order ID: " << temp->orderID
             << ", Customer: " << temp->customerName
             << ", Food: " << temp->foodItem << endl;

        temp = temp->next;
    }
}

void searchOrder()
{
    string id;

    cout << "Enter Order ID to search: ";
    cin >> id;

    Node* temp = head;

    while (temp != NULL)
    {
        if (temp->orderID == id)
        {
            cout << "\nOrder Found!\n";
            cout << "Order ID: " << temp->orderID << endl;
            cout << "Customer: " << temp->customerName << endl;
            cout << "Food Item: " << temp->foodItem << endl;
            return;
        }

        temp = temp->next;
    }

    cout << "Order not found.\n";
}

void removeOrder()
{
    string id;

    cout << "Enter Order ID to remove: ";
    cin >> id;

    if (head == NULL)
    {
        cout << "Order not found.\n";
        return;
    }

    if (head->orderID == id)
    {
        Node* temp = head;
        head = head->next;

        delete temp;

        cout << "Order delivered and removed.\n";
        return;
    }

    Node* temp = head;

    while (temp->next != NULL)
    {
        if (temp->next->orderID == id)
        {
            Node* deleteNode = temp->next;
            temp->next = temp->next->next;

            delete deleteNode;

            cout << "Order delivered and removed.\n";
            return;
        }

        temp = temp->next;
    }

    cout << "Order not found.\n";
}

int main()
{
    int choice;

    do
    {
        cout << "\n===== FOOD DELIVERY SYSTEM =====\n";
        cout << "1. Add New Order\n";
        cout << "2. Display Pending Orders\n";
        cout << "3. Search Order\n";
        cout << "4. Remove Delivered Order\n";
        cout << "5. Add Urgent Order\n";
        cout << "6. Display Updated Order List\n";
        cout << "7. Exit\n";

        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            addOrder();
            break;

        case 2:
            displayOrders();
            break;

        case 3:
            searchOrder();
            break;

        case 4:
            removeOrder();
            break;

        case 5:
            addUrgentOrder();
            break;

        case 6:
            displayOrders();
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