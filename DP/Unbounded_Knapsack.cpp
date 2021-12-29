// In unbounded knapsack there are multiple occurrences of a single item ;
// An item is not marked as processed until it's declined at some point of time.
#include <bits/stdc++.h>
using namespace std;
// 1. Unbounded Knapsack:Solution using recursion
int unbounded_knapsack(vector<int> weight, vector<int> value, int size, int capacity)
{
    if (size == 0 || capacity == 0)
        return 0;
    if (weight[size - 1] <= capacity)
        return max(value[size - 1] + unbounded_knapsack(weight, value, size, capacity - weight[size - 1]),
                   unbounded_knapsack(weight, value, size - 1, capacity));
    else
        return unbounded_knapsack(weight, value, size - 1, capacity);
}
// 2. Solution using recursion and memoization
// helper function:
int unbounded_knapsack_memo_util(vector<int> weight, vector<int> values, int size, int capacity, vector<vector<int>> &memo)
{
    if (size == 0 || capacity == 0)
        return 0;
    if (memo[size - 1][capacity] != -1)
        return memo[size - 1][capacity];
    if (weight[size - 1] <= capacity)
        return memo[size - 1][capacity] = max(values[size - 1] + unbounded_knapsack_memo_util(weight, values, size, capacity - weight[size - 1], memo), unbounded_knapsack_memo_util(weight, values, size - 1, capacity, memo));
    else
        return memo[size - 1][capacity] = unbounded_knapsack_memo_util(weight, values, size - 1, capacity, memo);
}
//main function:
int unbounded_knapsack_memo(vector<int> weight, vector<int> values, int size, int capacity)
{
    vector<vector<int>> memo(size + 1, vector<int>(capacity + 1, -1));
    return unbounded_knapsack_memo_util(weight, values, size, capacity, memo);
}
// Top-Down approach:
int unbounded_knapsack_topDown(vector<int> weight, vector<int> values, int size, int capacity) //incomplete
{
    int memo[size + 1][capacity + 1];
    for (int i = 0; i < size + 1; i++)
        memo[i][0] = 0;
    for (int i = 1; i < capacity + 1; i++)
        memo[0][i] = 0;
    int i = 1, j = 1;
    while (i <= size)
    {
        while (j <= capacity)
        {
            if (weight[i - 1] > j)
            {
                memo[i][j] = memo[i - 1][j];
                i++;
            }
            else
            {
                memo[i][j] = max(values[i - 1] + memo[i - 1][j - weight[i - 1]], memo[i - 1][j]);
            }
            j++;
        }
        i++;
    }
    return memo[size][capacity];
}
int main()
{

    int W = 8;
    vector<int> val = {10, 40, 50, 70};
    vector<int> wt = {1, 3, 4, 5};
    int n = val.size();
    cout << unbounded_knapsack_memo(wt, val, n, W);
    return 0;
}