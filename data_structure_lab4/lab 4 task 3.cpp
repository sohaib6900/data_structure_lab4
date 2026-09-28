#include <iostream>
using namespace std;

class Node
{
public:
    string productID;
    Node* next;

    Node(string id)
    {
        productID = id;
        next = NULL;
    }
};

class ShoppingCart
{
private:
    Node* head;

public:
    ShoppingCart()
    {
        head = NULL;
    }

    void addProduct(string id)
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

    void displayCart()
    {
        Node* temp = head;

        while (temp != NULL)
        {
            cout << temp->productID;

            if (temp->next != NULL)
                cout << " -> ";

            temp = temp->next;
        }

        cout << endl;
    }

    void removeProduct(string id)
    {
        if (head == NULL)
        {
            cout << "Cart is empty." << endl;
            return;
        }

        // If product is the first node
        if (head->productID == id)
        {
            Node* temp = head;
            head = head->next;

            delete temp;
            return;
        }

        Node* current = head;

        while (current->next != NULL)
        {
            if (current->next->productID == id)
            {
                Node* temp = current->next;

                current->next = current->next->next;

                delete temp;
                return;
            }

            current = current->next;
        }

        cout << "Product Not Found" << endl;
    }
};

int main()
{
    ShoppingCart cart;

    cart.addProduct("P101");
    cart.addProduct("P205");
    cart.addProduct("P310");
    cart.addProduct("P415");

    cout << "Shopping Cart:" << endl;
    cart.displayCart();

    cout << "\nRemove Product: P310" << endl;

    cart.removeProduct("P310");

    cout << "\nUpdated Cart:" << endl;
    cart.displayCart();

    return 0;
}
