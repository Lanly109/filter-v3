#include <cstdio>
using namespace std;
int max(int a,int b){
	return a > b ? a : b;
}
int main()
{
	freopen("live.in","r",stdin);
	freopen("live.out","w",stdout);
	int n,w;
	int a[100000] = {0};
	scanf("%d %d",&n,&w);
	for(int i = 1; i<=n;i++)
	{
		scanf("%d",&(a[i]));
		int tmp = a[i];
		int j = i - 1;
		while(j != 0 && a[j] < tmp)
		{
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = tmp;
		int p = i * w / 100;
		p  = max(1,p);
		int s = a[p];
		while(s == a[p + 1])
		{
			p++;
		}
		printf("%d ",s);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
	
	
	
}
