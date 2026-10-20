#include <iostream>
using namespace std;

int main()
{
    int table[10];

    for(int i = 0; i < 10; i++)
    {
        table[i] = -1;
    }

    int numberOfStudents;
    cout << "Enter number of students: ";
    cin >> numberOfStudents;

    for(int i = 0; i < numberOfStudents; i++)
    {
        int studentID;
        cout << "Enter student ID: ";
        cin >> studentID;

        int firstSlot = studentID % 10;
        int jump = 7 - (studentID % 7);
        int count = 0;
        int slot = firstSlot;

        while(table[slot] != -1 && count < 10)
        {
            count++;
            slot = (firstSlot + count * jump) % 10;
        }

        if(count == 10)
        {
            cout << "Hash table is full!" << endl;
        }
        else
        {
            table[slot] = studentID;
        }
    }

    cout << "Final hash table:" << endl;

    for(int i = 0; i < 10; i++)
    {
        cout << i << " : " << table[i] << endl;
    }

    return 0;
}