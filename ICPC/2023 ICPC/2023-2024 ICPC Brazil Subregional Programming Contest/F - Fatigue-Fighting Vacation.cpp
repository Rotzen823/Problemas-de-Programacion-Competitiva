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

    int d, c, r;
    cin >> d >> c >> r;

    int act[c];
    for(int i = 0; i < c; i++){
        cin >> act[i];
    }

    int ans = r;
    while(r--){
        int x;
        cin >> x;
        d += x;
    }

    for(int i = 0; i < c; i++){
        if(d >= act[i]){
            d -= act[i];
            ans++;
        }
        else{
            break;
        }
    }

    cout << ans << ENDL;

    return 0;
}
