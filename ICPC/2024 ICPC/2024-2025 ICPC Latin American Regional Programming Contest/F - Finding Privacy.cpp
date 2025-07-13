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
#define MAX 1005

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, k;
    cin >> k >> n;

    int a = n / 3, b = n / 2;
    if(n % 3 != 0){
        a++;
    }
    if(n % 2 != 0){
        b++;
    }

    if(k < a || k > b){
        cout << "*\n";
        return 0;
    }

    string ans(n, '-');
    for(int i = 0; i < n; i++){
        int actN = n - i;
        int maxSeats = actN / 2;
        if(actN % 2 != 0){
            maxSeats++;
        }

        if(maxSeats != k){
            i++;
        }
        ans[i] = 'X';
        i++;
        k--;
    }

    cout << ans << ENDL;

    return 0;
}
