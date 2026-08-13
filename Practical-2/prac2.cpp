#include<iostream>
using namespace std;

void linearsearch_plate_iterative(int plates[], int n, int tplate)
{
    int i;
    bool found = false;
    for (i=0; i<n; i++)
    {
        if (plates[i] == tplate)
        {
            found = true;
            break;
        }
    }

    if (found==true)
    {
        cout << tplate <<" Location is found at : " << i+1 << endl;
    }
}

int linearsearch_plate_reccursive(int plates[], int n, int tplate, int i=0)
{
    if (i==n)
    {
        return -1;
    }

    if (plates[i] == tplate)
    {
        return i;
    }

    return linearsearch_plate_reccursive(plates, n, tplate, ++i);
}

void binarysearch_plate_iterative(int plates[], int n, int tplate)
{
    int left = 0;
    int right = n-1;

    while (left <= right)
    {
        int mid = (right + left) / 2;
        if (plates[mid] == tplate)
        {
            cout << tplate << " is found at location : " << mid+1;
            break;
        }

        else if (plates[mid] > tplate)
        {
            right = mid-1;
        }

        else
        {
            left = mid+1;
        }
    }
}

void binarysearch_plate_reccursive(int plates[], int tplate, int right, int left = 0)
{
    while (left <= right)
    {
        int mid = (right + left) / 2;
        if (plates[mid] == tplate)
        {
            cout << tplate << " is found at location : " << mid+1 << endl;
            break;
        }

        else if (plates[mid] > tplate)
        {
            right = mid-1;
            return binarysearch_plate_reccursive(plates, tplate, right, left);
        }

        else
        {
            left = mid+1;
            return binarysearch_plate_reccursive(plates, tplate, right, left);
        }
    }
}

int main()
{
    int n=5;
    int plates[5] = {100,200,300,400,500};
    int tplate = 200;
    cout << "linear search plate iterative" << endl;
    linearsearch_plate_iterative(plates, n, tplate);

    cout << "linear search plate reccursive" << endl;
    int place = linearsearch_plate_reccursive(plates, n, tplate);
    cout << tplate <<" Location is found at : " << place+1 << endl;
    cout<<endl;

    cout << "binary search plate iterative" << endl;
    binarysearch_plate_reccursive(plates, tplate, n-1);

    cout << "binary search plate reccursive" << endl;
    binarysearch_plate_reccursive(plates, tplate, n-1);

}