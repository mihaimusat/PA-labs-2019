#include <fstream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;
 
#define inf (1 << 20)
const int kNmax = 1005;
 
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
  	int C[kNmax][kNmax];
	
	int viz[kNmax];
	int parinte[kNmax];
 
	void read_input() {
		ifstream fin("in");
		fin >> n >> m;
 
		memset(C, 0, sizeof C);
		for (int i = 1, x, y, z; i <= m; i++) {
			fin >> x >> y >> z;
			adj[x].push_back(y);
			adj[y].push_back(x);
      			C[x][y] += z;
		}
		fin.close();
	}
 
	bool bfs() {
        	memset(viz, 0, sizeof(viz));
        	queue<int> q;
        	q.push(1);
        	viz[1] = 1;
 
        	while(!q.empty()) {
            		int nod = q.front();
            		q.pop();
            		if(nod != n) {
            			for(auto vecin : adj[nod]) {
                			if(!viz[vecin] && C[nod][vecin]) {
 						parinte[vecin] = nod;
                				viz[vecin] = 1;
                				q.push(vecin);
					}
            			}
			}
        	}
 
        	return viz[n];
    	}
 
	int get_result() {
		/*
		TODO: Calculati fluxul maxim pe graful orientat dat.
		Sursa este nodul 1.
		Destinatia este nodul n.

		In adj este stocat graful neorientat obtinut dupa ce se elimina orientarea
		arcelor, iar in C sunt stocate capacitatile arcelor.
		De exemplu, un arc (x, y) de capacitate z va fi tinut astfel:
		C[x][y] = z, adj[x] contine y, adj[y] contine x.
		*/
		int maxflow = 0;
        	while(bfs()) {
            		for(auto vecin : adj[n]) {
                		if(viz[vecin] && C[vecin][n]) {
                  			parinte[n] = vecin;
                			int flow = inf;
                 			for(int nod = n; nod != 1; nod = parinte[nod]) {
                    				flow = min(flow, C[parinte[nod]][nod]);
                			}
 
                			for(int nod = n; nod != 1; nod = parinte[nod]) {
                    				C[parinte[nod]][nod] -= flow;
                    				C[nod][parinte[nod]] += flow;
                			}
 
                			maxflow += flow;
				}
            		}
        	}
 
        	return maxflow;
    	}
	 
	void print_output(int result) {
		ofstream fout("out");
		fout << result << '\n';
		fout.close();
	}
};
 
int main() {
	Task *task = new Task();
	task->solve();
	delete task;
	return 0;
}
