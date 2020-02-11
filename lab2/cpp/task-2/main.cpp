#include <fstream>
#include <vector>
using namespace std;

class Task {
 public:
	void solve() {
		read_input();
		print_output(get_result());
	}

 private:
	int n, m;
	vector<int> dist;

	void read_input() {
		ifstream fin("in");
		fin >> n >> m;
		dist.push_back(0); //dist(0) = A
		for (int i = 1, d; i <= n; i++) {
			fin >> d;
			dist.push_back(d);
		}
		fin.close();
	}

	int get_result() {
		/*
		TODO: Aflati numarul minim de opriri necesare pentru a ajunge
		la destinatie.
		*/
		return gas_station();
	}

	int gas_station() {
        int sol = 0;
        int fuel = m; //cat am acum in rezervor

        for(int i = 1; i<=n; i++) {
            fuel = fuel - (dist[i]-dist[i-1]);

            if(i < n && (fuel == 0 || dist[i+1]-dist[i]>fuel)) {
                sol++;
                fuel = m;
            }
        }

        return sol;
	}

	void print_output(int result) {
		ofstream fout("out");
		fout << result;
		fout.close();
	}
};

int main() {
	Task task;
	task.solve();
	return 0;
}
