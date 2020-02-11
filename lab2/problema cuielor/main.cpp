#include <bits/stdc++.h>

using namespace std;

bool point_in_interval(const pair<int, int>& interval, int point) {
    return point>=interval.first && point<=interval.second;
}

bool cmp(pair<int, int>& a, pair<int, int>& b) {
    return a.second<b.second;
}

vector<int> cover_intervals(vector<pair<int, int>>& intervals) {
    vector<int> nails;
    int last_point = INT_MIN;

    sort(intervals.begin(), intervals.end(), cmp);

    for(auto interval:intervals) {
        if(!point_in_interval(interval, last_point)) {
            nails.push_back(interval.second);
            last_point = interval.second;
        }
    }
    return nails;
}

int main()
{
    ifstream fin("a.in");
    ofstream fout("a.out");

    int n;
    fin>>n;

    vector<pair<int, int>> v(n);

    for(int i=0; i<n; i++) {
        fin>>v[i].first>>v[i].second;
    }

    vector<int> res = cover_intervals(v);

    for(int i=0; i<res.size(); i++) {
        fout<<res[i]<<" ";
    }

    return 0;
}
