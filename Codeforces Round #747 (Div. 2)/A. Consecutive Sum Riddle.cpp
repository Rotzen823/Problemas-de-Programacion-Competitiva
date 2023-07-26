#include<iostream>
typedef long long ll;

using namespace std;

int main(){
	ll n,num,l,r;
	cin>>n;
	while(n--){
		cin>>num;
		r=num;
		l=(-num)+1;
		cout<<l<<" "<<r<<"\n";
	}
}

