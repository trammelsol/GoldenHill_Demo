#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include <algorithm>
using namespace std;
 
class Solution {
public:
    int GetMinPathStringLength(int m, int n, string strTableContent) {
        vector<vector<int>> graph;
        int minSize = numeric_limits<int>::max();
        int count = 0;
        vector<int> row;
        for (char& ch : strTableContent) {
            if (ch == '|') {
                row.push_back(count);
                count = 0;
            }
            else if (ch == '/') {
                row.push_back(count);
                count = 0;
                graph.push_back(row);
                row.clear();
            }
            else
                count++;
        }
        vector<vector<int>> dp(m ,vector<int>(n));
        dp[0][0] = graph[0][0];
        for (int i = 1; i < m; i++)
            dp[i][0] = graph[i][0] + dp[i - 1][0];
        for (int i = 1; i < n; i++)
            dp[0][i] = graph[0][i] + dp[0][i - 1];
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + graph[i][j];
            }
        }
        return dp[m-1][n-1];
    }
};