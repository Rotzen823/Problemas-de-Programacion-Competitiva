#include<bits/stdc++.h>

using namespace std;

int main(){
	int n, a, b;
	bool ac,dc;
	cin>>n;
	
	while(n--){
		cin>>a;
		dc = ac = true;
		
		for(int k=1; k<10; k++){
			cin>>b;
			if(a > b){
				ac = false;
			}
			
			if(a < b){
				dc = false;
			}
			a = b;
		}
		
		if(ac || dc){
			cout << "Ordered\n";
		}
		else{
			cout << "Unordered\n";
		}
	}
}
