#include <bits/stdc++.h>

using namespace std;

int bsearch(vector<int> v, int left, int right, int val) {

    if(left>=right) return -1;
    else {
    int mid = (left+right)/2;
    if(v[mid]==val) return mid;
    if(v[mid]<val) //right = mid-1;
        return bsearch(v, left, mid-1, val);
    if(v[mid]>val) //left = mid+1;
        return bsearch(v, mid+1, right, val);

    }
}

int main()
{
    vector<int> v;

    v = {1, 2, 4, 5, 8, 9};
    int x = 8;

    cout<<bsearch(v,0,v.size()-1,x)<<" ";

    return 0;
}
