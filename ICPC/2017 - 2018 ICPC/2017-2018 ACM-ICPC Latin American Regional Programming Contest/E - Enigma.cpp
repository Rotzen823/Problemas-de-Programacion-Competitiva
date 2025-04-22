#include<bits/stdc++.h>
#define MAX 1005
 
using namespace std;

bool ready[MAX][MAX];

int n;
string x;

bool dp(int p, int res){
	if(p == x.length()){
		return !res;
	}

	if(ready[p][res]){
		return false;
	}

	ready[p][res] = true;

	int l = 0, r = 9;
	if(p == 0){
		l = 1;
	}

	if(x[p] != '?'){
		l = r = x[p] - '0';
	}

	for(int k = l; k <= r; k++){
		if(dp(p + 1, (res * 10 + k) % n)){
			x[p] = k + '0';
			return true;
		}
	}
	
	return false;
}
 
int main(){
	std::ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

	cin >> x >> n;

	if(dp(0, 0)){
		cout << x << "\n";
	}
	else{
		cout << "*\n";
	}
 
	return 0;
}
