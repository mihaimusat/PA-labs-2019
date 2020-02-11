#include <bits/stdc++.h>

using namespace std;

vector <int> v;

void merge_halves(int left, int right) {

    int mid = (left+right)/2;

    int i,j;
    i = left;
    j = mid + 1;

    vector<int> aux;

    while (i<=mid && j<=right) {
        if(v[i]<=v[j]) {
            aux.push_back(v[i]);
            i++;
        }
        else {
            aux.push_back(v[j]);
            j++;
        }
    }
    while(i<=mid) {
        aux.push_back(v[i]);
        i++;
    }
    while(j<=right) {
        aux.push_back(v[j]);
        j++;
    }

    for(int k=left; k<=right; k++)
        v[k] = aux[k-left];
}

void merge_sort(int left, int right) {
    if(left>=right) return;
    int mid = (left+right)/2;

    merge_sort(left, mid);
    merge_sort(mid+1, right);

    merge_halves(left, right);
}

int main()
{
    v = {1, 6, 4, 23, 5, 3};
    merge_sort(0, v.size()-1);

    for(int i = 0; i<v.size(); i++) {
        cout << v[i] << " ";
    }
    return 0;
}
