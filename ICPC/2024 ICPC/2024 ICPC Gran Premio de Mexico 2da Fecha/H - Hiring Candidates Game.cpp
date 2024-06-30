#include <bits/stdc++.h>
#define MAX 1000005
#define MOD 1000000007

using namespace std;
// Pura Gente del Coach Moy
using ll = long long;
using ii = pair<ll, ll>;
using vi = vector<ll>;
using vii = vector<ii>;

#define fi first
#define se second
#define pb push_back
#define SZ(x) ((int)(x).size())
#define ALL(x) begin(x), end(x)
#define FOR(i, a, b) for (int i = (int)a; i < (int)b; ++i)
#define ROF(i, a, b) for (int i = (int)a - 1; i >= (int)b; --i)
#define ENDL '\n'

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int n, r, c;
    cin >> n >> r >> c;
    r--; c--;

    list<int> con;
    for(int i = 0; i < n; i++){
        con.push_back(i + 1);
    }

    vi ans;
    auto s1 = con.begin();
    auto s2 = --con.end();
    
    while(SZ(con) > 2){
        int rx = r % SZ(con);
        while(rx--){
            s1++;
            if(s1 == con.end()){
                rx++;
            }
        }

        int cx = c % SZ(con);
        while(cx--){
            s2--;
            if(s2 == con.end()){
                cx++;
            }
        }

        if(s1 == s2){
            ans.pb(*s1);
            
            auto e = s1;
            while(s1 == con.end() || s1 == e){
				s1++;
			}
			while(s2 == con.end() || s2 == e){
				s2--;
			}
            con.erase(e);
        }
        else{
            auto e1 = s1;
            auto e2 = s2;
            
			while(s1 == con.end() || s1 == e1 || s1 == e2){
				s1++;
			}
			while(s2 == con.end() || s2 == e1 || s2 == e2){
				s2--;
			}

            con.erase(e1);
            con.erase(e2);
        }

    }

    for(int x : con){
        ans.pb(x);
    }

    sort(ALL(ans));

    cout << ans[0];
    for(int i = 1; i < SZ(ans); i++){
        cout << ' ' << ans[i];
    }
    cout << ENDL;

 	return 0;
}
