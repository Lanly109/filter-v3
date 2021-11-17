#include <cstdio>
using namespace std;
int main()
{
	freopen("power.in","r",stdin);
	freopen("power.out","w",stdout);
	int x;
	scanf("%d",&x);
	//10000000
	if(x % 2){
	    printf("-1");
	    return 0;
	}
	int i;
	for(i = 2; i <= x; i *= 2)
	{
		
	}
	while(x > 0){
		if(x >= i){
			x -= i;
			printf("%d ",i);
		}
		i /= 2;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
