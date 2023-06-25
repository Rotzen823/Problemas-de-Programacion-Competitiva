#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> vi;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, c, s;
    cin >> n >> c >> s;

    int p = 1, res = 0;
    if(s == 1){
        res++;
    }

    while(c--){
        int x;
        cin >> x;

        p += x;
        if(p < 1){
            p = n;
        }
        else if(p > n){
            p = 1;
        }

        if(p == s){
            res++;
        }
    }

    cout << res << "\n";
	return 0;
}
