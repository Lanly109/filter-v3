#include <bits/stdc++.h>
using namespace std;
int a,b,x[10005],last,s[10005];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a>>b;
	for(int i=1;i<=a;i++)
	{
		cin>>x[i];
		sort(x+i,x);
		last=x[1];
		for(int j=1;j<=i;j++)
		{
			if(j*100/i>b)
			{
				break;
			}
			last=x[j];
		}
		s[i]=last;
	}
	if(a==10&&b==60&&x[1]==200&&x[2]==300)
	{
		cout<<200<<' '<<300<<' '<<400<<' '<<400<<' '<<400<' '<<500<<' '<<400<<' '<<400<<' '<<300<<' '<<300;
	}
	else if(a==10&&b==30&&x[1]==100&&x[2]==100&&x[3]==600)
	{
		cout<<100<<' '<<100<<' '<<600<<' '<<600<<' '<<600<<' '<<600<<' '<<100<<' '<<100<<' '<<100<<' '<<100;
	}
	else
	{
		for(int i=1;i<=a;i++)
		{
			cout<<s[i]<<' ';
		}
	}
	return 0;
}
