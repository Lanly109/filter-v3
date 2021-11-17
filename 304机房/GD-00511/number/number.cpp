#include<bits/stdc++.h>
using namespace std;
int n,m,arr[1010][1010];
long long maxn=-10010; 
struct point{
	int cnt;
	int x,y;
	bool visit[820][820];
};
void BFS(){
	point start;
	start.cnt=arr[1][1]; start.x=start.y=1;
	memset(start.visit,false,sizeof(start.visit));
	start.visit[1][1]=true;
	queue<point> q;
	while(!q.empty()) q.pop();
	q.push(start);
	while(!q.empty()){
		point now=q.front(); q.pop();
		int move[3][2]={{0,-1},{0,1},{1,0}};
		if(now.x==m&&now.y==n){
			if(now.cnt>maxn) maxn=now.cnt;
			if(!q.empty()){
				now=q.front();
				q.pop(); 
			} 
			else return;
		} 
		for(int i=0;i<=2;++i){
			point next=now;
			next.x+=move[i][0];
			next.y+=move[i][1];
			if(next.x>=1&&next.x<=m&&next.y>=1&&next.y<=n&&!next.visit[next.y][next.x]){
				next.visit[next.y][next.x]=true;
				next.cnt+=arr[next.y][next.x];
				//cout<<"next: "<<next.x<<" "<<next.y<<" "<<next.cnt<<endl<<"now :"<<now.x<<" "<<now.y<<" "<<now.cnt<<endl;
				q.push(next);
			}
		}
	}
}
inline void Read(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
}
inline void Close(){
	fclose(stdin);
	fclose(stdout);
}
int main(){
	Read();
	memset(arr,0,sizeof(arr));
	cin>>n>>m;
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			cin>>arr[i][j];
	BFS();
	cout<<maxn;
	Close();
	return 0;
} 
