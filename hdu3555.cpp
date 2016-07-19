#include <iostream>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<iostream>
using  namespace std;
const int N = 20;
typedef long long LL;
int dig[N];
LL dp[N][10][2];

LL dfs(int pos, int pre, bool has49, bool limit)
{
    if(pos == 0) return has49;
    if(!limit && dp[pos][pre][has49] != -1) {
        return dp[pos][pre][has49];
    }
    int last = limit ? dig[pos] : 9;
    LL ret = 0;
    for(int i = 0; i <= last; i++) {
        ret += dfs(pos - 1, i, has49 || (pre == 4 && i == 9), limit && (i == last));
    }
    if(!limit) dp[pos][pre][has49] = ret;
    return ret;
}

LL solve(LL n)
{
    int len = 0;
    while(n) {
        dig[++len] = n % 10;
        n /= 10;
    }
    return dfs(len, 0, false, true);
}

int main()
{
    memset(dp, -1, sizeof(dp));
    int T; scanf("%d",&T);
    while (T--) {
        LL n;
        cin >> n;
        cout << solve(n) << endl;
    }
    return 0;
}
