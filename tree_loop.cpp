using namespace std;
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <algorithm>

static int tree[100000];
static int dp[100000];
static void getTree(int lvl, int target, int* plen)
{
    int t;
    if (lvl >= target)
    {
        cin >> tree[(*plen)++];
        return;
    }
    else
    {
        cin >> t;
        getTree(lvl + 1, target, plen);
        getTree(lvl + 1, target, plen);
    }
}
static inline int max(int x, int y)
{
    return x > y ? x : y;
}
int main()
{
    int n, k, i, len, tmp;
    while (cin >> n)
    {
        k = n + 1;
        i = 0;
        while (k > 1)
        {
            k >>= 1;
            i++;
        }
        k = i;
        len = 0;
        getTree(0, k - 1, &len);
        for (i = 0; i < n; i++)
            cin >> tmp;
        dp[0] = tree[0];
        dp[1] = tree[1];
        dp[2] = tree[2] + dp[0];
        for (i = 3; i < len; i++)
            dp[i] = tree[i] + max(dp[i - 2], dp[i - 3]);
        if (len <= 1)
            cout << dp[len - 1];
        else
            cout << max(dp[len - 1], dp[len - 2]);
        cout << endl;
    }
    return 0;
}