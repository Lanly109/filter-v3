#include<bits/stdc++.h> 
using namespace std;
	int x[10000000];
int main()
{
	//freopen ("power.in","r",stdin);
	//freopen ("power.out","w",stdout);
	int a,i=1,j=2;
	cin>>a;
	if(a%2==0)
	{
		x[0]=0;
		while(a>0)
		{
			//cout<<1<<endl;
			//cout<<j<<endl;
			if((a/j)%2==1)
			{
				x[i-1]=1;
				a=a-j;
				//cout<<0<<endl;
			}
			else
			{
				x[i-1]=0;
				//cout<<1<<endl; 
				//cout<<a<<endl;
				//cout<<j<<endl;
			}
			//cout<<a<<" "<<i<<endl;
			j=j*2;
			if(a>0)
			{
				i++;
			}
		}
		int m=pow(2,i);
		for(int n=i;n>=0;n-- )
		{
			if(x[n]==1)
			{
				cout<<m*2<<" ";
			//	cout<<n<<endl; 
			}
		//	cout<<x[n]<<endl;
			//cout<<x[n]<<" "<<n<<" "<<m<<" "<<endl;
			m=m/2;
				
		}
	}
	else
	{
		cout<<-1;
	}
	return 0;
}
