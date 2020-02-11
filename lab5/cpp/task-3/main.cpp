#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

class Task {
 public:
	void solve() {
		read_input();
		print_output(get_result());
	}

 private:
	int n;

	void read_input() {
		ifstream fin("in");
		fin >> n;
		fin.close();
	}

	vector<int> get_result() {
		vector<int> sol(n + 1, 0);

		/*
		TODO: Gasiti o solutie pentru problema damelor pe o tabla de dimensiune
		n x n.

		Pentru a plasa o dama pe randul i, coloana j:
			sol[i] = j.
		Randurile si coloanele se indexeaza de la 1 la n.

		De exemplu, configuratia (n = 5)
		X----
		--X--
		----X
		-X---
		---X-
		se va reprezenta prin sol[1..5] = {1, 3, 5, 2, 4}.
		*/

		vector<int> visited(n+1, 0);

		bkt(1, visited, sol);

		return sol;
	}

	bool bkt(int crt_line, vector<int>& visited, vector<int>& sol) {
        if(crt_line == n+1) {
            return true;
        }

        for(int j=1; j<=n; j++) {
            if(visited[j]) {
                continue;
            }
        //sol[i]=coloana unde punem regina de pe linia i
        bool ataca=false;
        for(int line = 1; line<crt_line; line++) {
            if(abs(crt_line-line)==abs(j-sol[line])) {
                ataca=true;
                break;
            }
        }
        if(ataca) {
            continue;
        }

        //!!!!
        sol[crt_line]=j;
        visited[j]=1;

        bool ok = bkt(crt_line+1, visited, sol);

        if(ok) {
            return true;
        }

        sol[crt_line]=0;
        visited[j]=0;

        }
        return false;
	}

	void print_output(vector<int> result) {
		ofstream fout("out");
		for (int i = 1; i <= n; i++) {
			fout << result[i] << (i != n ? ' ' : '\n');
		}
		fout.close();
	}
};

int main() {
	Task task;
	task.solve();
	return 0;
}
