#include <bits/stdc++.h>

using namespace std;

int bs(int v[], int n) {

    int left = 0;
    int right = n;
    int mid = 0;

    while(left<right) {
        mid = (left + right)/2;
        if(v[mid]==mid) {
            left = mid+1;
        }
        else {
            right = mid-1;
        }
    }
    if(v[left]==left)
        return left+1;
    else
        return left;
}

int main()
{
    ifstream fin("a.in");
    ofstream fout("a.out");

    int n;
    int v[1001];

    fin>>n;

    for(int i=0; i<n; i++) {
        fin>>v[i];
    }

    sort(v, v+n);

    fout<<bs(v, n)<<endl;
    return 0;
}
