#include <iostream>
#include <string>
using namespace std;

int ChangingSequence(int arr[], int arrLength) {

    // code goes here  
    bool is_increasing = false;
    int inc_break = 0;

    bool is_decreasing = false;
    int dec_break = 0;

    // Test increasing
    int prev_val = arr[0];
    int i = 1;
    for (; i < arrLength; i++)
    {
        if (arr[i] <= prev_val)
        {
            break;
        }
        prev_val = arr[i];
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
    prev_val = arr[0];
    i = 1;
    for (; i < arrLength; i++)
    {
        if (arr[i] >= prev_val)
        {
            break;
        }
        prev_val = arr[i];
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

