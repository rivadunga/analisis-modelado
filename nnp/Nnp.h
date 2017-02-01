#include <iostream>
using namespace std;

class Nnp
{
public:
    void check(int a[], int len)
    {
        for (int i = 0; i < len; i++)
        {
            int n   = a[i];
            int sum = 0;
            for (int j = 1; j < n - 1; j++)
            {
                if (n % j == 0)
                    sum += j;
            }

            if (sum == n)
                cout << "Es perfecto" << endl;
            else
                cout << "No es perfecto" << endl;
        }
    }
};
