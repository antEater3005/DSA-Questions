#include <bits/stdc++.h>
using namespace std;
int minimumDiffSubset(vector<int> arr)
{

    int n = arr.size(), sum = 0;
    for (auto a : arr)
        sum += a;
    int t[n + 1][sum + 1];
    for (int i = 0; i < n + 1; i++)
        t[i][0] = 1;
    for (int i = 1; i < sum + 1; i++)
        t[0][i] = 0;
    for (int i = 1; i < n + 1; i++)
        for (int j = 1; j < sum + 1; j++)
            if (arr[i - 1] <= j)
                t[i][j] = t[i - 1][j] || t[i - 1][j - arr[i - 1]];
            else
                t[i][j] = t[i - 1][j];
    int ans = INT_MAX;
    for (int i = 0; i <= sum / 2; i++)
    {
        if (t[n][i])
            ans = min(ans, sum - 2 * i);
    }
    return ans;
}
// This function will give the number of subsets having a given sum difference;
int givenDiffSubset(vector<int> arr, int diff)
{

    int n = arr.size(), sum = 0;
    for (auto a : arr)
        sum += a;
    int t[n + 1][sum + 1];
    for (int i = 0; i < n + 1; i++)
        t[i][0] = 1;
    for (int i = 1; i < sum + 1; i++)
        t[0][i] = 0;
    for (int i = 1; i < n + 1; i++)
        for (int j = 1; j < sum + 1; j++)
            if (arr[i - 1] <= j)
                t[i][j] = t[i - 1][j] || t[i - 1][j - arr[i - 1]];
            else
                t[i][j] = t[i - 1][j];
    int ans = 0;
    for (int i = 0; i <= sum / 2; i++)
    {
        if (t[n][i] && sum - 2 * i == diff)
            ans++;
    }
    return ans;
}
int main()
{
    vector<int> arr = {5, 6, 6, 5, 7, 4, 7, 6};
    cout << minimumDiffSubset(arr);
    return 0;
}
