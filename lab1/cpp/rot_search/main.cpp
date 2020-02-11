#include <bits/stdc++.h>

using namespace std;

int bsearch(vector<int> v, int left, int right) {

    if(left>=right) return -1;
    else {
        while(left<=right) {
            int mid = left+(right-left)/2;
            if(v[mid] < v[mid-1]) return mid;
            if(v[mid]>v[0]) {
                left = mid+1;
            }
            else if(v[mid]<v[0]) {
                right = mid-1;
            }

        }
    }
}

int main()
{
    vector<int> v = {5, 7, 9, 1, 2, 3};

    cout<<bsearch(v, 0, v.size()-1)<<" ";


    return 0;
}
