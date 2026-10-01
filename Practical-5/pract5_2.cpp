#include <iostream>
using namespace std;

class SinglyCircular
{
    struct Node
    {
        int student;
        Node *next;
    };

    Node *head;

public:
    SinglyCircular()
    {
        head = NULL;
    }

    void join(int student, int position)
    {
        Node *newNode = new Node;
        newNode->student = student;

        if (head == NULL)
        {
            head = newNode;
            newNode->next = head;
            return;
        }

        if (position == 1)
        {
            Node *temp = head;

            while (temp->next != head)
            {
                temp = temp->next;
            }

            newNode->next = head;
            temp->next = newNode;
            head = newNode;
            return;
        }

        Node *temp = head;

        for (int i = 1; i < position - 1 && temp->next != head; i++)
        {
            temp = temp->next;
        }

        newNode->next = temp->next;
        temp->next = newNode;
    }

    void leave(int position)
    {
        if (head == NULL)
        {
            return;
        }

        if (head->next == head)
        {
            delete head;
            head = NULL;
            return;
        }

        if (position == 1)
        {
            Node *last = head;

            while (last->next != head)
            {
                last = last->next;
            }

            Node *deleteNode = head;
            head = head->next;
            last->next = head;

            delete deleteNode;
            return;
        }

        Node *temp = head;

        for (int i = 1; i < position - 1; i++)
        {
            temp = temp->next;
        }

        Node *deleteNode = temp->next;
        temp->next = deleteNode->next;

        delete deleteNode;
    }

    void display()
    {
        if (head == NULL)
        {
            cout << "Circle is empty" << endl;
            return;
        }

        Node *temp = head;

        do
        {
            cout << temp->student << " ";
            temp = temp->next;
        }
        while (temp != head);

        cout << endl;
    }
};


class DoublyCircular
{
    struct Node
    {
        int student;
        Node *next;
        Node *prev;
    };

    Node *head;

public:
    DoublyCircular()
    {
        head = NULL;
    }

    void join(int student, int position)
    {
        Node *newNode = new Node;
        newNode->student = student;

        if (head == NULL)
        {
            head = newNode;
            newNode->next = head;
            newNode->prev = head;
            return;
        }

        if (position == 1)
        {
            Node *last = head->prev;

            newNode->next = head;
            newNode->prev = last;

            last->next = newNode;
            head->prev = newNode;

            head = newNode;
            return;
        }

        Node *temp = head;

        for (int i = 1; i < position - 1 && temp->next != head; i++)
        {
            temp = temp->next;
        }

        newNode->next = temp->next;
        newNode->prev = temp;

        temp->next->prev = newNode;
        temp->next = newNode;
    }

    void leave(int position)
    {
        if (head == NULL)
        {
            return;
        }

        if (head->next == head)
        {
            delete head;
            head = NULL;
            return;
        }

        if (position == 1)
        {
            Node *deleteNode = head;
            Node *last = head->prev;

            head = head->next;

            last->next = head;
            head->prev = last;

            delete deleteNode;
            return;
        }

        Node *temp = head;

        for (int i = 1; i < position; i++)
        {
            temp = temp->next;
        }

        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;

        delete temp;
    }

    void display()
    {
        if (head == NULL)
        {
            cout << "Circle is empty" << endl;
            return;
        }

        Node *temp = head;

        do
        {
            cout << temp->student << " ";
            temp = temp->next;
        }
        while (temp != head);

        cout << endl;
    }
};


int main()
{
    SinglyCircular singly;
    DoublyCircular doubly;

    cout << "Singly Circular Linked List" << endl;

    singly.join(10, 1);
    singly.display();

    singly.join(20, 2);
    singly.display();

    singly.join(30, 3);
    singly.display();

    singly.join(40, 2);
    singly.display();

    singly.leave(2);
    singly.display();

    singly.leave(1);
    singly.display();


    cout << endl;

    cout << "Doubly Circular Linked List" << endl;

    doubly.join(10, 1);
    doubly.display();

    doubly.join(20, 2);
    doubly.display();

    doubly.join(30, 3);
    doubly.display();

    doubly.join(40, 2);
    doubly.display();

    doubly.leave(2);
    doubly.display();

    doubly.leave(1);
    doubly.display();

    return 0;
}