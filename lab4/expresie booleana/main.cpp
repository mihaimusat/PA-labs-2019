#include <bits/stdc++.h>

#define nmax 1001
#define mod 1000000007

using namespace std;

int main()
{
    ifstream fin("a.in");
    ofstream fout("a.out");

    int n;
    string exp;

    fin>>n;
    fin>>exp;

    unsigned long long t[n+1][n+1];
    unsigned long long f[n+1][n+1];

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            t[i][j]=0;
            f[i][j]=0;
        }
    }

    for(int i=0; i<n; i+=2) {
        if(exp[i]=='T') {
            t[i][i]=1;
            f[i][i]=0;
        }
        else if(exp[i]=='F') {
            f[i][i]=1;
            t[i][i]=0;
        }
    }

    for(int i=0; i<n; i++) {
        for(int j=0; (i+j)<n; j++) {
            for(int k=j+1; k<j+i; k+=2) {
                if(exp[k]=='&') {
                    t[j][i+j] = t[j][i+j]%mod + (t[j][k-1]*t[k+1][i+j])%mod;
                    f[j][i+j] = f[j][i+j]%mod + (t[j][k-1]*f[k+1][i+j])%mod + (f[j][k-1]*t[k+1][i+j])%mod
                    +(f[j][k-1]*f[k+1][i+j])%mod;
                }
                if(exp[k]=='|') {
                    t[j][i+j] = t[j][i+j]%mod + (t[j][k-1]*t[k+1][i+j])%mod + (t[j][k-1]*f[k+1][i+j])%mod
                    +(f[j][k-1]*t[k+1][i+j])%mod;
                    f[j][i+j] = f[j][i+j]%mod + (f[j][k-1]*f[k+1][i+j])%mod;
                }
                if(exp[k]=='^') {
                    t[j][i+j] = t[j][i+j]%mod + (t[j][k-1]*f[k+1][i+j])%mod + (f[j][k-1]*t[k+1][i+j])%mod;
                    f[j][i+j] = f[j][i+j]%mod + (f[j][k-1]*f[k+1][i+j])%mod + (t[j][k-1]*t[k+1][i+j])%mod;
                }
            }
        }
    }


    fout<<t[0][n-1]%mod<<endl;

    return 0;
}
