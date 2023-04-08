#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,c,sum,max,d;
	cin>>n;
	for(int k=1; k<=n; k++){
		cin>>c; 
		cin>>d;
		sum = d;
		max = d;
		if(sum < 0) {
			sum = 0;
		}
		while(--c){
			cin>>d;
			sum += d;
			if(sum > max){
				max = sum;
			}
			if(sum < 0){
				sum = 0;
			}
		}
		cout<< "Case #"<<k<<": "<<max<<"\n";
	}
	return 0;
}


