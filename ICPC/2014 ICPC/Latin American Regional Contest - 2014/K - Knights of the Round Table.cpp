#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define pb push_back
#define INF 1000000000
#define MOD 1000000007
#define MAX 100005
#define maxlog 20
#define ALL(x) begin(x), end(x)
#define SZ(x) ((int)(x).size())
#define ENDL '\n'

typedef long long ll;
typedef pair <int, int> ii;
typedef pair <ii, ii> ii2;
typedef vector <int> vi;
typedef vector <ii> vii;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, d;
    cin >> n >> d;
    vector<bool> isSeat(n, false);
    vi seats(n, -1);

    while(d--){
        int a, b;
        cin >> a >> b; a--; b--;
        isSeat[a] = true;
        seats[b] = a;
    }

    ll sum = 0;
    int st = -1;
    vi count(n, 0);
    for(int i = 0, j = 0; j < (n * 2); j++){
        int b = j % n;
        if(seats[b] != -1 && !isSeat[b]){
            sum++;
            count[b] = 1;
        }
        else if(seats[b] == -1 && isSeat[b]){
            sum--;
            count[b] = -1;
        }

        while(i <= j && sum < 0){
            sum -= count[i % n];
            i++;
        }

        if(j - i == n){
            st = i;
            break;
        }
    }

    ll ans = 1;
    sum = 0;
    for(int i = 0; i < n; i++, st++){
        st %= n;
        if(count[st] == 1){
            sum++;
        }
        if(seats[st] != -1){
            continue;
        }

        if(!isSeat[st]){
            sum++;
        }

        ans *= sum; ans %= MOD;

        sum--;
    }

    cout << ans << ENDL;

    return 0;
}
