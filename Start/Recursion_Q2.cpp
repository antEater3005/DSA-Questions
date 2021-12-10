// CODE TO CALCULATE P TO THE POWER N, USING RECURSION.
#include <iostream>
using namespace std;
int power(int p, int n)
{
    if (n == 0)
    {
        return 1;
    }
    int prevpower = power(p, n - 1);
    return p * prevpower;
}

int main()
{
    int n, p;
    cin >> p >> n;
    cout << power(p, n) << endl;

    return 0;
}