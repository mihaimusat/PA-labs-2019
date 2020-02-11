#include <bits/stdc++.h>

#define nmax 1000001
#define mod 1000000007

using namespace std;

int n, t;
int v[nmax];
int dp[nmax][2];

void solve() {

    dp[0][0]=1;
    dp[0][1]=0;
    for(int i=1; i<=n; i++) {
        if(v[i]%2==0) {
            dp[i][0]=2*dp[i-1][0];
            dp[i][1]=2*dp[i-1][1];
        }
        else {
            dp[i][0]=dp[i-1][0]+dp[i-1][1];
            dp[i][1]=dp[i-1][0]+dp[i-1][1];
        }
        dp[i][0]=dp[i][0]%mod;
        dp[i][1]=dp[i][1]%mod;
    }
}

int main()
{
    ifstream fin("azerah.in");
    ofstream fout("azerah.out");

    fin>>t;
    while(t--) {
        fin>>n;
        for(int i=1; i<=n; i++) {
            fin>>v[i];
        }
        solve();
        fout<<dp[n][0]-1<<endl;
    }
    return 0;
}
