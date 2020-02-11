#include <bits/stdc++.h>

using namespace std;

typedef struct {
    int before;
    int after;
}Object;

bool cmp(Object& a, Object& b) {
    return (a.before - a.after) < (b.before - b.after);
}

int main()
{
    ifstream fin("a.in");
    ofstream fout("a.out");

    int n, k;
    fin>>n>>k;

    vector<Object> objects(n);

    for(int i=0; i<n; i++) {
        fin>>objects[i].before;
    }

    for(int i=0; i<n; i++) {
        fin>>objects[i].after;
    }

    sort(objects.begin(), objects.end(), cmp);

    int sum = 0;
    int luate = 0;
    while(luate < k || (objects[luate].after - objects[luate].before > 0)) {
        sum += objects[luate].before;
        luate++;
    }
    while(luate < n) {
        sum += objects[luate].after;
        luate++;
    }

    fout<<sum<<endl;

    return 0;
}
