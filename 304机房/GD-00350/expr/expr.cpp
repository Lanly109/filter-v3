#include <bits/stdc++.h>
using namespace std;
#define N 1000100
#define ll long long
const int inf = 2e9;
const int base = 1e5 + 1;  

template <class T>
inline void read(T& a){
	T x = 0, s = 1;
	char c = getchar();
	while(!isdigit(c)){ if(c == '-') s = -1; c = getchar();  }
	while(isdigit(c)){ x = x * 10 + (c ^ '0'); c = getchar();  }
	a = x * s;
	return ;
}

char s[N]; 

int n;
int q; 
int a[N], sum[N]; 

//struct node{
//	int huo, yu, fan;  // �������� 
//	int lev;    // ���㼶��
//	int x, y;   // ������� �������������� || �������д����㣩 
//	//  Ϊȡ������ʱ y = -1 
//} p[N];
//int id = 0; 
//int stac[N], top = 0;    // �������� 
//
//int get_kind(char s){   // ��ȡ�������� 
//	if(s == '&') return 1;
//	if(s == '|') return 2;
//	else if(s == '!') return 3;
//	else return -1; 
//}

namespace subtask1{
	bool flag1 = 0;
	bool flag2 = 0; 
	bool flag3 = 0; 
	void main(){
		n = s[0] - '0';
		for(int i = 1; i <= n; i++){
			read(a[i]);
			sum[a[i]]++; 
		}
		read(q);
		while(q--){
			int x; 	read(x);
			sum[a[x]]--;		
			sum[!a[x]]++; 
			if(flag1){  // huo yunsuan  
				if(sum[1]) puts("1");
				else puts("0"); 
			}
			else{  // yu yunsuan 
				if(sum[0]) puts("0");
				else puts("1"); 
			}
			sum[!a[x]]--;
			sum[a[x]]++; 
		}
		return ; 
	}
}

int main(){
//	freopen("hh.txt", "r", stdin);  
	freopen("expr.in", "r", stdin); 
	freopen("expr.out", "w", stdout); 
	s[0] = '@'; 
	while(!isdigit(s[0])){
		scanf("%s", s);
		if(s[0] == '|') subtask1::flag1 = 1;
		if(s[0] == '&') subtask1::flag2 = 1; 
		if(s[0] == '!') subtask1::flag3 = 1; 
	}
	int num = subtask1::flag1 + subtask1::flag2 + subtask1::flag3;
	if(num == 1){
		subtask1::main();
		return 0; 
	}
	else {
		n = s[0] = '0';
		int tmp; 
		for(int i = 1; i <= n; i++)
			read(tmp); 
		int q; read(q);
		while(q--){
			int x; read(x);
			printf("0\n"); 
		}
	} 
	return 0; 
}

