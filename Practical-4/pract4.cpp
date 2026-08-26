#include <iostream>
using namespace std;

struct Node
{
    int token;
    Node* next;
};

Node* front = NULL;

// Insert critical patient at front
void insertFront(int token)
{
    Node* newNode = new Node;
    newNode->token = token;
    newNode->next = front;
    front = newNode;
}

// Insert routine patient at end
void insertEnd(int token)
{
    Node* newNode = new Node;
    newNode->token = token;
    newNode->next = NULL;

    if (front == NULL)
    {
        front = newNode;
        return;
    }

    Node* temp = front;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = newNode;
}

// Insert patient at a specific position
void insertAtPosition(int token, int position)
{
    // Position 1 means front
    if (position <= 1)
    {
        insertFront(token);
        return;
    }

    Node* temp = front;

    // Move to node before required position
    for (int i = 1; i < position - 1 && temp != NULL; i++)
    {
        temp = temp->next;
    }

    // Position is greater than current length + 1
    if (temp == NULL)
    {
        cout << "Invalid position. Patient not inserted." << endl;
        return;
    }

    Node* newNode = new Node;
    newNode->token = token;

    newNode->next = temp->next;
    temp->next = newNode;
}

// Delete patient by token value
void deleteByValue(int token)
{
    if (front == NULL)
    {
        cout << "Queue is empty." << endl;
        return;
    }

    // If first node contains the token
    if (front->token == token)
    {
        Node* temp = front;
        front = front->next;
        delete temp;
        return;
    }

    Node* temp = front;

    while (temp->next != NULL && temp->next->token != token)
    {
        temp = temp->next;
    }

    // Token not found
    if (temp->next == NULL)
    {
        cout << "Token " << token << " not found." << endl;
        return;
    }

    Node* deleteNode = temp->next;
    temp->next = deleteNode->next;

    delete deleteNode;
}

// Forward traversal
void displayForward()
{
    Node* temp = front;

    cout << "Front to Back: ";

    while (temp != NULL)
    {
        cout << temp->token << " ";
        temp = temp->next;
    }

    cout << endl;
}

// Reverse printing without modifying the queue
void displayReverse(Node* temp)
{
    if (temp == NULL)
        return;

    // Go to the end first
    displayReverse(temp->next);

    // Print while returning from recursion
    cout << temp->token << " ";
}

// Display queue after every operation
void displayQueue()
{
    displayForward();
}

int main()
{
    // -------------------------------
    // PROBLEM 1
    // -------------------------------

    cout << "===== PROBLEM 1 =====" << endl;

    // Critical patient -> Front
    cout << "\nInsert 101 at front:" << endl;
    insertFront(101);
    displayQueue();

    // Routine patient -> End
    cout << "\nInsert 102 at end:" << endl;
    insertEnd(102);
    displayQueue();

    cout << "\nInsert 103 at end:" << endl;
    insertEnd(103);
    displayQueue();

    // Specific position
    cout << "\nInsert 104 at position 2:" << endl;
    insertAtPosition(104, 2);
    displayQueue();

    cout << "\nInsert 105 at position 3:" << endl;
    insertAtPosition(105, 3);
    displayQueue();

    // Invalid position
    cout << "\nTrying to insert 106 at position 10:" << endl;
    insertAtPosition(106, 10);
    displayQueue();


    // -------------------------------
    // PROBLEM 2
    // -------------------------------

    cout << "\n===== PROBLEM 2 =====" << endl;

    // Delete by value
    cout << "\nDeleting token 104:" << endl;
    deleteByValue(104);
    displayForward();

    // Forward traversal
    cout << "\nForward traversal:" << endl;
    displayForward();

    // Reverse printing
    cout << "\nReverse printing:" << endl;
    cout << "Back to Front: ";
    displayReverse(front);
    cout << endl;

    return 0;
}