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

	vector<int> gasit;
	vector<int> low;
	vector<int> parinte;
	vector<int> verif;
	
	vector<int> critice;
	
	void init() {
		gasit = vector<int>(n + 1, -1);
    		low = vector<int>(n + 1, 0);
    		parinte = vector<int>(n + 1, 0);
    		verif = vector<int>(n + 1, 0); 
	}

	void read_input() {
		ifstream fin("in");
		fin >> n >> m;
		
		init();

		for (int i = 1, x, y; i <= m; i++) {
			fin >> x >> y;
			adj[x].push_back(y);
			adj[y].push_back(x);
		}
		fin.close();
	}

	vector<int> get_result() {
		/*
		TODO: Gasiti nodurile critice ale grafului neorientat stocat cu liste
		de adiacenta in adj.
		*/
		tarjan();
		return critice;
	}

	void tarjan() {
		int inceput = 0;
		for(int i = 1; i <= n; i++) {
			if(gasit[i] == -1) {
				parinte[i] = 0;
				dfs(i, inceput);
			}
		}
		
	}

	void dfs(int nod, int& inceput) {
		inceput++;
		gasit[nod] = inceput;
		low[nod] = inceput;

		int copil = 0;
		for(auto& vecin : adj[nod]) {
			if(gasit[vecin] == -1) {
				parinte[vecin] = nod;	
				copil++;
				dfs(vecin, inceput);
				low[nod] = std::min(low[nod], low[vecin]);
				if(low[vecin] >= gasit[nod]) {
					if(parinte[nod] != 0) {
						if(!verif[nod]) {
							critice.push_back(nod);
							verif[nod] = 1;
						}
					} 
				}
			} else if(vecin != parinte[nod]) {
				low[nod] = std::min(low[nod], gasit[vecin]); 
			}

			if(parinte[nod] == 0 && copil >= 2) {
				if(!verif[nod]) {			
					verif[nod] = 1;
					critice.push_back(nod);
				}
			}
		}
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
