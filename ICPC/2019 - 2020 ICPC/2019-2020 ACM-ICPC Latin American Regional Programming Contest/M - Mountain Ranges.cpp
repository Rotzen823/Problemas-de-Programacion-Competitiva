#include<iostream>
#include <vector>
 
using namespace std;
 
int main(){
	
	int n, m, max = 1;
	
	cin>>n>>m;
	vector<int> Ar(n);
	
	for(int i = 0; i < n; i++){
		cin>>Ar[i];
	}
	
	int ax = 1;
	
	for(int i = 1; i < n; i++){
		if(Ar[i-1] >= Ar[i]-m){
			ax++;
		}
		else if(ax > max){
			max = ax;
			ax = 1;
		}
		else{
			ax = 1;
		}
	}
	if(ax > max){
		max = ax;
	}
	
	cout<<max;
	
	return 0;
}
