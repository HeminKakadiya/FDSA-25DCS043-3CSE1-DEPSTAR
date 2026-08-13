#include <iostream>
#include <string>
#include <sstream>
using namespace std;

void rotateArray(int arr[], int n, int h)
{
    h %= n;  
    while (h--)
    {
        int first = arr[0];

        for (int i = 0; i < n - 1; i++)
            arr[i] = arr[i + 1];

        arr[n - 1] = first;
    }

    cout << "Final Display Order: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

void duplicateBooks(int books[], int n)
{
    bool found = false;
    cout << "Books borrowed more than once: ";
    for (int i = 0; i < n; i++)
    {
        int count = 1;

        for (int j = i + 1; j < n; j++)
        {
            if (books[i] == books[j])
                count++;
        }

        bool printed = false;
        for (int k = 0; k < i; k++)
        {
            if (books[k] == books[i])
            {
                printed = true;
                break;
            }
        }

        if (count > 1 && !printed)
        {
            cout << books[i] << " ";
            found = true;
        }
    }

    if (!found)
        cout << "None";

    cout << endl;
}

void longestWord(string sentence)
{
    stringstream ss(sentence);
    string word;
    string longest = "";

    while (ss >> word)
    {
        if (word.length() > longest.length())
            longest = word;
    }

    cout << "Longest Word : " << longest << endl;
    cout << "Length : " << longest.length() << endl;
}

int main()
{
    int arr[] = {10, 20, 30, 40, 50};
    int n = 5;
    int h;
    cout << "Enter number of rotations: ";
    cin >> h;
    rotateArray(arr, n, h);
    
    int books[] = {101, 102, 103, 101, 105, 102, 101};
    int size = 7;
    duplicateBooks(books, size);
    cin.ignore();

    string sentence;
    cout << "Enter a sentence: ";
    getline(cin, sentence);

    longestWord(sentence);

    return 0;
}