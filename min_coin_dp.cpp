#include<bits/stdc++.h>
using namespace std;

int min_coin(int coin[], int amount, int n)
{
    // Dynamic programming array to store minimum coins required
    vector<vector<int>> solution(n + 1, vector<int>(amount + 1, INT_MAX));

    // Base case: If amount is 0, no coins are needed
    for(int i = 0; i <= n; i++)
        solution[i][0] = 0;

    // Build the solution table bottom-up
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= amount; j++)
        {
            if(coin[i - 1] > j)
            {
                // If the current coin value is greater than the amount, just use the previous solution
                solution[i][j] = solution[i - 1][j];
            }
            else
            {
                // If we can use the current coin, either we use it or we don't
                solution[i][j] = min(solution[i - 1][j], 1 + solution[i][j - coin[i - 1]]);
            }
        }
    }
    // Return the minimum coins required for the given amount
    return solution[n][amount];
}

int main()
{
    int n;
    cout << "Enter the number of coins: ";
    cin >> n;

    cout << "Enter coins: ";
    int coin[n];
    for(int i = 0; i < n; i++)
    {
        cin >> coin[i];
    }

    int amount;
    cout << "Enter amount: ";
    cin >> amount;

    int minCoins = min_coin(coin, amount, n);
    cout << "Minimum coins required: " << minCoins << endl;

    return 0;
}
