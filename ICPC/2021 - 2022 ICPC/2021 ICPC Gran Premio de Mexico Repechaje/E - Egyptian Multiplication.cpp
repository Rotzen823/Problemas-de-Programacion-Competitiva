#include<bits/stdc++.h>
#define MAX 1000

using namespace std;

typedef long long ll;

ll nums[MAX];
ll c;

void multi(ll a, ll b){
	ll r, pot = 1;
	if(a == 0 || b == 0){
		nums[c++] = 0;
		return;
	}
	while(a>0){
		r = a % 2;
		if(r == 1){
			nums[c++] = pot * b;
		}
		pot *= 2;
		a/=2;
	}
}

int main(){
	ll n,m;
	char op;
	for(ll i=1; ; i++){
		cin>>n;
		if(n == -1) break;
		c = 0;
		cin>>m;
		cin>>op;
		multi(n, m);
		cout<<"Case "<<i<<": "<<n<<" x "<<m<<" = ";
		if(op == 'u'){
			cout << nums[0];
			for(int k=1; k<c; k++){
				cout << " + "<<nums[k];
			}
			cout<<"\n";
		}
		else{
			cout << nums[c-1];
			for(int k=c-2; k>=0; k--){
				cout << " + "<<nums[k];
			}
			cout<<"\n";
		}
	}
	return 0;
}
