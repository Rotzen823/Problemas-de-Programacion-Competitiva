#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define pb push_back
#define sz size
#define all(x) x.begin(), x.end()
#define forn(i, n) for(int i = 0; i < n; i++)
#define forns(i, s, n) for(int i = s; i < n; i++)
#define ENDL '\n'
#define INF 1000000000
#define MOD 1000000007

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, x;
    cin >> n >> x;

    vi time(481, 0);
    while(n--){
        int s, d;
        cin >> s >> d;

        d += s;

        for(int i = s; i <= d; i++){
            for(int j = i % x; j <= min(i, 480); j += x){
                time[j]++;
            }
        }
    }

    int t = 0;
    for(int i = 1; i <= 480; i++){
        if(time[i] < time[t]){
            t = i;
        }
    }

    cout << t << ' ' << time[t] << ENDL;

    return 0;
}
