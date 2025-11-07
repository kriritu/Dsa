#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function to get the maximum revenue
int rodCutting(int price[], int n) {
    vector<int> dp(n+1, 0);

    for (int i = 1; i <= n; i++) {
        int maxVal = -1;
        for (int j = 0; j < i; j++) {
            maxVal = max(maxVal, price[j] + dp[i-j-1]);
        }
        dp[i] = maxVal;
    }

    return dp[n];
}

int main() {
    int price[] = {1, 5, 8, 9, 10, 17, 17, 20};
    int n = sizeof(price) / sizeof(price[0]);
    cout << "Maximum Obtainable Value is " << rodCutting(price, n) << endl;
    return 0;
}
