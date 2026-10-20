#include<iostream>
using namespace std;

class Queue
{
    int *arr;
    int capacity;
    int front;
    int rear;
    int count;

public:

    Queue(int n)
    {
        capacity = n;
        arr = new int[capacity];
        front = 0;
        rear = -1;
        count = 0;
    }

    ~Queue()
    {
        delete[] arr;
    }

    void push(int token)
    {
        if(count == capacity)
        {
            cout << "Error: Queue is full" << endl;
            return;
        }

        rear = (rear + 1) % capacity;
        arr[rear] = token;
        count++;

        cout << "Front token: " << arr[front] << endl;
    }

    void pop()
    {
        if(count == 0)
        {
            cout << "Error: Queue is empty" << endl;
            return;
        }

        front = (front + 1) % capacity;
        count--;

        if(count == 0)
        {
            front = 0;
            rear = -1;
        }

        if(count > 0)
        {
            cout << "Front token: " << arr[front] << endl;
        }
        else
        {
            cout << "Queue is empty" << endl;
        }
    }
};

int main()
{
    int n;
    cout << "Enter queue capacity: ";
    cin >> n;

    Queue queue(n);

    int operations;
    cout << "Enter number of operations: ";
    cin >> operations;

    for(int i = 0; i < operations; i++)
    {
        int choice;

        cout << endl;
        cout << "1. Join" << endl;
        cout << "2. Serve" << endl;
        cout << "Enter operation: ";
        cin >> choice;

        if(choice == 1)
        {
            int token;
            cout << "Enter token number: ";
            cin >> token;

            queue.push(token);
        }
        else if(choice == 2)
        {
            queue.pop();
        }
        else
        {
            cout << "Error: Invalid operation" << endl;
        }
    }

    return 0;
}