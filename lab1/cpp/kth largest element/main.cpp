#include <bits/stdc++.h>

using namespace std;

int n, k;

int partition(vector<int> &v, int left, int right) {

    int pos = random()%(right - left + 1) + left;
    swap(v[left], v[pos]);

    int p = left+1;
    for(int i = left+1; i<=right; i++) {
        if(v[i] > v[left]) {
        swap(v[i], v[p]);
        p++;
        }
    }
    swap(v[left], v[p-1]);
    return p-1;
}

int kthLargest(vector<int> &v, int left, int right, int k) {
    if(left == right) {
        return v[left];
    }

    int p = partition(v, left, right);
    if(p==k) {
        return v[p];
    }
    else if(p>k) {
        return kthLargest(v, left, p-1, k);
    }
    else {
        return kthLargest(v, p+1, right, k);
    }
}


int main()
{
    ifstream fin("a.in");
    ofstream fout("a.out");

    vector<int> v;

    fin>>n>>k;

    for(int i = 0; i<n; i++) {
        int x;
        fin>>x;
        v.push_back(x);
    }

    srand(time(NULL));
    int res = kthLargest(v, 0, n-1, k-1);
    fout<<res<<endl;

    return 0;
}
