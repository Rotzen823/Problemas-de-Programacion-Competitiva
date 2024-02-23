#include <bits/stdc++.h>

#define ENDL '\n'
#define INF 1000000000
#define MOD 1000000007
#define MAX_N 10000005
#define se second
#define fi fisrt

using namespace std;

typedef long long ll;
typedef pair <int, int> ii;
typedef vector <int> vi;
typedef vector <ii> vii;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, k;
    cin >> n >> k;

    vector<bool> lights(n + 1, true);

    int off = 0;
    int res = 0;
    while(k--){
        int x;
        cin >> x;

        for(int i = x; i <= n; i += x){
            if(lights[i]){
                off++;
                lights[i] = false;
            }
            else{
                off--;
                lights[i] = true;
            }
        }

        res = max(res, off);
    }

    cout << res << "\n";

    return 0;
}
