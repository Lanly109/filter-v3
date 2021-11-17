#include <iostream>
#include <fstream>
#include <map>
#include <set>

using namespace std;

set<int> stype;
map<int, int> score;
int maxnum(int a, int b) {
	return a > b ? a : b;
}
int main() {
	ifstream ifs("live.in");
	ofstream ofs("live.out");
	int n, w;
	ifs >> n >> w;
	int max = -1;
	for(int i = 1; i <= n; i++) {
		int cur, pn;
		ifs >> cur;
		pn = maxnum(1, (int)(i * w / 100));
		stype.insert(cur);
		score[cur]++;
		int cpn = 0;
		set<int>::reverse_iterator it = stype.rbegin();
		while(it != stype.rend() && cpn < pn) {
			cpn += score[*it];
			it++;
		}
		it--;
		ofs << *it << " ";
	}
	return 0;
}
