#include<bits/stdc++.h>
#define MAX 10005

using namespace std;

int step[MAX],a,b,n;
bool visit[MAX];
queue <int> cola;

void bus(){
	int x,ax;
	while(!cola.empty()){
		x=cola.front(), cola.pop();
		ax=x*a;
		if(ax>9999) ax=1;
		if(ax==n){
			visit[ax]=true;
			step[ax]=step[x]+1;
			break;
		}
		else if(!visit[ax]){
			visit[ax]=true;
			step[ax]=step[x]+1;
			cola.push(ax);
		}
		ax=x/b;
		if(ax==n){
			visit[ax]=true;
			step[ax]=step[x]+1;
			break;
		}
		else if(!visit[ax]){
			visit[ax]=true;
			step[ax]=step[x]+1;
			cola.push(ax);
		}
	}
}

int main(){
	cin>>a>>b>>n;
	visit[0]=visit[1]=true;
	cola.push(1);
	bus();
	cout<<step[n]<<"\n";
}
