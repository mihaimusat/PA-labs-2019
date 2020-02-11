#include <bits/stdc++.h>

#define nmax 1001

using namespace std;

int n;
int a[nmax][nmax];
int nr[nmax+1];

int main()
{
    ifstream fin("custi.in");
    ofstream fout("custi.out");

    fin>>n;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            fin>>a[i][j];
        }
    }

    int nr[n+1];

    //dp[i][j]=nr de submatrici care au 1 in coltul dreapta jos
    for(int i=0; i<=n; i++) {
        nr[i]=0;
    }

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            if(a[i][j]==1) {
                a[i][j]=min(min(a[i-1][j], a[i][j-1]), a[i-1][j-1])+1;
                nr[a[i][j]]++;
            }
        }
    }

    for(int i=n-1; i>0; i--) {
        nr[i]+=nr[i+1];
    }
    for(int i=1; i<=n; i++) {
        fout<<nr[i]<<endl;
    }
    return 0;
}
