#include<iostream>
using namespace std;

class Node
{
public:
    int data;
    Node* next;

    Node(int d)
    {
        data = d;
        next = NULL;
    }
};

class Queue
{
public:
    Node* front;
    Node* rear;

    Queue()
    {
        front = NULL;
        rear = NULL;
    }

    void arrive(int d)
    {
        Node* n = new Node(d);

        if(front == NULL)
        {
            front = rear = n;
        }
        else
        {
            rear->next = n;
            rear = n;
        }

        cout << "Patient " << d << " arrived" << endl;
        print();
    }

    void attend()
    {
        if(front == NULL)
        {
            cout << "Attend: No patients waiting" << endl;
            print();
            return;
        }

        cout << "Attend: Patient " << front->data << " is attended" << endl;

        Node* temp = front;
        front = front->next;

        delete temp;

        if(front == NULL)
        {
            rear = NULL;
        }

        print();
    }

    void print()
    {
        if(front == NULL)
        {
            cout << "Front: Empty" << endl;
        }
        else
        {
            cout << "Front: " << front->data << endl;
        }
    }
};

int main()
{
    Queue q;

    q.arrive(101);
    q.arrive(102);
    q.arrive(103);
    q.arrive(104);
    q.arrive(105);

    q.attend();
    q.attend();

    q.arrive(106);
    q.arrive(107);

    q.attend();
    q.attend();
    q.attend();

    q.arrive(108);
    q.arrive(109);
    q.arrive(110);

    q.attend();
    q.attend();
    q.attend();
    q.attend();
    q.attend();

    q.attend();

    return 0;
}