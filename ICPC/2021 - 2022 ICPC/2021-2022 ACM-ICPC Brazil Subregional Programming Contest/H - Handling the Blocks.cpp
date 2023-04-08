#include<bits/stdc++.h>
#define MAX 100005

using namespace std;

int num[MAX][2];

int main(){
	int n,c;
	cin>>n>>c;
	for(int k=0; k<n; k++){
		cin>>num[k][0]>>num[k][1];
	}
	for(int k=0; k<n; k++){
		if(num[k][0]!=k+1 && num[k][1]!=num[num[k][0]-1][1]){
			cout<<"N\n";
			return 0;
		}
	}
	cout<<"Y\n";
	return 0;
}
