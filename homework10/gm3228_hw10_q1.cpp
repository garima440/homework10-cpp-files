#include <iostream>
#include <string>
using namespace std;

string* createWordsArray(string sentence, int& outWordsArrSize);
bool isAlpha(char ch);

// Driver program to test function
int main()
{
    string * arr;
    int arrSize = 0;
    string sentence;

    cout << "Please enter a sentence: ";
    getline(cin, sentence);
 
    arr = createWordsArray(sentence, arrSize);

    cout << "Size of array is: " << arrSize << endl;

    for (int i = 0; i < arrSize; i++)
    {
        cout << "word " << i << ": " << arr[i] << endl;
    }
    return 0;
}

// return an array of words of in a sentence and update the array size
string* createWordsArray(string sentence, int& outWordsArrSize)
{
    int i = 0;
    outWordsArrSize = 1;
    char space = ' ';
    
    while (sentence[i] != '\0')
    {
        if (sentence[i] == ' '  && isAlpha(sentence[i + 1]) == true)
        {
            outWordsArrSize++;
        }
        i++;
    }

    string* wordArr = new string[outWordsArrSize];

    int starting_pos = 0;
    for (int i = 0; i < outWordsArrSize; i++)
    {
        int index = sentence.find(space, starting_pos);
        wordArr[i] = sentence.substr(starting_pos, index - starting_pos);
        starting_pos = index + 1;
    }
    return wordArr;
}

// check if a letter is alphabet
bool isAlpha(char ch)
{
    bool flag = false;

    if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
    {
        flag = true;
    }

    return flag;
}