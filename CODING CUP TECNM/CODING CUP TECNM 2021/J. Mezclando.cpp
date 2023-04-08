#include<bits/stdc++.h>
#define MAX 505

using namespace std;

int num[MAX];
int num2[MAX];
char op[10], op2[10];


int main(){
	int n;
	cin>>n;
	for(int k=0; k<n; k++){
		cin>>num[k];
	}
	int m;
	cin>>m;
	for(int k=0; k<m; k++){
		cin>>num2[k];
	}
	
	cin>>op>>op2;
	if(op[0]=='i' && op2[0]=='i'){
		for(int k=0,j=0; k<n || j<m; k++, j++){
			if(k<n){
				cout<<num[k]<<"\n";
			}
			if(j<m){
				cout<<num2[j]<<"\n";
			}
		}
	}
	else if(op[0]=='f' && op2[0]=='f'){
		for(int k=n-1,j=m-1; k>=0 || j>=0; k--, j--){
			if(k>=0){
				cout<<num[k]<<"\n";
			}
			if(j>=0){
				cout<<num2[j]<<"\n";
			}
		}
	}
	else if(op[0]=='i' && op2[0]=='f'){
		for(int k=0, j=m-1; k<n || j>=0; k++, j--){
			if(k<n){
				cout<<num[k]<<"\n";
			}
			if(j>=0){
				cout<<num2[j]<<"\n";
			}
		}
	}
	else{
		for(int k=n-1, j=0; k>=0 || j<m; k--, j++){
			if(k>=0){
				cout<<num[k]<<"\n";
			}
			if(j<m){
				cout<<num2[j]<<"\n";
			}
		}
	}
	
	return 0;
}
