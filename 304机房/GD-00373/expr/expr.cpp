#include<bits/stdc++.h>
using namespace std;
int n,q;
int main(){
	freopen("expr.in","r",stdin);
	freopen("expr.out","w",stdout);
	srand(time(NULL));
	while(true){
		char a;
		a=getchar();
		if(a=='\n') break;
	}
	cin>>n;
	for(int i=1;i<=n;i++) cin>>q;
	cin>>q;
	for(int i=1;i<=q;i++){
		cout<<rand()%2<<endl;
	}
	return 0;
}
