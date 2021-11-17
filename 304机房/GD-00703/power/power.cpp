#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main() {
	ifstream ifs("power.in");
	ofstream ofs("power.out");
	int n;
	ifs >> n;
	if(n % 2 == 1) {
		ofs << -1 << endl;
		return 0;
	}
	int m = 1;
	while(m <= n) {
		m *= 2;
	}
	m /= 2;
	bool flag = false;
	vector<int> num;
	while(m > 1) {
		n -= m;
		num.push_back(m);
		if(n == 0) {
			flag = true;
			break;
		}
		while(m > n) {
			m /= 2;
		}
	}
	if(flag) {
		for(int i = 0; i < num.size(); i++) {
			ofs << num[i] << " ";
		}
		ofs << endl;
	}
	else {
		ofs << -1 << endl;
	}
	return 0;
} 
