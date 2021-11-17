#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
using namespace std;
int n,w,score,line;
priority_queue<int> q;
queue<int>q2;
int main()
{
	freopen("live.in","r",stdin);
	freopen("live.out","w",stdout);
	scanf("%d%d",&n,&w);
	for(int i=1;i<=n;i++){
		scanf("%d",&score);
		q.push(score);
		if(i*w/100<1){
			printf("%d ",q.top());
			line=q.top();
		}
		else if(score==line) printf("%d ",line);
		else if(score<line&&(i*w/100==(i-1)*w/100)) printf("%d ",line);
		else{
			for(int j=1;j<i*w/100;j++){
				q2.push(q.top());
				q.pop();
			}
			line=q.top();
			printf("%d ",q.top());
			while(!q2.empty()){
				q.push(q2.front());
				q2.pop();
			}
		}
	}
	fclose(stdin);fclose(stdout);
	
	return 0;
} 
