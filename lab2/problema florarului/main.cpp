#include <bits/stdc++.h>

using namespace std;

bool cmp(int a, int b) {
    return a>b;
}

int minimum_cost(vector<int>& costs, int k) {
    sort(costs.begin(), costs.end(), cmp);

    int x = 0;//numarul de flori cumparate la un moment dat
    int total_cost = 0;//costul total
    for(int i=0; i<costs.size(); i++) {
        int idx = i%k;//impartim florile in grupuri de cate k
        total_cost+=(x+1)*costs[i];

        if(idx == k-1) {
            x++;
        }
    }
    return total_cost;

}

int main()
{
    ifstream fin("a.in");
    ofstream fout("a.out");

    int n, k;
    fin>>n>>k;

    vector<int> costs(n);
    for(int i=0; i<n; i++) {
        fin>>costs[i];
    }

    fout<<minimum_cost(costs, k)<<endl;
    return 0;
}
