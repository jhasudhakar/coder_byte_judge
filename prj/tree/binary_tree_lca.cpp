#include <iostream>
#include <string>
using namespace std;

string BinaryTreeLCA(string strArr[], int arrLength)
{
    unsigned int n = 0, n1 = 0, n2 = 0;
    unsigned int start_index = 1;
    std::string cur_val;
    //cur_val.push_back(start_index);

    for (unsigned int i = 1; i < strArr[0].size(); i++)
    {
        if (strArr[0][i] == ',' || strArr[0][i] == ']')
        {
            n++;
            if (strArr[1].size() == i - start_index)
            {
                unsigned int j = start_index, k = 0;
                for (; j < i; j++, k++)
                {
                    if (strArr[0][j] != strArr[1][k])
                    {
                        break;
                    }
                }
                if (j == i) {
                    n1 = n;
                } else {
                    //std::cout << "First num not matching with Cur val= " << cur_val << std::endl;
                }
            }

            if (strArr[2].size() == i - start_index)
            {
                unsigned int j = start_index, k=0;
                for (; j < i; j++,k++)
                {
                    if (strArr[0][j] != strArr[2][k])
                    {
                        break;
                    }
                }
                if (j == i) {
                    n2 = n;
                }
                else {
                    //std::cout << "Second num not matching with Cur val= " << cur_val << std::endl;
                }

            }
            start_index = i + 2; // reset to next starting index
            cur_val.clear();
            i++;

        }
        else
        {
            cur_val.push_back(strArr[0][i]);
        }

        if (n1 && n2)
            break;
    }

    //std::cout << "n1= " << n1 << ", n2= " << n2 << std::endl;
    while (n1 != n2)
    {
        if (n1 > n2)
            n1 = n1 / 2;
        else
            n2 = n2 / 2;
        //std::cout << "n1= " << n1 << ", n2= " << n2 << std::endl;
    }

    unsigned int pos = 0, i;
    for (i = 1; i < strArr[0].size(); i++)
    {
        if (n1 == pos+1)
            break;
        if (strArr[0][i] == ',' || strArr[0][i] == ']')
        {
            pos++;
        }
    }

    string ret_str;
    while (!(strArr[0][i] == ',' || strArr[0][i] == ']') && i<strArr[0].size())
    {
        ret_str.push_back(strArr[0][i]);
        i++;
    }
    return ret_str;
}

int main(void) {

    std::string str_vec[] = { "[5, 2, 6, 1, #, 8, 12, #, #, #, #, #, #, 3, #]", "3", "12" };
    std::cout << "Input: { \"[5, 2, 6, 1, #, 8, 12, #, #, #, #, #, #, 3, #]\", \"3\", \"12\" } \n\n";
    std::string ret_val = BinaryTreeLCA(str_vec, 3);
    std::cout << ret_val << std::endl;
    std::cout << "Expected output = " << 12 << std::endl;
    return 0;
}