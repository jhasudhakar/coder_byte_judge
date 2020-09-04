#include <iostream>
#include <string>
using namespace std;

int ChangingSequence(int arr[], int arrLength) {

    // code goes here  
    int inc_break = 0;
    int dec_break = 0;

    // Test increasing
    int i = 1;
    for (; i < arrLength; i++)
    {
        if (arr[i] <= arr[i - 1])
        {
            break;
        }
    }
    if (i == arrLength)
    {
        // increasing sequence
        return -1;
    }
    else
    {
        inc_break = i - 1;
    }

    // Test decreasing
    i = 1;
    for (; i < arrLength; i++)
    {
        if (arr[i] >= arr[i - 1])
        {
            break;
        }
    }
    if (i == arrLength)
    {
        // decreasing sequence
        return -1;
    }
    else
    {
        dec_break = i - 1;
    }

    if (inc_break > dec_break)
        return inc_break;
    else
        return dec_break;
}

