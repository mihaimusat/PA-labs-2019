#include <bits/stdc++.h>

#define nmax 1025

using namespace std;

int a[nmax];
int b[nmax];
int dp[nmax][nmax];
int s[nmax];

/*
void make_lcs(int i, int j, vector<int>& seq) {

    if(i < 0 || j < 0) {
        if(seq.size() > best_seq.size()) {
            best_seq = seq;
        }
        return;
    }

    if(v1[i] == v2[j]) {
        seq.push_back(v1[i]);
        make_lcs(i-1,j-1,seq);
        seq.pop_back();
    }
    else {
        make_lcs(i,j-1,seq);
        make_lcs(i-1,j,seq);
    }
}
*/

int main()
{
    ifstream fin("cmlsc.in");
    ofstream fout("cmlsc.out");

    int n, m;

    fin>>m>>n;
    for(int i=1; i<=m; i++) {
        fin>>a[i];
    }
    for(int i=1; i<=n; i++) {
        fin>>b[i];
    }

    for(int i=1; i<=m; i++) {
        for(int j=1; j<=n; j++) {
            if(a[i]==b[j]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    fout<<dp[m][n]<<endl;

    int i = m;
    int j = n;
    while(i>0 && j>0) {
        if(a[i]==b[j]) {
            s[dp[i][j]]=a[i];
            i--;
            j--;
        }
        else if(dp[i-1][j]<dp[i][j-1]) {
            j--;
        }
        else {
            i--;
        }
    }

    for(int i=1; i<=dp[m][n]; i++) {
        fout<<s[i]<<" ";
    }

    return 0;
}
