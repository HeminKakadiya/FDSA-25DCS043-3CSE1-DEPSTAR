#include <iostream>
using namespace std;

int main()
{
    int parking[10];

    for(int i = 0; i < 10; i++)
    {
        parking[i] = -1;
    }

    int numberOfVehicles;
    cout << "Enter number of vehicles: ";
    cin >> numberOfVehicles;

    for(int i = 0; i < numberOfVehicles; i++)
    {
        int registrationNumber;
        cout << "Enter registration number: ";
        cin >> registrationNumber;

        int slot = registrationNumber % 10;
        int count = 0;

        while(parking[slot] != -1 && count < 10)
        {
            slot = (slot + 1) % 10;
            count++;
        }

        if(count == 10)
        {
            cout << "Parking is full!" << endl;
        }
        else
        {
            parking[slot] = registrationNumber;
        }
    }

    cout << "Final parking slots:" << endl;

    for(int i = 0; i < 10; i++)
    {
        cout << i << " : " << parking[i] << endl;
    }

    return 0;
}