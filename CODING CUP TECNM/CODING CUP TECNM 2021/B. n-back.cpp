#include<bits/stdc++.h>
#define MAX 1005
#define MAXS 10005

using namespace std;

int num[MAX];
char arr[MAXS];

int main(){
	int n,c=0,ax,sum,x=0,con=0;
	char let;
	cin>>n;
	scanf("%c",&let);
	gets(arr);
	while(arr[c]!='\0'){
		let=arr[c++];
		sum=let-'0';
		let=arr[c++];
		while(let!=' ' && let!='\0'){
			ax=let-'0';
			sum*=10;
			sum+=ax;
			let=arr[c++];
		}
		num[x++]=sum;
	}
	
	for(int k=n; k<x; k++){
		if(num[k]==num[k-n]) con++;
	}
	cout<<con<<"\n";
	return 0;
}
