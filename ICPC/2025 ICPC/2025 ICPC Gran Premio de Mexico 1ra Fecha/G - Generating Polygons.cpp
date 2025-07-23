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
#define INF 10000000000000
#define MOD 1000000007
#define MAX 1005

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;

    while(t--){
        int n, a;
        cin >> n >> a;

        int aMin = (n / 2) - 1;
        if(n & 1){
            aMin++;
        }

        if(a < aMin){
            cout << "No\n";
            continue;
        }
        cout << "Yes\n";

        deque<ii> points;
        ii pL(0, 0), pR(1, 0);
        for(int i = 0; i < n; i += 2){
            if(i == n - 1){
                if(i % 4 == 0){ // Right
                    pR.se += (a - aMin) * 2 + 1;
                    points.pb(pR);
                }
                else{ //Left
                    pL.se += (a - aMin) * 2 + 1;
                    points.push_front(pL);
                }
                break;
            }
            if(i == n - 2){
                if(i % 4 == 0){ // Right
                    pL.fi -= (a - aMin) * 2;
                }
                else{ //Left
                    pR.fi += (a - aMin) * 2;
                }
            }

            points.pb(pR);
            points.push_front(pL);
            pR.se++; pL.se++;

            if(i % 4 == 0){
                pR.fi++; 
                pL.fi++;   
            }
            else{
                pR.fi--; 
                pL.fi--; 
            }
        }

        for(ii x : points){
            cout << x.fi << ' ' << x.se << ENDL;
        }
    }

    return 0;
}
