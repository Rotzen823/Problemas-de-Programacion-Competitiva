//Pura gente del coach moy
#include <bits/stdc++.h>

#define MOD 1000000007
#define INF 10000000000
#define ENDL '\n'
#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef pair <int, ll> ii;
typedef vector <ii> vii;
typedef vector <int> vi;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, h;
    cin >> n >> h;

    int ans = 0;
    while(n--){
        int x;
        cin >> x;
        if(h >= x){
            ans++;
        }
    }

    cout << ans << ENDL;

    return 0;
}
