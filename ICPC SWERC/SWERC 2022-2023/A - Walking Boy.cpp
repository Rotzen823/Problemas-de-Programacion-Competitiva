#include <bits/stdc++.h>

#define ENDL '\n'
#define fi first
#define se second
#define MOD 1000000007
#define INF 1000000000
#define MAX 100005

using namespace std;

typedef long long ll;
typedef pair <int, int> ii;
typedef vector <int> vi;
typedef vector <ii> vii;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;

        int c = 0;
        int ax = 0;
        while(n--){
            int x;
            cin >> x;
            c += (x - ax) / 120;

            ax = x;
        }

        c += (1440 - ax) / 120;

        if(c >= 2){
            cout << "YES\n";
        }
        else{
            cout << "NO\n";
        }
    }

    return 0;
}
