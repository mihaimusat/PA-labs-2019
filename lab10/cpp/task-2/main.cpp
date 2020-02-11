#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <set>
#include <tuple>
#include <queue>


using namespace std;

const int kNmax = 2e5 + 10;

class Task {
 public:
	void solve() {
		read_input();
		print_output(get_result());
	}

 private:
	int n;
	int m;
	vector<pair<int, int> > adj[kNmax];

	void read_input() {
		ifstream fin("in");
		fin >> n >> m;
		for (int i = 1, x, y, w; i <= m; i++) {
			fin >> x >> y >> w;
			adj[x].push_back(make_pair(y, w));
			adj[y].push_back(make_pair(x, w));
		}
		fin.close();
	}

	struct cmp {
    		bool operator() (pair<int, int>& a, pair<int, int>& b) {
        		return a.second > b.second;
		}
	};

	int get_result() {
		/*
		TODO: Calculati costul minim al unui arbore de acoperire
		folosind algoritmul lui Prim.
		*/

        	priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
        	vector<int> viz(n + 1, 0);
        	
		int minWeight = 0;

        	viz[1] = 1;
        	for(auto& muchie : adj[1]) {
            		pq.emplace(muchie);
        	}

        	while(!pq.empty()) {
            		pair<int, int> now = pq.top();
            		pq.pop();
            		if(!viz[now.first]) {
                		minWeight += now.second;
                		viz[now.first] = 1;
                		for(auto& muchie : adj[now.first]) {
                    			if(!viz[muchie.first]) {
                        			pq.emplace(muchie.first, muchie.second);
                    			}
                		}
            		}
        	}

		return minWeight;
	}

	void print_output(int result) {
		ofstream fout("out");
		fout << result << "\n";
		fout.close();
	}
};

int main() {
	Task *task = new Task();
	task->solve();
	delete task;
	return 0;
}
