#include "cubestringcalc.h"
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
#include <chrono>
using namespace std;

void find_path(const char*, std::string, const int, int, int);
int eq(char*, char*);

char cornerarray[24] =
{
    'Y','R','B',
    'Y','O','B',
    'Y','O','G',
    'Y','R','G',
    'W','R','G',
    'W','O','G',
    'W','O','B',
    'W','R','B'
};

char orig[24];
int checked = 0;

char solved[24] =
{
    'Y','R','B',
    'Y','O','B',
    'Y','O','G',
    'Y','R','G',
    'W','R','G',
    'W','O','G',
    'W','O','B',
    'W','R','B'
};

char str[] = 
{ 
    'a', 'b', 'c', //R
    'd', 'e', 'f', //U
    'g', 'h', 'i', //L
    'm', 'n', 'o', //F
};

char result;

int main(int argc, char *argv[])
{
    auto begin = std::chrono::high_resolution_clock::now();
    char* arr = (char*)malloc(argc);
    for (size_t i = 1; i < argc; i++)
    {
        arr[i - 1] = *argv[i];
    }

    calc(cornerarray, arr, argc - 1);
    memcpy(orig, cornerarray, 24 / sizeof(char));
   
    int orig_len = 1;
    while (result != 'y')
    {
        cout << " [*] checking depth " << orig_len << "\n";
        find_path(str, "", sizeof(str), orig_len, orig_len);

        orig_len++;
    }

    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now() - begin);
    std::printf(" [*] searched %i %.4f states per second\n", checked, checked / (elapsed.count() * 1e-9));
}


void find_path(const char str[], std::string prefix, const int n, int length, int orig_len)
{
    if (result == 'y')
    {
        return;
    }
    char* c = &prefix[0];
    if (length != 1)
    {
        for (int i = 0; i < n; i++)
        {
            find_path(str, prefix + str[i], n, length - 1, orig_len);
        }
    }
    else
    {
        for (int j = 0; j < n; j++)
        {
            c[orig_len - 1] = str[j];

            calc(cornerarray, c, orig_len);
            checked++;
            if (eq(cornerarray, solved))
            {
                cout << " [*] solution: " << c << "\n";
                result = 'y';
            }
            memcpy(cornerarray, orig, 24 / sizeof(char));
        }
    }
}

int eq(char* ar1, char* ar2)
{
    for (size_t i = 0; i < 24; i++)
    {
        if (ar1[i] != ar2[i])
        {
            return 0;
        }
    }
    return 1;
}
