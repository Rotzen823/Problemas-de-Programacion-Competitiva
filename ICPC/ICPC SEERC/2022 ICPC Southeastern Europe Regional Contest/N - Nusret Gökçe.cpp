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

    int n, m;
    cin >> n >> m;

    vi s(n);
    set<ii> order;
    for(int i = 0; i < n; i++){
        cin >> s[i];
        order.insert(ii(s[i], i));
    }

    while(!order.empty()){
        int id = order.rbegin()->se;
        order.erase(ii(s[id], id));

        if(id != 0){
            if(s[id] > s[id - 1] && s[id] - s[id - 1] > m){
                order.erase(ii(s[id - 1], id - 1));
                s[id - 1] = s[id] - m;
                order.insert(ii(s[id - 1], id - 1));
            }
        }
        if(id != n - 1){
            if(s[id] > s[id + 1] && s[id] - s[id + 1] > m){
                order.erase(ii(s[id + 1], id + 1));
                s[id + 1] = s[id] - m;
                order.insert(ii(s[id + 1], id + 1));
            }
        }
    }

    cout << s[0];
    for(int i = 1; i < n; i++){
        cout << ' ' << s[i];
    }
    cout << ENDL;

    return 0;
}
