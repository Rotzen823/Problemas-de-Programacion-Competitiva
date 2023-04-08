#include<bits/stdc++.h>
#define MAX 1005

using namespace std;

int num[MAX];


int main(){
	int n;
	cin>>n;
	for(int k=0; k<n; k++){
		cin>>num[k];
	}
	int a=1;
	for(int k=1; k<n; k++){
		if(num[k-1]+1!=num[k]){
			a=k+1;
			break;
		}
	}
	int b=1;
	for(int k=n-2; k>=0; k--){
		if(num[k+1]-1!=num[k]){
			b=n-k;
			break;
		}
	}
	if(a!=1){
		cout<<a<<"\n"<<b<<"\n";
	}
	else{
		cout<<"OK\n";
	}
	return 0;
}
