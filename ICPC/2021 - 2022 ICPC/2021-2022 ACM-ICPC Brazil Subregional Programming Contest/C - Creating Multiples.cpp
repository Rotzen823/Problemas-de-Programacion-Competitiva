#include<bits/stdc++.h>
#define MAX 200005

using namespace std;

int num[MAX];

int main(){
	int b,n,sum=0,lim1,lim2;
	cin>>b>>n;
	for(int k=0; k<n; k++){
		cin>>num[k];
		if(k%2==0){
			sum+=num[k];
		}
		else{
			sum-=num[k];
		}
	}
	if(sum%(b+1)==0){
		cout<<"0 0\n";
		return 0;
	}
	if(sum>0){
		lim1 = sum%(b+1);
		lim2 = (b+1)-lim1;
	}
	else{
		sum=-sum;
		lim2 = sum%(b+1);
		lim1 = (b+1)-lim2;
	}
	for(int k=0; k<n; k++){
		if(k%2==0){
			if(num[k]>=lim1){
				cout<<k+1<<" "<<num[k]-lim1<<"\n";
				return 0;
			}
		}
		else{
			if(num[k]>=lim2){
				cout<<k+1<<" "<<num[k]-lim2<<"\n";
				return 0;
			}
		}
	}
	cout<<"-1 -1\n";
	return 0;
}
