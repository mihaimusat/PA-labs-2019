#include <bits/stdc++.h>
#define NMAX 100001

using namespace std;

int n, v[NMAX], aux[NMAX];

int count_inversions(int left, int right) {
    if(left >= right) {
        return 0;
    }

    int mid = left+(right-left)/2;
    int crt = count_inversions(left, mid) + count_inversions(mid+1, right);

    int i = left;
    int j = mid+1;
    int k = left;

    while(i<=mid && j<=right) {
        if(v[i]<v[j]) {
            aux[k] = v[i];
            i++;
        }
        else {
            crt += (mid-i+1);
            aux[k]= v[j];
            j++;
        }
        k++;
    }

    while(i<=mid) {
        aux[k]=v[i];
        i++;
        k++;
    }

    while(j<=right) {
        aux[k]=v[j];
        j++;
        k++;
    }

    for(i=left; i<k; i++) {
        v[i]=aux[i];
    }

    return crt;
}

int main()
{
    ifstream fin("a.in");
    ofstream fout("a.out");

    int n;

    fin>>n;
    for(int i = 0; i<n; i++) {
        fin>>v[i];
    }

    int res = count_inversions(0, n-1);
    fout<<res<<endl;

    return 0;
}
