// Boyer-Moore algorithm is also known as Majority vote algorithm.
// It find out the number having maximum repetition in list.
#include <iostream>
using namespace std;
int MajorityVote(int a[], int n)
{
    int candidate = 0;
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (count == 0)
            candidate = a[i];
        if (candidate == a[i])
            count++;
        else
            count--;
    }
    return candidate;
}
int main()
{
    int a[] = {2,4,1,2,3,1,1,2}; // the majority element is 5.
    int n = 8;
    cout << MajorityVote(a, n);
    return 0;
}