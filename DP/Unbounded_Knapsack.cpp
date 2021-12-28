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

int main()
{

    int W = 8;
    vector<int> val = {10, 40, 50, 70};
    vector<int> wt = {1, 3, 4, 5};
    int n = val.size();
    cout << unbounded_knapsack_memo(wt, val, n, W);
    return 0;
}