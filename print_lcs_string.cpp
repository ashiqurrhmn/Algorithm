#include<iostream>
#include<string>
#include<vector>
using namespace std;

pair<int, string> lcs(string x, string y) {
    int m = x.size();
    int n = y.size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    // Build the dp table
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (x[i - 1] == y[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    // Reconstruct the LCS from the dp table
    int index = dp[m][n];
    string lcs_str(index, '\0'); // Create a string of length 'index'

    int i = m, j = n;
    while (i > 0 && j > 0) {
        if (x[i - 1] == y[j - 1]) {
            lcs_str[index - 1] = x[i - 1];
            i--;
            j--;
            index--;
        } else if (dp[i - 1][j] > dp[i][j - 1]) {
            i--;
        } else {
            j--;
        }
    }

    return {dp[m][n], lcs_str};
}

int main() {
    string x, y;
    cout << "Enter first sequence: ";
    cin >> x;
    cout << "Enter second sequence: ";
    cin >> y;

    pair<int, string> result = lcs(x, y);

    cout << "Length of LCS is: " << result.first << endl;
    cout << "LCS is: " << result.second << endl;

    return 0;
}

