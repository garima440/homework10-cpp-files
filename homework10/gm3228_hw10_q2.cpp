#include <iostream>
using namespace std;

int* findMissing(int arr[], int n, int& resArrSize)
{
    int * newArr = new int[n];
    int * temp = new int[n + 1];

    for (int i = 0; i <= n; i++)
    {
        temp[i] = 0;
    }

    for (int i = 0; i < n; i++)
    {
        temp[arr[i]]++;
    }
    
    int j = 0;
    for (int i = 0; i < n; i++)
    {
        if (temp[i] == 0)
        {
            newArr[j] = i;
            j++;
        }
    }
    resArrSize = j;
    return newArr;
}

// driver program to test findMissing function
int main()
{
    const int arrSize = 6;     // change array size here
    int resArrSize = 0;

    int arr[arrSize] = {1, 1, 2, 6, 1, 2};
    cout << "Original array of size " << arrSize << ": ";

    for (int i = 0; i < arrSize; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;

    int * missingInts = findMissing(arr, arrSize, resArrSize);
    cout << "Missing elements are: ";

    for (int i = 0; i < resArrSize; i++)
    {
        cout << missingInts[i] << " ";
    }
    cout << endl << "resArrSize is updated to: " << resArrSize;
    return 0;
}
