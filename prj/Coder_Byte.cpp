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
        if (arr[i] <= arr[i-1])
        {
            break;
        }
    }
    if (i == arrLength)
    {
        // increasing sequence
        return -1;
    }
    else if (i > 1) // if decreasing seq then i should be 1.
    {
        return i - 1;
    }
    else
    {
        inc_break = i-1;
    }

    // Test decreasing
    i = 1;
    for (; i < arrLength; i++)
    {
        if (arr[i] >= arr[i-1])
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
        dec_break = i-1;
    }

    if (inc_break > dec_break)
        return inc_break;
    else
        return dec_break;
}


int main(void) {

    // keep this function call here
    /* Note: In C++ you first have to initialize an array and set
       it equal to the stdin to test your code with arrays. */

    //int A[] = coderbyteInternalStdinFunction(stdin);
    int A[] = { 0, 1,2,3,4,5,6 };
    int arrLength = sizeof(A) / sizeof(*A);
    cout << ChangingSequence(A, arrLength);
    return 0;

}