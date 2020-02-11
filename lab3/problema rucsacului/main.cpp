#include <bits/stdc++.h>

#define nmax 5005
#define gmax 10005

int dp[gmax];
int w[nmax];
int p[nmax];

using namespace std;

int main()
{
    ifstream fin("rucsac.in");
    ofstream fout("rucsac.out");

    int n, g;

    fin>>n>>g;
    for(int i=1; i<=n; i++) {
        fin>>w[i]>>p[i];
    }
    for(int i=1; i<=n; i++) {
        for(int j=g; j>=w[i]; j--) {
            dp[j] = max(dp[j-w[i]]+p[i], dp[j]);
        }
    }

    fout<<dp[g]<<endl;

    return 0;
}
