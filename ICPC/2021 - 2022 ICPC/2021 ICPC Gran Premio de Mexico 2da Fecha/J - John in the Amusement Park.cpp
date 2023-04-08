#include<bits/stdc++.h>
#define MAX 1000005
#define MAXA 5005

using namespace std;

int T[MAX],t,c=0;
bool visit[MAX];

typedef struct{
	int h;
	int d;
	int x;
}act;

act DIV[MAXA];

void qs(int limz, int limd){
	int izq=limz, der=limd, pivot=DIV[(izq+der)/2].x;
	act temp;
	do{
		while(DIV[izq].x<pivot && izq<limd) izq++;
		while(DIV[der].x>pivot && der>limz) der--;
		if(izq<=der){
			temp=DIV[izq];
			DIV[izq] = DIV[der];
			DIV[der] = temp;
			izq++,der--;
		}
	}while(izq<=der);
	if(izq<limd) qs(izq,limd);
	if(der>limz) qs(limz,der);
}

int hap(int tim){
	if(visit[tim]) return T[tim];
	int max=0,sum;
	for(int k=0; k<c; k++){
		if(DIV[k].x==tim){
			sum=hap(tim+DIV[k].d) + DIV[k].h;
			if(sum>max) max=sum;
		}
		else if(DIV[k].x>tim){
			sum=hap(DIV[k].x);
			if(sum>max) max=sum;
		}
	}
	visit[tim]=true;
	T[tim]=max;
	return max;
}
 
int main(){
	int n,h,d,x,m,res;
	cin>>n>>t;
	while(n--){
		cin>>h>>d>>x;
		while(x--){
			cin>>m;
			DIV[c].h=h;
			DIV[c].d=d;
			DIV[c++].x=m;
		}
	}
	qs(0,c-1);
	res=hap(0);
	cout<<res<<"\n";
}
