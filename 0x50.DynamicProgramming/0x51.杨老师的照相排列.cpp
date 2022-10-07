#include <bits/stdc++.h>
using namespace std;

using ll = long long;

constexpr int maxn = 31;

ll dp[maxn][maxn][maxn][maxn][maxn];

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int k;
    while (cin >> k and k) {
        vector<int> arr(5);
        for (int i = 0; i < k; ++i)
            cin >> arr[i];
        memset(dp, 0, sizeof dp);
        dp[0][0][0][0][0] = 1;
        for (int i = 0; i <= arr[0]; ++i)
            for (int j = 0; j <= arr[1]; ++j)
                for (int k = 0; k <= arr[2]; ++k)
                    for (int l = 0; l <= arr[3]; ++l)
                        for (int m = 0; m <= arr[4]; ++m) {
                            if (!dp[i][j][k][l][m]) continue;
                            if (i < arr[0])
                                dp[i + 1][j][k][l][m] += dp[i][j][k][l][m];
                            if (j < arr[1] and j < i)
                                dp[i][j + 1][k][l][m] += dp[i][j][k][l][m];
                            if (k < arr[2] and k < j)
                                dp[i][j][k + 1][l][m] += dp[i][j][k][l][m];
                            if (l < arr[3] and l < k)
                                dp[i][j][k][l + 1][m] += dp[i][j][k][l][m];
                            if (m < arr[4] and m < l)
                                dp[i][j][k][l][m + 1] += dp[i][j][k][l][m];
                        }
        cout << dp[arr[0]][arr[1]][arr[2]][arr[3]][arr[4]] << '\n';
    }
    return 0;
}