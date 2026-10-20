#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node* next;

    Node(int value)
    {
        data = value;
        next = NULL;
    }
};

int main()
{
    Node* shelves[10];

    for(int i = 0; i < 10; i++)
    {
        shelves[i] = NULL;
    }

    int numberOfBooks;
    cout << "Enter number of books: ";
    cin >> numberOfBooks;

    for(int i = 0; i < numberOfBooks; i++)
    {
        int bookCode;
        cout << "Enter book code: ";
        cin >> bookCode;

        int shelf = bookCode % 10;
        Node* newNode = new Node(bookCode);

        if(shelves[shelf] == NULL)
        {
            shelves[shelf] = newNode;
        }
        else
        {
            Node* current = shelves[shelf];

            while(current->next != NULL)
            {
                current = current->next;
            }

            current->next = newNode;
        }
    }

    cout << "Final shelf contents:" << endl;

    for(int i = 0; i < 10; i++)
    {
        cout << i << " : ";

        Node* current = shelves[i];

        while(current != NULL)
        {
            cout << current->data << " -> ";
            current = current->next;
        }

        cout << "NULL" << endl;
    }

    return 0;
}