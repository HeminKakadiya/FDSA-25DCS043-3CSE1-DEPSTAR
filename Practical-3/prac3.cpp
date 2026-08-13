#include <iostream>
using namespace std;

void display_arr(int arr[], int n)
{
    for (int i=0; i<n; i++)
    {
        cout<< arr[i] << " ";
    }
    cout<< endl;
}

void normalSort(int arr[], int n)
{
    for (int i=0; i<n-1; i++)
    {
        for (int j=i+1; j<n; j++)
        {
            if (arr[i]>arr[j])
            {
                int temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
            }
        }
    }
    display_arr(arr, n);
}

void selectionSort(int arr[], int n)
{
    for (int i=0; i<n-1; i++)
    {
        int minIndex = i;
        for (int j=i+1; j<n; j++)
        {
            if (arr[j]<arr[minIndex])
            {
                minIndex = j;
            }
        }

        int temp = arr[minIndex];
        arr[minIndex] = arr[i];
        arr[i] = temp;
    }
    display_arr(arr, n);
}


void insertionSort(int arr[], int n)
{
    for (int i=1; i<n; i++)
    {
        int temp = arr[i];
        int j = i-1;

        while (j>=0 && arr[j]>temp)
        {
            arr[j+1] = arr[j];
            j--;
        }

        arr[j+1] = temp;
    }

    display_arr(arr, n);
}

void bubbleSort(int arr[], int n)
{   
    for (int i=0; i<n-1; i++)
    {
        for (int j=0; j<n-1-i; j++)
        {
            if (arr[j]>arr[j+1])
            {
                int temp = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = temp; 
            }
        }
    }
    display_arr(arr, n);
}

int main()
{
    int arr[] = {5, 2, 4, 6, 1, 3};
    int bucket[] = {0, 1, 0, 1, 2, 2};
    int n = 6;

    cout<<"Normal Sort: "<<endl;
    normalSort(arr, n);

    cout<<"Selection Sort: "<<endl;
    selectionSort(arr, n);

    cout<<"Insertion Sort: "<<endl;
    insertionSort(arr, n);

    cout<<"Bubble Sort: "<<endl;
    bubbleSort(arr, n);

    cout<<"Sorted Bucket using Bubble Sort"<<endl;
    bubbleSort(bucket, n);

}
