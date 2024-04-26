#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pa = pair <int, int>;
using vi = vector <int>;
using vii = vector <pa>;

#define fi first
#define se second
#define pb push_back
#define SZ(x) ((int)(x).size())
#define ALL(x) begin(x), end(x)
#define FOr(i, a, b) for (int i = (int)a; i < (int)b; ++i)
#define ROF(i, a, b) for (int i = (int)a - 1; i >= (int)b; --i)
#define ENDL '\n'

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    ll x = 0, y = 0;

    string s;
    cin >> s;

    for(char d : s){
        x *= 2;
        y *= 2;
        switch(d){
            case '1':
            x++;
            break;
            case '2':
            y++;
            break;
            case '3':
            x++;
            y++;
            break;
        }
    }

    int z = s.length();
    cout << z << ' ' << x << ' ' << y << ENDL;

    return 0;
}
