#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std; 
int p,w,r[610],a,temp,s;
int main(){
	freopen("live.in","r",stdin);
	freopen("live.out","w",stdout);
	cin >> p >> w;
	for(int i = 1;i <= p;i++){
		cin >> a;
		r[a]++;
		temp = 0;
		s = max(1,i*w/100);
		for(int j = 600;j >= 0;j--){
			temp += r[j];
			if(temp>=s){
				cout << j << ' ';
				break;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
