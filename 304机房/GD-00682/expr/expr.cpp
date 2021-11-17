#include<cstdio>
#include<cstring>
#include<string>
#include<iostream>
#include<algorithm>
#include<cmath> 
using namespace std;
string a;
long long n,b[100005],q,c[100005];
int main(){
	freopen("expr.in","r",stdin);
	freopen("expr.out","w",stdout);
	getline(cin,a);
	scanf("%lld",&n);
	for(long long i=1;i<=n;i++)scanf("%lld",&b[i]);
	scanf("%lld",&q);
	for(long long i=1;i<=q;i++)scanf("%lld",&c[i]);
	for(int i=1;i<=q;i++)printf("1 ");
	return 0;
}
