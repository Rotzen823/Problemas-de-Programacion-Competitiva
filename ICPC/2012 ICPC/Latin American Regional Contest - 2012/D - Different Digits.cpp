#include <bits/stdc++.h>
#define MAX 5005

using namespace std;
typedef pair<int, int> ii;
typedef vector<ii> vii;

int memo[MAX];

int rep(int n){
    bool dig[10] = {0};

    while(n > 0){
        int r = n % 10;
        if(dig[r]){
            return 0;
        }
        dig[r] = true;
        n /= 10;
    }

    return 1;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    memo[0] = 0;

    for(int k = 1; k <= 5000; k++){
        memo[k] = memo[k - 1] + rep(k);
    }

    int a, b;
    while(cin >> a >> b){
        cout << memo[b] - memo[a - 1] << "\n";
    }
    

    return 0;
}
