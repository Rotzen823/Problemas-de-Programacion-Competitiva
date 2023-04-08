#include<stdio.h>
#define MAX 365
 
int dan[MAX];
bool exist[MAX];
bool visit[MAX];
int rel[MAX][2];
 
int bus(int v){
	if(visit[v]) return 0;
	int c=1,a,d;
	a=rel[v][0];
	d=rel[v][1];
	visit[v]=true;
 
	if(a!=-1){
		rel[v][0]=rel[a][1]=-1;
		c+=bus(a);
	}
	if(d!=-1){
		rel[v][1]=rel[d][0]=-1;
		c+=bus(d);
	}
	
	return c;
}
 
int main(){
	int n,par,v,res=0,ax=0,sum=0;
	scanf("%d",&n);
	for(int k=0; k<n; k++){
		scanf("%d",&v);
		dan[k]=v;
		rel[v][0]=rel[v][1]=-1;
		exist[v]=true;
	}
	for(int dis=1; dis<=359; dis++){
		//crear el 'grafo'
		for(int k=0; k<360; k++) visit[k]=false;
		for(int k=0; k<n; k++){
			v=dan[k];
			par=(v+dis)%360;
			if(exist[par]){
				rel[v][1]=par;
				rel[par][0]=v;
			}
		}
		//contar
		sum=0;
		for(int k=0; k<n; k++){
			v=dan[k];
			ax=bus(v);
			sum+=(ax/2);
		}
		if(sum>res) res=sum;
	}
	printf("%d\n",res);
}
