#include <bits/stdc++.h>

using namespace std;

#define MAX 10000
#define INF 1000000000
#define MOD 1000000009
#define fi first
#define se second
#define ENDL '\n'
#define pb push_back
#define SZ(x) ((int)(x).size())
#define ALL(x) begin(x), end(x)

typedef long long ll;
typedef pair <int, int> ii;
typedef vector<int> vi;
typedef vector <ii> vii;

ll convert(int n, string a){
    ll ans = 0;
    bool flag = true;
    for(int i = 0, j = n - 1; i < n; i++, j--){
        if(a[i] == '1'){
            if(flag){
                ans += (1LL << j);
            }
            flag = !flag;
        }
        else if(!flag){
            ans += (1LL << j);
        }
    }

    return ans;
}

int main(){
    ios_base::sync_with_stdio;
    cin.tie(0); cout.tie(0);
    
    int n;
    string a, b;
    cin >> n >> a >> b;
    

    ll pA = convert(n, a), pB = convert(n, b);
    ll ans = pB - pA - 1;

    //cout << pB << ' ' << pA << ' ' << ans << ENDL;

    cout << ans << ENDL;
    
    return 0;
}
