#include "bits/stdc++.h"
using namespace std;
void swap(int a, int b)
{
    int t = a;
    a = b;
    b = t;
}
// Given a sorted array of positive integers. Your task is to rearrange  the array elements alternatively i.e first element should be max value, second should be min value, third should be second max, fourth should be second min and so on.
void rearrange(long long *arr, int n)
{
    int min = 0, max = n - 1, me = arr[n - 1] + 1; // me is the maximum element in the array
    for (int i = 0; i < n; i++)
    {
        if (i % 2 == 0)
        {
            arr[i] += ((arr[max] % me) * me);
            max--;
        }
        else
        {
            arr[i] += ((arr[min] % me) * me);
            min++;
        }
    }
    for (int i = 0; i < n; i++)
    {
        arr[i] = arr[i] / me;
    }
}
//Given arrival and departure times of all trains that reach a railway station. Find the minimum number of platforms required for the railway station so that no train is kept waiting.
// https://practice.geeksforgeeks.org/problems/minimum-platforms-1587115620/1/?category[]=Arrays&category[]=Arrays&problemStatus=unsolved&difficulty[]=1&page=1&query=category[]ArraysproblemStatusunsolveddifficulty[]1page1category[]Arrays#
int maxPF(int arr[], int dep[], int n)
{
    int temp[2400] = {0};
    for (int i = 0; i < n; i++)
    {
        temp[arr[i]]++;
        temp[dep[i] + 1]--;
    }
    int maxPf = 0;
    for (int i = 1; i < 2400; i++)
    {
        temp[i] += temp[i - 1];
        maxPf = max(temp[i], maxPf);
    }
    return maxPf;
}
int main()
{
    int arr[] = {900, 940, 950, 1100, 1500, 1800};
     int dep[] = {910, 1200, 1120, 1130, 1900, 2000};
    // int arr[] = {1, 2, 3, 4, 5, 6};
    return 0;
}