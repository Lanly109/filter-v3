#include <cstdio>
#include <string>
#include <cmath>
#include <iostream>
#include <algorithm> 
using namespace std;

int tree[5000000]={0};/*-3 for |,-2 for &,-1 for !, numbers for vals*/
bool vals[100000];
int nst=0;
int parent(int index){
	return index/2;
}
bool isfull(int index){
	if(tree[index]>0){
		return true;
	}else{
		if(tree[index]==-1){
			return tree[index*2+1];
		}else{
			return tree[index*2] && tree[index*2+1];
		}
	}
}
void placeitem(int item){
	if(item){
		if(nst==0){
			nst=1;
			tree[1]=item;
		}else{
			while(isfull(nst)){
			 	nst=parent(nst);
			}
			//printf("%d %d\n",nst,item);
			if(!tree[nst*2+1]){
				nst=nst*2+1;
				tree[nst]=item;
			}else{
				nst*=2;
				tree[nst]=item;
				
			}
		}
	}
}
int inter(string s){
	if(s[0]=='x'){
		int cnt=0;
		for(int i=1;i<s.length();i++){
			cnt=cnt*10+s[i]-'0';
		}
		return cnt;
	}else{
		if(s[0]=='|'){
			return -3;
		}else if(s[0]=='!'){
			return -1;
		}else if(s[0]=='&'){
			return -2;
		}else{
			return 0;
		}
	}
}
bool calc(int index){
	if(tree[index]>0){
		//printf("%d\n",vals[tree[index]]);
		return vals[tree[index]];
	}else if(tree[index]==-1){
		//printf("%d\n",!calc(index*2+1));
		return !calc(index*2+1);
	}else if(tree[index]==-2){
		//printf("%d\n",calc(index*2)&&calc(index*2+1));
		return calc(index*2)&&calc(index*2+1);
	}else if(tree[index]==-3){
		//printf("%d\n",calc(index*2)||calc(index*2+1));
		return calc(index*2)||calc(index*2+1);
	}
}
int tonum(string s){
	int cnt=0;
	for(int i=0;i<s.length();i++){
		cnt=cnt*10+s[i]-'0';
	}
	return cnt;
}
int main(){
	freopen("expr.in","r",stdin);
	freopen("expr.out","w",stdout);
	string s[100000];
	int cnt=0,n,q,tmp;
	while(cin >> s[++cnt]){
		if('0'<=s[cnt][0] && s[cnt][0]<='9'){
			break;
		}
	}
	n=tonum(s[cnt--]);
	for(int i=cnt;i>=1;i--){
		placeitem(inter(s[i]));
	}
	//printf("%d",n);
	for(int i=1;i<=n;i++){
		scanf("%d",&vals[i]);
	}
	
	/*for(int i=1;i<=100;i++){
		printf("%d\n",tree[i]);
	}
	printf("---------------");*/
	scanf("%d",&q);
	for(int i=1;i<=q;i++){
		scanf("%d",&tmp);
		vals[tmp]=!vals[tmp];
		printf("%d\n",calc(1));
		vals[tmp]=!vals[tmp];
	}
	return 0;
}
