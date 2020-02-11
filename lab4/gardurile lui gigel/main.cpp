#include <bits/stdc++.h>
#define mod 1009

using namespace std;

int main()
{
    ifstream fin("a.in");
    ofstream fout("a.out");

    int n;

    fin>>n;

    vector<int> dp(n+1);

    dp[1]=1;
    dp[2]=1;
    dp[3]=1;
    dp[4]=2;

    for(int i=5; i<=n; i++) {
        dp[i]=(dp[i-1]+dp[i-4]) % mod;
    }
    fout<<dp[n]<<endl;
    return 0;
}
