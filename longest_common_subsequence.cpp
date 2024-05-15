#include<iostream>
#include<string>
using namespace std;

int lcs(string x, string y, int m, int n)
{
    if(n == 0 || m == 0)
        return 0;
    if(x[m-1] == y[n-1])
        return 1 + lcs(x, y, m-1, n-1);
    else
        return max(lcs(x, y, m, n-1), lcs(x, y, m-1, n));
}

int main()
{
    string x;
    cout << "Enter first sequence: ";
    cin >> x;
    string y;
    cout << "Enter second sequence: ";
    cin >> y;
    int m = x.size();
    int n = y.size();

    cout << "Length of LCS is: " << lcs(x, y, m, n) << endl;

    return 0;
}
