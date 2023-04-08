#include<bits/stdc++.h>
#define MAX 100005

using namespace std;

struct nodo{
	vector <int> s;
	bool die;
}arbol[MAX];

bool visit[MAX];

int bus(int n){
	if(!arbol[n].die){
		return n;
	}
	visit[n]=true;
	int lar = arbol[n].s.size();
	int op;
	for(int k=0; k<lar; k++){
		if(!visit[arbol[n].s[k]]){
			op=bus(arbol[n].s[k]);
			if(op!=-1){
				visit[n]=false;
				return op;
			}
		}
	}
	return -1;
}

int main(){
	int n,t,d,c=1,r;
	cin>>n;
	while(n--){
		cin>>t>>d;
		if(t==1){
			c++;
			arbol[d].s.push_back(c);
		}
		else{
			arbol[d].die=true;
			r=bus(1);
			cout<<r<<"\n";
		}
	}
	return 0;
}

