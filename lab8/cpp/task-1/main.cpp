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
	vector<int> adjt[kNmax];

	void read_input() {
		ifstream fin("in");
		fin >> n >> m;
		for (int i = 1, x, y; i <= m; i++) {
			fin >> x >> y;
			adj[x].push_back(y);
			adjt[y].push_back(x);
		}
		fin.close();
	}

	vector<vector<int>> get_result() {
		/*
		TODO: Gasiti componentele tare conexe ale grafului orientat cu
		n noduri, stocat in adj. Rezultatul se va returna sub forma
		unui vector, ale carui elemente sunt componentele tare conexe
		detectate. Nodurile si componentele tare conexe pot fi puse in orice
		ordine in vector.
		
		Atentie: graful transpus este stocat in adjt.
		*/
		vector<vector<int>> sol;

		vector<int> viz(n + 1);
		vector<int> gata;

		//initial bag o valoare random -> am indexare de la 1
		gata.push_back(9999);

		for(int i = 1; i <= n; i++) {
			if(!viz[i]) {
				dfs(i, viz, gata);
			}
		}

		for(int i = n; i >= 1; i--) {
			if(viz[gata[i]]) { 
				vector<int> ctc;
				dfs_transpus(gata[i], viz, ctc);
				sol.push_back(ctc);
			}
		}
		return sol;
	}

	void dfs(int nod, vector<int>& viz, vector<int>& gata) {
		viz[nod] = 1;
		for(auto& v : adj[nod]) {
			if(!viz[v]) {
				dfs(v, viz, gata);
			}
		}
		gata.push_back(nod);
	}

	void dfs_transpus(int nod, vector<int>& viz, vector<int>& ctc) {
		viz[nod] = 0;
		ctc.push_back(nod);
		for(auto& v : adjt[nod]) {
			if(viz[v]) {
				dfs_transpus(v, viz, ctc);
			}
		}
	}

	void print_output(vector<vector<int>> result) {
		ofstream fout("out");
		fout << result.size() << '\n';
		for (const auto& ctc : result) {
			for (int nod : ctc) {
				fout << nod << ' ';
			}
			fout << '\n';
		}
		fout.close();
	}
};

int main() {
	Task *task = new Task();
	task->solve();
	delete task;
	return 0;
}
