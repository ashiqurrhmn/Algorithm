#include<iostream>
using namespace std;

int knapsack(int W, int wt[], int v[], int n)
{
    if(n == 0 || W == 0)
        return 0;
    if(wt[n-1] > W)
    {
        return knapsack(W, wt, v, n-1);
    }
    else
    {
        return max(v[n-1] + knapsack(W-wt[n-1], wt, v, n-1), knapsack(W, wt, v, n-1));
    }
}

int main()
{
    int n;
    cout << "Enter value of n: ";
    cin >> n;

    int v[n];
    cout << "Enter values: ";
    for(int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    int wt[n];
    cout << "Enter weights: ";
    for(int i = 0; i < n; i++)
    {
        cin >> wt[i];
    }

    int W;
    cout << "Enter total weight: ";
    cin >> W;

    cout << "Total profit: " << knapsack(W, wt, v, n) << endl;

    return 0;
}
