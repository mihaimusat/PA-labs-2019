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

	vector<vector<int> > get_result() {
		vector<vector<int> > all;

		/*
		TODO: Construiti toate submultimile multimii {1, ..., N}.

		Pentru a adauga o noua submultime:
			vector<int> submultime;
			all.push_back(submultime);
		*/

		vector<int>subm;

		vector<int>visited(n+1, 0);

		bkt(subm, visited, all);

		return all;
	}

    void bkt(vector<int>& subm, vector<int>& visited, vector<vector<int>>& all ) {
        if(subm.size() <= n) {
            all.push_back(subm);
        }

        if(subm.size() == n) {
            return;
        }

        int start;
        if(subm.size() == 0) {
            start = 0;
        }
        else {
            start = subm.back();
        }

        for(int i = start+1; i<=n; i++) {
            subm.push_back(i);
            visited[i]=1;

            bkt(subm, visited, all);

            subm.pop_back();
            visited[i]=0;
        }
    }

	void print_output(vector<vector<int> > result) {
		ofstream fout("out");
		fout << result.size() << '\n';
		for (int i = 0; i < (int)result.size(); i++) {
			for (int j = 0; j < (int)result[i].size(); j++) {
				fout << result[i][j] <<
					(j + 1 != result[i].size() ? ' ' : '\n');
			}
		}
		fout.close();
	}
};

int main() {
	Task task;
	task.solve();
	return 0;
}
