//Pura gente del coach moy
#include <bits/stdc++.h>

#define MOD 1000000007
#define MAX 1005
#define ENDL '\n'
#define INF 1000000000
#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector <ll> vi;
typedef vector<ii> vii;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;

    int ans = 100000;
    while(n--){
        int a, b;
        cin >> a >> b;
        ans = min(b / a, ans);
    }

    cout << ans << ENDL;



    return 0;
}
