#include <bits/stdc++.h>

#define nmax 100005

using namespace std;

vector<int> v(nmax);
vector<int> dp(nmax);
vector<int> prec(nmax);
vector<int> scmax(nmax);

int main()
{
    ifstream fin("scmax.in");
    ofstream fout("scmax.out");

    int n;

    fin>>n;
    for(int i = 1; i <= n; i++) {
        fin>>v[i];
    }

    dp[1] = 1;
    prec[1] = 0;

    for(int i = 2; i <= n; i++) {
        dp[i] = 1;
        prec[i] = 0;
        for(int j = 1; j < i; j++) {
            if(v[j] < v[i]) {
                if(dp[j] + 1 > dp[i])  {
                    dp[i] = dp[j] + 1;
                    prec[i] = j;
                }
            }
        }
    }

    int sol = dp[1];
    int pos = 1;

    for(int i = 2; i <= n; i++) {
        if(dp[i] > sol) {
            sol = dp[i];
            pos = i;
        }
    }

    fout<<sol<<endl;

    for(int i = 1; i <= sol; i++) {
        scmax.push_back(v[pos]);
        pos = prec[pos];
    }

    reverse(scmax.begin(),scmax.end());

    for(int i = 0; i < sol; i++) {
        fout<<scmax[i]<<" ";
    }

    return 0;
}
