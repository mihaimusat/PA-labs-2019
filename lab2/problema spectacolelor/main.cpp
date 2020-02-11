#include <bits/stdc++.h>

using namespace std;

bool end_hour_comp(pair<int, int>& e1, pair<int, int>& e2) {
    return (e1.second < e2.second);
}

vector<pair<int, int>> plan(vector<pair<int, int>>& intervals) {
    vector<pair<int, int>> plan;
    sort(intervals.begin(), intervals.end(), end_hour_comp);
    int last_end = INT_MIN;
    for(auto interval : intervals) {
        if(interval.first >= last_end) {
            plan.push_back(interval);
            last_end = interval.second;
        }
    }
    return plan;
}

int main()
{
    ifstream fin("int.in");
    ofstream fout("int.out");

    int n;
    fin>>n;

    vector<pair<int, int>> v;

    for(int i=0; i<n; i++) {
        int x, y;
        fin>>x>>y;
        v.push_back({x, y});
    }

    vector<pair<int, int>> p = plan(v);
    fout<<p.size()<<endl;

    return 0;
}
