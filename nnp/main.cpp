#include <iostream>
#include "Nnp.h"
using namespace std;



int main()
{
    int len;

    cin >> len;

    int a[len];
    for (int i = 0; i < len; ++i)
        cin >> a[i];

    Nnp nnp;
    nnp.check(a, len);
    return 0;
}
