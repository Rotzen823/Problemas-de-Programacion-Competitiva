#include <bits/stdc++.h>
#define MAX 1005

using namespace std;

typedef long long ll;
typedef vector<int> vi;

int memo[MAX][MAX];
int horarios[MAX];

int horarioDif(int i, int j){
    int dif = abs(horarios[i] - horarios[j]);
    return min(dif, 24 - dif);
}

int dp(int i, int j){
    if(i >= j){
        return 0;
    }

    if(memo[i][j] != -1){
        return memo[i][j];
    }

    memo[i][j] = min(dp(i + 2, j) + horarioDif(i, i + 1), dp(i + 1, j - 1) + horarioDif(i, j));
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    memset(memo, -1, sizeof(memo));

    int n;
    cin >> n;

    for(int k = 0; k < n; k++){
        cin >> horarios[k];
    }

    sort(horarios, horarios + n);

    cout << dp(0, n - 1) << "\n";
     
    return 0;
}
