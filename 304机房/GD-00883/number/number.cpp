#include <cstdio>
#include <queue>
//#include <cstring>
//#include <bits/stdc++.h>
using namespace std;
int a[1003][1003];
bool b[1003][1003];
int r[1003][1003];
queue<int> q[3];
int n,m;
int max(int a, int b){
	return a > b ? a : b;
}
int search(int x,int y){
	if(x < 1 || y < 1 || x > n || y > m || b[x][y]) return 0;
	q[1].push(x);
	q[2].push(y - 1);
	q[1].push(x);
	q[2].push(y+1);
	q[1].push(x + 1);
	q[2].push(y);
	b[x][y] = 1;
	search(x,y-1);
	search(x,y+1);
	search(x - 1, y);
	b[x][y] = 0;
	//if(r[x][y] != -11111111) return r[x][y];
	//r[x][y] = max(max(r[x][y - 1],r[x][y + 1]),r[x - 1][y]) + a[x][y];
	return 0;
}
int find(int x, int y)
{
	return r[x][y];
}
int found(){
	while(!(q[1].empty())){
	
	int x = q[1].front(), y = q[2].front();
	r[x][y] = max(max(find(x, y + 1),find(x,y - 1)),find(x - 1,y));
	q[1].pop();q[2].pop();
}
}
int main()
{
	for(int i = 0; i<=1002; i++){
		for(int j = 0; j <= 1002; j++){
			a[i][j] = -11111111;
			r[i][j] = -11111111;
		}
	}

	scanf("%d %d",&n,&m);
	for(int i = 1; i<= n; i++){
		for(int j = 1; j<= m; j++){
			scanf("%d",&a[i][j]);
		}
		r[i][1] = a[i][1];
	}
	
	/*for(int i = 1; i<= n; i++){
		for(int j = 1; j<= m; j++){
			printf("%d ",a[i][j]);
		}
		printf("\n");
	}*/
	search(1,1);
	found();
	printf("9");
	
}
