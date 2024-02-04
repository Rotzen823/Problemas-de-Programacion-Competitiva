#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ll;
typedef vector<int> vi;
typedef vector<double> vd;

vector<vd> comb;

double nCk(int n, int k){
    if(k < 0 || k > n){
        return 0;
    }

    if(n == k || k == 0){
        return 1;
    }

    if(comb[n][k] != -1){
        return comb[n][k];
    }

    return comb[n][k] = nCk(n - 1, k - 1) + nCk(n - 1, k);
}

int n, d;

vector<vector<vd> >  memo;

double dp(int s, int a, int b){
	if(s == 0 && (a == 0 || b == 0)){
		return 0;
	}

	if(memo[s][a][b] != -1.0){
		return memo[s][a][b];
	}

	double res = 0;
	for(int i = 0; i <= s; i++){
		for(int j = 0; j <= a; j++){
			for(int k = 0; k <= b; k++){
				if(i == 0 && j == 0 && k == 0){
					continue;
				}

				double ax = dp(s - i, a - j, b - k);
				double p = nCk(s, i) * nCk(a, j) * nCk(b, k) * nCk(n - a - b - s, d - i - j - k);
				p /= nCk(n, d);
				res += (p * ax);
			}
		}
	}

	res++;
	double p0 = nCk(n - a - b - s, d) / nCk(n, d);
	res /= (1.0 - p0);
	return memo[s][a][b] = res;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

	memo.assign(15, vector<vd>(15, vd(15, -1.0)));
	comb.assign(55, vd(55, -1.0));

	int c;
	cin >> n >> d >> c;

	set<int> j1;
	for(int i = 0; i < c; i++){
		int x;
		cin >> x;
		j1.insert(x);
	}

	int s = 0;
	for(int i = 0; i < c; i++){
		int x;
		cin >> x;
		if(j1.count(x)){
			s++;
		}
	}

	double res = dp(s, c - s, c - s);

	cout << res << "\n";
    
    return 0;
}
