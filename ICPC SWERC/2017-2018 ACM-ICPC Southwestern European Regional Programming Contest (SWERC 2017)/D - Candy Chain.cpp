#include <bits/stdc++.h>
#define INF 1000000000
#define MAX 55
#define MAXC 405

using namespace std;

string s;
string candies[400];
int P[400];
int memo[51][51][2][401][51];
int c;

int dp(int i, int j, bool rfc, int p, int k){
    if(p == c){
        return -INF;
    }

    if(i == j){
        return k == (int) candies[p].length() ? P[p] : 0;
    }

    if(memo[i][j][rfc][p][k] != -1){
        return memo[i][j][rfc][p][k];
    }

    if(k == (int) candies[p].length()){
        return memo[i][j][rfc][p][k] = dp(i, j, rfc, 0, 0) + P[p];
    }

    int res = -INF;
    if(s[i] == candies[p][k]){
        res = max(res, dp(i + 1, j, rfc, p, k + 1));
    }

    if(k == 0 && p == 0 && !rfc){
        res = max(res, dp(i + 1, j, false, 0, 0));
    }

    if(k == 0){
        res = max(res, dp(i, j, rfc, p + 1, 0));
    }

    if(k > 0){
        for(int m = i + 1; m < j; m++){
            res = max(res, dp(m, j, rfc, p, k) + dp(i, m, true, 0, 0));
        }
    }

    return memo[i][j][rfc][p][k] = res;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    memset(memo, -1, sizeof(memo));

    cin >> s >> c;

    c *= 2;

    for(int i = 0; i < c; i += 2){
        cin >> candies[i] >> P[i];
        candies[i + 1] = candies[i];
        P[i + 1] = P[i];
        reverse(candies[i + 1].begin(), candies[i + 1].end());
    }

    int res = dp(0, s.length(), false, 0, 0);

    cout << res << "\n";

    return 0;
}
