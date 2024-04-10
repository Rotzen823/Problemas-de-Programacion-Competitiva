#include <bits/stdc++.h>
#define MAX 2025

using namespace std;
// Pura Gente del Coach Moy
using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

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

    int t;
    cin >> t;

    while(t--){
        string s1, s2;
        cin >> s1 >> s2;

        int b1 = 0, b2 = 0;

        string nS1, nS2;
        for(char x : s1){
            if(x == 'B'){
                b1++;
            }
            else if(nS1.empty() || nS1.back() != x){
                nS1.pb(x);
            }
            else{
                nS1.pop_back();
            }
        }

        for(char x : s2){
            if(x == 'B'){
                b2++;
            }
            else if(nS2.empty() || nS2.back() != x){
                nS2.pb(x);
            }
            else{
                nS2.pop_back();
            }
        }

        if(nS1 == nS2 && b1 % 2 == b2 % 2){
            cout << "YES\n";
        }
        else{
            cout << "NO\n";
        }
    }

  return 0;
}
