#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std; 
int n,a[30],temp = 0;
int main(){
	freopen("power.in","r",stdin);
	freopen("power.out","w",stdout);
	cin >> n;
	if(n%2){
		cout << -1;
		return 0;
	}
	n/=2;
	for(int i = 1;n;i++){
		if(n%2){
			temp++;
			a[temp] = i;
		} 
		n/=2;
	}
	for(int i = temp;i > 0;i--){
		cout << pow(2,a[i]) << ' ';
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
