#include <bits/stdc++.h>

using namespace std;

int partition(int v[], int left, int right) {
    int i = left;
    int j = right;

    int pos = random()%(right - left + 1) + left;
    int pivot = v[pos];

    while(1) {
        while(v[i]<pivot) {
            i++;
        }
        while(v[j]>pivot) {
            j--;
        }
        if(i<j) {
            swap(v[i], v[j]);
            i++;
            j--;
        }
        else {
            return j;
        }
    }
}

void quicksort(int v[], int left, int right) {
    if(left>=right) return;
    else {
        int p = partition(v, left, right);
        quicksort(v, left, p);
        quicksort(v, p+1, right);
    }
}

int main()
{
    ifstream fin("a.in");
    ofstream fout("a.out");

    int n, v[500001];

    fin>>n;

    for(int i=0; i<n; i++) {
        fin>>v[i];
    }

    quicksort(v, 0, n-1);

    for(int i=0; i<n; i++) {
        fout<<v[i]<<" ";
    }
    return 0;
}
