#include <bits/stdc++.h>

using namespace std;

int bsearch(vector<int> v, int left, int right, int val) {

    while(left<=right) {
        int mid = left+(right-left)/2;
        if(v[mid]==val) return v[mid];
        if(v[mid]< val) left = mid + 1;
        if(v[mid] > val) right = mid-1;
    }
    if(left>=right) return -1;
}

int main()
{
    vector<int> v1 = {1, 2, 5, 6, 7};
    vector<int> v2 = {2, 3, 6, 9, 10};

    vector<int> v3;

    for(int i=0; i<v1.size(); i++) {
        int pos = bsearch(v1, 0, v1.size()-1, v2[i]);
        if(pos != -1) {
            v3.push_back(v2[i]);
        }
    }

    for(int i=0; i<v3.size(); i++) {
        cout<<v3[i]<<" ";
    }


    return 0;
}
