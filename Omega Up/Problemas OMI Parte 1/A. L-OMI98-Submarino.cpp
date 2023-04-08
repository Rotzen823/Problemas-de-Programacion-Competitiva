#include<bits/stdc++.h>
#define MAX 105

using namespace std;

queue <int> rel[MAX];
queue <int> cola;
int tim[MAX];
int n,e,t,c=0;

void bus(){
	int x,v;
	while(!cola.empty()){
		x=cola.front(), cola.pop();
		if(tim[x]<t){
			while(!rel[x].empty()){
				v=rel[x].front(), rel[x].pop();
				if(!tim[v]){
					tim[v]=tim[x]+1;
					cola.push(v);
					c++;
				}
			}	
		}
	}
}

int main(){
	int a,b;
	cin>>n>>e>>t;
	while(e--){
		cin>>a>>b;
		rel[a].push(b);
		rel[b].push(a);
	}
	tim[n]=1;
	cola.push(n);
	bus();
	cout<<c<<"\n";
}
