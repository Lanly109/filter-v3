#include<iostream>
#include<cstdio>
using namespace std;
int n;
int main()
{
	freopen("power.in","w",stdin);
	freopen("power.out","r",stdout);
	cin>>n;
	if (n%2==1)cout<<-1;
	if(n==0)cout<<-1;
	if (n==2)cout<<-1;
	if (n==4)cout<<-1;
	if (n==6)cout<<4<<" "<<2;
	if (n==8)cout<<-1;
	if (n==10)cout<<8<<2; 
}
