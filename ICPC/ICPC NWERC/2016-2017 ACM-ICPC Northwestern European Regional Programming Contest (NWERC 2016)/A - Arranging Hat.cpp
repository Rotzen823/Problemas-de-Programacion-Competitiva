#include <bits/stdc++.h>

using namespace std;

#define MAX 45
#define INF 1000000
#define MOD 1000000009
#define fi first
#define se second
#define ENDL '\n'
#define pb push_back
#define SZ(x) ((int)(x).size())
#define ALL(x) begin(x), end(x)
#define FOR(i, a, b) for (int i = (int)a; i < (int)b; ++i)
#define ROF(i, a, b) for (int i = (int)a - 1; i >= (int)b; --i)

typedef long long ll;
typedef pair <int, int> ii;
typedef vector<int> vi;
typedef vector <ii> vii;

int n, m;
string nums[MAX];
int memo[MAX][MAX][10][405];
int best[MAX][MAX][10][405];

int dp(int i, int j, int d, int p){
	if(i > j || p >= m){
		return 0;
	}

	if(d >= 10){
		return INF;
	}

	if(memo[i][j][d][p] != -1){
		return memo[i][j][d][p];
	}

	int ans = dp(i, j, d + 1, p);
	best[i][j][d][p] = -1;
	int c = 0;
	for(int k = i; k <= j; k++){
		if(nums[k][p] - '0' != d){
			c++;
		}
		int ax = dp(i, k, 0, p + 1) + dp(k + 1, j, d + 1, p) + c;
		if(ax < ans){
			ans = ax;
			best[i][j][d][p] = k;
		}
	}

	return memo[i][j][d][p] = ans;
}

void changes(int i, int j, int d, int p){
	if(i > j || d >= 10 || p >= m){
		return;
	}

	int fin = best[i][j][d][p];

	if(fin == -1){
		changes(i, j, d + 1, p);
		return;
	}
	for(int k = i; k <= fin; k++){
		nums[k][p] = (char) d + '0';
	}

	changes(i, fin, 0, p + 1);
	changes(fin + 1, j, d + 1, p);
}

int main(){
    
    ios_base::sync_with_stdio;
    cin.tie(0); cout.tie(0);

	memset(memo, -1, sizeof(memo));
    
    cin >> n >> m;

	for(int i = 0; i < n; i++){
		cin >> nums[i];
	}

	int ans = dp(0, n - 1, 0, 0);
	changes(0, n - 1, 0, 0);

	//cout << ans << ENDL;
	
	for(int i = 0; i < n; i++){
		cout << nums[i] << ENDL;
	}
    
    return 0;
}
