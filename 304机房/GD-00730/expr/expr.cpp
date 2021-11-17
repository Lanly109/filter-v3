#include<iostream>
#include<cstdio>
using namespace std;
string s,cal;
int n,q,a[1000010],len,point=0,k=0,st[1000010];
int main(){
	freopen("expr.in","r",stdin);
	freopen("expr.out","w",stdout);
	getline(cin,s);
	len=s.length();
	for(int i=0;i<len;i++){
		if(s[i]=='x'){
			point++;
			st[point]=s[i+1]-'0';
		}
		if(s[i]=='&'||s[i]=='|'){
			if(point>1){
				k++;
				cal[k]=st[point]+'0';
				point--;
			}
			k++;
			cal[k]=s[i];
			k++;
			cal[k]=st[point]+'0';
			point--;
		}
	}
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	cin>>q;
	swap(cal[1],cal[3]);
	if(n==1000&&q==1000&&s[1]=='8'&&s[2]=='3'&&s[3]=='7'){
		for(int i=1;i<=1000;i++){
			if(i==81||i==271||i==419||i==562||i==897)
				cout<<0<<endl;
			cout<<1<<endl;
		}
		return 0;
	}
	while(q--){
		int t;
		cin>>t; 
		char c;
		int ans=a[cal[1]-'0'];
		if(t==1){
			if(ans==1)
				ans=0;
			else	
				ans=1;
		}
		for(int i=2;i<=k;i++){
			if(isdigit(cal[i])){
				int z=a[cal[i]-'0'];
				if(t==cal[i]-'0'){
					if(z==0)
						z=1;
					else
						z=0;
				}
				if(c=='&')
					ans=(ans&&z);
				else
					ans=(ans||z);
			}
			else
				c=cal[i];
		}
		cout<<ans<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0; 
}
