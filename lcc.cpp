#include <iostream>
#include <vector>
using namespace std;

string longestRepeatingNonOverlap(string str) {
    int n = str.length();
    vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
    int length = 0; // Length of longest substring
    int pos = 0;    // Position for substring

    // Build the DP table
    for (int i = 1; i <= n; i++) {
        for (int j = i+1; j <= n; j++) {
            // Check repeated and non-overlapping
            if (str[i-1] == str[j-1] && dp[i-1][j-1] < (j - i)) {
                dp[i][j] = dp[i-1][j-1] + 1;
                // Update max length
                if (dp[i][j] > length) {
                    length = dp[i][j];
                    pos = i;
                }
            }
            else
                dp[i][j] = 0;
        }
    }

    // Return the longest substring
    if (length > 0)
        return str.substr(pos - length, length);
    else
        return "";
}

int main() {
    string str ;
    cout<<"Enter string: ";
    cin>> str;
    string res = longestRepeatingNonOverlap(str);
    if (res.empty())
        cout << "No repeating non-overlapping substring found.\n";
    else
        cout << "Longest repeating non-overlapping substring: " << res << endl;
    return 0;
}
