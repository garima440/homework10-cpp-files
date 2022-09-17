#include <iostream>
#include <vector>
using namespace std;

void main1();
void main2();
void searchNum(int * arr, int arrSize, int num);

// driver program to test function main1() and main2()
int main()
{
    cout << "Executing function main1(): " << endl;
    main1();
    cout << endl;

    for (int i = 0; i < 80; i++)
    {
        cout << "-";
    }

    cout << endl;
    cout << "Executing function main2():" << endl;
    main2();
    return 0;
}

// function main1()
void main1()
{
    int input;
    int num;
    int actualArrSize = 0;
    int newArrSize = 1;
    int * prevArr = new int[1];
    
    cout << "Please enter a sequence of positive integers, each in a separate line." << endl;
    cout << "Enter -1 to end the sequence." << endl;

    while (true)
    {
        cin >> input;
        if (input == -1)
        {
            break;
        }

        if (actualArrSize == newArrSize)
        {
            int * newArr = new int[newArrSize * 2];
            for (int i = 0; i < actualArrSize; i++)
            {
                newArr[i] = prevArr[i];
            }

            delete []prevArr;
            prevArr = newArr;
            newArrSize *= 2;
        }
        prevArr[actualArrSize] = input;
        actualArrSize++;
    }

    cout << "Please enter a number you want to search." << endl;
    cin >> num;

    searchNum(prevArr, actualArrSize, num);
}

// function main2()
void main2()
{
    int input;
    int num;
    int i;
    bool flag = false;

    vector <int> vect;

    cout << "Please enter a sequence of positive integers, each in a separate line." << endl;
    cout << "Enter -1 to end the sequence." << endl;

    while (true)
    {
        cin >> input;
        if (input == -1)
        {
            break;
        }
        vect.push_back(input);
    }
    cout << "Please enter a number you want to search." << endl;
    cin >> num;

    for (int i = 0; i < vect.size(); i++)
    {
        if (vect[i] == num)
        {
            flag = true;
            cout << num << " shows in lines " <<  i + 1;
            break;
        }
    }

    for (int j = i + 1; j < vect.size(); j++)
    {
        if (vect[j] == num)
        {
            flag = true;
            cout << ", " << j + 1;
        }
    }
    
    if (flag == false)
    {
        cout << "The number you are searching for is not present in the sequence";
    }
    cout << ".";
}

// search an array for some number
void searchNum(int * arr, int arrSize, int num)
{
    int i;
    bool flag = false;

    for (i = 0; i < arrSize; i++)
    {
        if (arr[i] == num)
        {
            flag = true;
            cout << num << " shows in lines " << i + 1;
            break;
        }
    }

    for (int j = i + 1; j < arrSize; j++)
    {
        if (arr[j] == num)
        {
            flag = true;
            cout << ", " << j + 1;
        }
    }
    
    if (flag == false)
    {
        cout << "The number you are searching for is not present in the sequence";
    }
    cout << ".";
}

