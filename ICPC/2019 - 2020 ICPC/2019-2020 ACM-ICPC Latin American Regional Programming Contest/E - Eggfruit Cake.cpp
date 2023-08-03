#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
    long long int s,n,t, c = 0;
    bool existE = false;
	string cake, nCake;
	cin >> cake >> s;
	n = cake.length();
	nCake = cake;
 
    t = n*s;
	
	for(int k = 0; k < n; k++){
		if(cake[k] == 'E'){
			nCake = cake.substr(k,n-k) + cake.substr(0, k);
            existE = true;
			break;
		}
	}
 
    if(!existE){
        cout << "0\n";
        return 0;
    }
	
	for(int k = 0; k < n; k++){
		if(nCake[k] == 'P'){
			c++;
			if(c > s){
				c = s;
			}
			t-=c;
		}
		else{
			c = 0;
		}
	}
	
	cout << t << "\n";
 
    return 0;
}
