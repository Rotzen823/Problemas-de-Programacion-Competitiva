#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ll;
typedef vector<int> vi;

vi sol;
set<ll> res;

map<vi, ll> memo;

ll dp(vi x){
	if(x.back() == 0){
		return 1;
	}

	if(memo.count(x)){
		return memo[x];
	}

	int st = 0;
	while(x[st] == 0){
		st++;
	}

	x[st]--;
	ll res = dp(x);
	ll ax = res;
	x[st]++;

	for(int i = st + 1; i < (int) x.size(); i++){
		if(x[i] > x[i - 1]){
			x[i]--;
			ax = dp(x);
			res += ax;
			x[i]++;
		}
		else{
			res += ax;
		}
	}

	return memo[x] = res;
}

void solve(int i, int sum){
	if(i == 0){
		if(sum > 0){
			return;
		}

		res.insert(dp(sol));
	}

	int st = 0;
	if(!sol.empty()){
		st = sol.back();
	}

	for(int s = st; s <= sum; s++){
		sol.push_back(s);
		solve(i - 1, sum - s);
		sol.pop_back();
	}
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

	int d, h;
	cin >> d >> h;

	res.insert(1);

	solve(d, h - 1);

	for(ll x : res){
		cout << x << "\n";
	}
    
    return 0;
}
