#include<iostream>
#include<queue>
#include<vector>
#define MAX 100005
#define MOD 998244353
 
using namespace std;
 
struct Nodo{
	long long int fat;
	vector<long long int> sons;
}arbol[MAX];
 
bool visit[MAX];
long long int dis[MAX];
long long int n,c=0;
long long int x;
 
queue<long long int> nodos;
 
void bpa(){
	long long int x,s,f;
	while(!nodos.empty()){
		x=nodos.front(), nodos.pop();
		f=arbol[x].fat;
		if(f && !visit[f]){
			visit[f]=true;
			c+=dis[f]=dis[x]+1;
			nodos.push(f);
		}
		
		while(!arbol[x].sons.empty()){
			s=arbol[x].sons.back(), arbol[x].sons.pop_back();
			if(!visit[s]){
				visit[s]=true;
				c+=dis[s]=dis[x]+1;
				nodos.push(s);
			}
		}
	}
}
 
long long int mcdExt(long long int a, long long int b){
	long long int r,y=0,x1=0,y1=1,tx,ty;
	x=1;
	while(b>0){
		r=a%b;
		tx=x1, ty=y1;
		x1=x-(a/b)*x1;
		x=tx;
		y1=y-(a/b)*y1;
		y=ty;
		a=b;
		b=r;
	}
	return a;
}
 
int main(){
	long long int ax,mcd,res;
	scanf("%lld",&n);
	for(long long int k=2; k<=n; k++){
		scanf("%lld",&ax);
		arbol[ax].sons.push_back(k);
		arbol[k].fat=ax;
		visit[ax]=true;
	}
	
	for(long long int k=1; k<=n; k++){
		if(!visit[k]){
			nodos.push(k);
			dis[k]=1;
			c++;
		}
		visit[k]= !visit[k];
	}
	bpa();
	//printf("%lld\n",c);
	mcd = mcdExt(n, c);
	n/=mcd, c/=mcd;
	//printf("%lld %lld\n",c,n);
	mcdExt(n,MOD);
	x=(x%MOD +MOD)%MOD;
	//printf("%lld\n",x);
	res=((c%MOD)*(x%MOD))%MOD;
	printf("%lld\n",res);
}

