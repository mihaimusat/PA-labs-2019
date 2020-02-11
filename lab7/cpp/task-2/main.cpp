#include <fstream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

const int kNmax = 100005;

class Task {
 public:
	void solve() {
		read_input();
		print_output(get_result());
	}

 private:
	int n;
	int m;
	vector<int> adj[kNmax];

	void read_input() {
		ifstream fin("in");
		fin >> n >> m;
		for (int i = 1, x, y; i <= m; i++) {
			fin >> x >> y;
			adj[x].push_back(y);
		}
		fin.close();
	}

	void dfs(int source, vector<int>& topsort, vector<bool>& viz) {
		viz[source] = true;
		for(auto vecin : adj[source]) {
			if(viz[vecin] == true) 
				continue;			
			dfs(vecin, topsort, viz);
		}
		topsort.push_back(source);
	}

	vector<int> get_result() {
		/*
		TODO: Faceti sortarea topologica a grafului stocat cu liste de
		adiacenta in adj.
		*******
		ATENTIE: nodurile sunt indexate de la 1 la n.
		*******
		*/
		vector<int> topsort;
		vector<bool> viz(n + 1, false);
		for(int i = 1; i <= n; i++) {
			if(viz[i] == true) 
				continue;				
			dfs(i, topsort, viz);			
		}
		
		reverse(topsort.begin(), topsort.end());
		
		return topsort;
	}

	void print_output(vector<int> result) {
		ofstream fout("out");
		for (int i = 0; i < int(result.size()); i++) {
			fout << result[i] << ' ';
		}
		fout << '\n';
		fout.close();
	}
};

int main() {
	Task *task = new Task();
	task->solve();
	delete task;
	return 0;
}
