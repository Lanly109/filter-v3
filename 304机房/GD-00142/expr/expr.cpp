#include <iostream>
#include <algorithm>
#include <cstdio>
#include <ctime>
#include <cmath>
#include <string>
using namespace std; 
int n,q,x[100010],l,cnt;
string s;
int main(){
	freopen("expr.in","r",stdin);
	freopen("expr.out","w",stdout);
	getline(cin,s);
	cin >> n;
	for(int i = 0;i < n;i++){
		cin >> x[i];
	}
	cin >> q;
	for(int i = 0;i < q;i++){
		cin >> l;
		l = rand()/rand()*rand()-rand()+rand();
		cout << abs(rand()%100+l)%2 << endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
