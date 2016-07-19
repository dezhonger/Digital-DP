#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

//包含13且是13的倍数
int bit[15];
int dp[15][15][3];

int dfs(int pos, int mod, int have, bool limit)
{
    if(pos == 0) return mod == 0 && have == 2;
    if(!limit && dp[pos][mod][have] != -1) return dp[pos][mod][have];
    int last = limit ? bit[pos] : 9;
    int result = 0;

    for(int i = 0; i <= last; i++) {
        int have13 = have;
        if(have == 0 && i == 1) have13 = 1;
        if(have == 1 && i != 1) have13 = 0;
        if(have == 1 && i == 3) have13 = 2;
        result += dfs(pos - 1, (mod * 10 + i) % 13, have13, limit && i == last);
    }
    if(!limit) dp[pos][mod][have] = result;
    return result;
}



int main()
{
    int n,len;
    while(~scanf("%d",&n))
    {
        memset(bit,0,sizeof(bit));
        memset(dp,-1,sizeof(dp));
        len = 0;
        while(n)
        {
            bit[++len] = n%10;
            n/=10;
        }
        printf("%d\n",dfs(len,0,0,true));
    }

    return 0;
}

