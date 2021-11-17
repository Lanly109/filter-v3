#include<bits/stdc++.h>
using namespace std;
string s;
int n,a[100005],q,f,d[100005],sum;
struct node{
	int l,r,num,tr,fan;
}tree[2000005];
void build(int x,int l,int r){
	tree[x].l=l;
	tree[x].r=r;
	tree[x].num=0;
	tree[x].tr=0;
	tree[x].fan=0;
	if(l<r){
		build(x*2,l,(l+r)/2);
		build(x*2+1,(l+r)/2+1,r);
	}
}
void update(int x){
	if(tree[x].tr){
		int p=x*2,o=tree[x].tr;
		tree[p].num=o-1;
		tree[p].tr=o;
		p++;
		tree[p].num=o-1;
		tree[p].tr=o;
	}
	if(tree[x].fan){
		int p=x*2;
		tree[p].num^=1;
		tree[p].fan=1;
		p++;
		tree[p].num^=1;
		tree[p].fan=1;
	}
}
void change(int x,int l,int r,int sum){
	if(tree[x].l>=l&&tree[x].r<=r){
		tree[x].num=sum;
		tree[x].tr=sum+1;
		tree[x].fan=0;
	}
	else{
		update(x);
		if((tree[x].l+tree[x].r)/2>=l) change(x*2,l,r,sum);
		if(r>(tree[x].l+tree[x].r)/2) change(x*2+1,l,r,sum);
	}
}
void reve(int x,int l,int r){
	if(tree[x].l>=l&&tree[x].r<=r){
		tree[x].num^=1;
		tree[x].fan^=1;
	}
	else{
		update(x);
		if((tree[x].l+tree[x].r)/2>=l) reve(x*2,l,r);
		if(r>(tree[x].l+tree[x].r)/2) reve(x*2+1,l,r);
	}
}
int query(int x,int l){
	if(tree[x].l==l&&tree[x].r==l) return tree[x].num;
	else{
		update(x);
		if((tree[x].l+tree[x].r)/2>=l) return query(x*2,l);
		else if(l>(tree[x].l+tree[x].r)/2) return query(x*2+1,l);
	}
}
int main(){
	freopen("expr.in","r",stdin);
	freopen("expr.out","w",stdout);
	getline(cin,s);
	cin>>n;
	for(int i=1;i<=n;i++) scanf("%d",a+i);
	build(1,1,n);
	stack<int> st,ed,num;
	for(int i=0;i<s.size();i++){
		if(s[i]==' ') continue;
		if(s[i]=='x'){
			i++;
			d[s[i]-'0']=++sum;
			change(1,sum,sum,!a[s[i]-'0']);
			st.push(sum);
			ed.push(sum);
			num.push(a[s[i]-'0']);
		}
		else if(s[i]=='!'){
			reve(1,st.top(),ed.top());
		}
		else if(s[i]=='|'){
			int x=st.top(),y=ed.top(),z=num.top();
			st.pop();ed.pop();num.pop();
			if(num.top()) change(1,x,y,1);
			if(z) change(1,st.top(),ed.top(),1);
			x=st.top();
			z=z|num.top();
			st.pop();ed.pop();num.pop();
			st.push(x);ed.push(y);num.push(z);
		}
		else{
			int x=st.top(),y=ed.top(),z=num.top();
			st.pop();ed.pop();num.pop();
			if(!num.top()) change(1,x,y,0);
			if(!z) change(1,st.top(),ed.top(),0);
			x=st.top();
			z=z&num.top();
			st.pop();ed.pop();num.pop();
			st.push(x);ed.push(y);num.push(z);
		}
	}
	cin>>q;
	while(q--){
		scanf("%d",&f);
		printf("%d\n",query(1,d[f]));
	}
	return 0;
}
