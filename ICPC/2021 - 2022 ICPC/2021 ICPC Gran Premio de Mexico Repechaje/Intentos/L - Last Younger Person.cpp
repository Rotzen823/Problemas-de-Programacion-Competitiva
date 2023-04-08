#include<bits/stdc++.h>
#define MAX 500005

using namespace std;

typedef long long ll;

string nom[MAX];
ll edad[MAX];
ll pers[MAX];

int main(){
	ll n, men, a, m, d, ax;
	char aux;
	cin>>n;
	cin>>nom[1];
	cin>>a>>aux>>m>>aux>>d;
	edad[1] = a*10000 + m*100 + d; 
	
	for(int k=2; k<=n; k++){
		cin>>nom[k];
		cin>>a>>aux>>m>>aux>>d;
		edad[k] = a*10000 + m*100 + d; 
		if(edad[k-1] < edad[k]){
			pers[k] = k-1;
		}
		else{
			pers[k] = pers[k-1];
		}
	}
	
	ll mi,id;
	cin>>mi;
	while(mi--){
		cin>>id;
		cout<<"At place #"<<id<<", ";
		if(pers[id] == 0){
			cout<<"no one younger arrived before "<<nom[id]<<"\n";
		}
		else{
			cout<<"the last younger person to arrive before "<<nom[id]<<" is "<<nom[pers[id]]<<"(#"<<pers[id]<<")\n";
		}
	}
	
	return 0;
}
