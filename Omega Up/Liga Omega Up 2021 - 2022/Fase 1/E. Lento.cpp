#include<bits/stdc++.h>

using namespace std;

int main(){
	long long int n, sum = 0, ci = 0, mi, num;
	cin >> n;
	while(n--){
		cin >> num;
		sum += num;
		if(num % 2 == 1){
			ci++;
			if(ci == 1){
				mi = num;
			}
			else if(num < mi){
				mi = num;
			}
		}
	}
	
	if(ci == 0){
		cout<<"0\n";
	}
	else if(ci % 2 == 0){
		cout<<sum-mi<<"\n";
	}
	else{
		cout<<sum<<"\n";
	}
	return 0;
}
