#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define pb push_back
#define MOD 1000000007
#define INF 2000000
#define MAX 1000
#define ENDL '\n'
#define SZ(x) ((int)(x).size())
#define ALL(x) begin(x), end(x)

typedef long long ll;
typedef pair <int, int> pi;
typedef vector <int> vi;
typedef vector <pi> vii;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;

    int ans = max(n - 2, 1);

    cout << ans << ENDL;

    return 0;
}
