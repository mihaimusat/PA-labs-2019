#include <bits/stdc++.h>

using namespace std;

struct Homework {
	int deadline;
	int score;

	Homework(int _deadline, int _score) : deadline(_deadline), score(_score) {}
};

class Task {
 public:
	void solve() {
		read_input();
		print_output(get_result());
	}

 private:
	int n;
	vector<Homework> hws;

	void read_input() {
		ifstream fin("in");
		fin >> n;
		for (int i = 0, deadline, score; i < n; i++) {
			fin >> deadline >> score;
			hws.push_back(Homework(deadline, score));
		}
		fin.close();
	}

	int get_result() {
		/*
		TODO: Aflati punctajul maxim pe care il puteti obtine planificand
		optim temele.
		*/
		int max_deadline = 0;
		for(auto h: hws) {
            		max_deadline = max(h.deadline, max_deadline);
        	}

        	vector<int> flag(n, 0);

        	int s = 0;
        	while(max_deadline > 0) {

            	int maxi = -1;
            	int pos = -1;

            		for(int i=0; i<hws.size(); i++) {

                		if(hws[i].score > maxi && flag[i]==0 && hws[i].deadline >= max_deadline) {
                    			maxi = hws[i].score;
                    			pos = i;
                		}
            		}

            		flag[pos] = 1;
            		s += maxi;

            		max_deadline--;
        	}
        	return s;
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
