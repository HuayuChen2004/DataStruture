#include <iostream>
#include <cstring>
using namespace std;

int LCS(string s1, string s2) {
    int m = s1.size(), n = s2.size();
    int dp[2][m + 1]; // 修正：第一维大小为2
    if (m > n) {
        swap(s1, s2);
        swap(m, n);
    }

    // 初始化dp数组
    for (int i = 0; i <= m; i++) {
        dp[0][i] = 0;
        dp[1][i] = 0;
    }

    for (int j = 1; j <= n; j++) {
        for (int i = 1; i <= m; i++) {
            if (s1[i - 1] == s2[j - 1]) { // 修正：使用正确的索引
                dp[j & 1][i] = dp[(j - 1) & 1][i - 1] + 1;
            } else {
                dp[j & 1][i] = max(dp[(j - 1) & 1][i], dp[j & 1][i - 1]);
            }
        }
    }
    return dp[n & 1][m]; // 修正：返回值
}

int main() {
    string s1 = "abcdesdgag";
    string s2 = "aceagrh";
    cout << LCS(s1, s2) << endl;
    return 0;
}
