#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <cmath>

using namespace std;

class Task {
public:
	void solve() {
		read_input();
		print_output(compute_sqrt());
	}

private:
	double n;

	void read_input() {
		ifstream fin("in");
		fin >> n;
		fin.close();
	}

	double compute_sqrt() {
		/*
		TODO: Calculati sqrt(n) cu o precizie de 0.001
		Precizie de 10^-x = |rezultatul vostru - rezultatul corect| <= 10^-x
		*/
		double left = 0;
		double right = n;
		double mid;

		int step = 100;

		if(n<1) right = 1.0;

		while(step--) {
            mid = left + (right-left)/2;
            if(fabs(n-mid*mid)<1e-3) return mid;
            if(n<mid*mid) {
                right=mid;
            }
            else {
                left = mid;
            }
		}
		return 0.0;
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
