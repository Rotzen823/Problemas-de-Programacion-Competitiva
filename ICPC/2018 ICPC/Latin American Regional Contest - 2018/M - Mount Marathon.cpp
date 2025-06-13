#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define pb push_back
#define MOD 1000000007
#define INF 1000000000
#define MAX 1000
#define ENDL '\n'
#define SZ(x) ((int)(x).size())
#define ALL(x) begin(x), end(x)

typedef long long ll;
typedef pair <int, int> ii;
typedef vector <int> vi;
typedef vector <ll> vll;
typedef vector <ii> vii;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);   

    int n;
    cin >> n;

    vi c(n);
    for(int i = 0; i < n; i++){
        cin >> c[i];
    }

    int ans = 1;
    for(int i = n - 2; i >= 0; i--){
        if(c[i] < c[i + 1]){
            ans++;
        }
    }

    cout << ans << ENDL;

    return 0;
}
