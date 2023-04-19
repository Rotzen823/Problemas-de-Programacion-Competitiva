#include <bits/stdc++.h>
#define MAX 70

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

ll onePot[MAX];

ll preCalc(int x){
    if(x == 0){
        return 1;
    }

    if(onePot[x]){
        return onePot[x];
    }

    return onePot[x] = ((preCalc(x - 1) - 1) << 1LL) + (1LL << (x - 1)) + 1;
}

int cifras(ll x){
    int res = 0;
    while(x > 0){
        x >>= 1LL;
        res++;
    }

    return res - 1;
}

ll contOne(ll x){
    int lim = cifras(x);
    ll ones = 0, res = 0;

    for(int k = lim; k >= 0; k--){
        if(x & (1LL << k)){
            res += (preCalc(k) + ones * (1LL << k));
            ones++;
        }
    }

    return res;
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    ll a, b;
    cin >> a >> b;

    cout << contOne(b) - contOne(a - 1) << "\n";
    return 0;
}
