#include <bits/stdc++.h>

using namespace std;

struct Object {
	int weight;
	int price;

	Object(int _weight, int _price) : weight(_weight), price(_price) {}
};

bool cmp(Object &a, Object&b) {
    return 1.0*a.weight/a.price < 1.0*b.weight/b.price;
}

class Task {
 public:
	void solve() {
		read_input();
		print_output(get_result());
	}

 private:
	int n, w;
	vector<Object> objs;

	void read_input() {
		ifstream fin("in");
		fin >> n >> w;
		for (int i = 0, weight, price; i < n; i++) {
			fin >> weight >> price;
			objs.push_back(Object(weight, price));
		}
		fin.close();
	}

	double get_result() {
		/*
		TODO: Aflati profitul maxim care se poate obtine cu obiectele date.
		*/
        return knapsack();
	}

	double knapsack() {

        sort(objs.begin(), objs.end(), cmp);

        double sol = 0.0;

        for (auto& o : objs) {
            if(w == 0.0)
                break;
            double weight = min(w, o.weight);
            w -= weight;
            sol += 1.0*weight/o.weight * o.price;
        }
        return sol;
	}

	void print_output(double result) {
		ofstream fout("out");
		fout << setprecision(4) << fixed << result;
		fout.close();
	}
};

int main() {
	Task task;
	task.solve();
	return 0;
}
