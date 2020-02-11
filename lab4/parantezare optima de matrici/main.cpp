#include <bits/stdc++.h>

#define nmax 501
#define inf 100000000000000000LL

using namespace std;

int n;
long long d[nmax];
long long dp[nmax][nmax];

long long solve(long long d[], int n) {

    for(int i=0; i<=n; i++) {
        dp[i][i]=0LL;
    }
    for(int i=1; i<=n-1; i++) {
         dp[i][i+1]=1LL*d[i-1]*d[i]*d[i+1];
    }
    for(int len=2; len<=n-1; len++) {
        for(int i=1; i+len<=n; i++) {
            int j=i+len;
            dp[i][j]=inf;
            for(int k=i; k<=j-1; k++) {
                long long sol=(dp[i][k]+dp[k+1][j]+1LL*d[i-1]*d[k]*d[j]);
                dp[i][j]=min(sol, dp[i][j]);
            }
        }
    }
    return dp[1][n];
}

int main()
{
    ifstream fin("podm.in");
    ofstream fout("podm.out");

    fin>>n;
    for(int i=0; i<=n; i++) {
        fin>>d[i];
    }

    fout<<solve(d, n)<<endl;

    return 0;
}
