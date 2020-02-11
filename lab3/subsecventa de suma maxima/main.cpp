#include <bits/stdc++.h>

using namespace std;

int main()
{
    ifstream fin("a.in");
    ofstream fout("a.out");

    int n, x, crt_sum = -1, best_sum = INT_MIN, crt_start, best_start, finish;

    fin>>n;
    for(int i = 1; i<=n; i++) {
        fin>>x;
        if(crt_sum < 0) {
            crt_start = i;
            crt_sum = x;
        }
        else {
            crt_sum += x;
        }

        if(best_sum < crt_sum) {
            best_sum = crt_sum;
            best_start = crt_start;
            finish = i;
        }
    }
    fout<<best_sum<<" "<<best_start<<" "<<finish<<endl;

    /*
    int n;
    vector<int> v;

    fin>>n;
    for(int i=0; i<n; i++) {
        int x;
        fin>>x;
        v.push_back(x);
    }

    vector<int> dp(NMAX);
    vector<int> start(NMAX);

    dp[0]=v[0];
    start[0]=0;

    for(int i=1; i<n; i++) {
        if(dp[i-1]<0) {
            dp[i]=v[i];
            start[i]=i;
        }
        else {
            dp[i]=dp[i-1]+v[i];
            start[i] = start[i-1];
        }
    }
    int sol = dp[0];
    int pos = 0;
    for(int i = 1; i<n; i++) {
        if(dp[i]>sol) {
            sol = dp[i];
            pos = i;
        }
    }
    fout<<sol<<" "<<start[pos]+1<<" "<<pos+1<<endl;

    */
    return 0;
}
