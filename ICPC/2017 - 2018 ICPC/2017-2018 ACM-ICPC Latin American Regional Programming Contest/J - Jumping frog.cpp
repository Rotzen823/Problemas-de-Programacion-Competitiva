#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define pb push_back
#define MOD 1000000007
#define INF 1000000000
#define MAX 1000
#define ENDL '\n'
#define SZ(x) ((int)(x).size())
#define ALL(x) begin(x), end(x)

typedef long long ll;
typedef pair <int, int> ii;
typedef vector <int> vi;
typedef vector <ii> vii;

bool solve(string &s, int d){
    int n = s.length();
    vector<bool> ready(n);

    for(int i = 0; i < n; i++){
        if(s[i] == 'R' && !ready[i]){
            int j = (i + d) % n;
            ready[i] = true;
            bool flag = true;
            while(i != j){
                if(s[j] == 'P' || ready[j]){
                    flag = false;
                    break;
                }
                ready[j] = true;
                j = (j + d) % n;
            }

            if(flag){
                return true;
            }
        }
    }

    return false;
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);   

    string s;
    cin >> s;

    int n = s.length();

    bool flag = true;
    for(int i = 0; i < n; i++){
        if(s[i] == 'P'){
            flag = false;
            break;
        }
    }

    if(flag){
        cout << n - 1 << ENDL;
        return 0;
    }

    vi cont(n, 0);
    vector<bool> ready(n);

    for(int i = 2; i < n; i++){
        cont[__gcd(i, n)]++;
    }

    int ans = 0;
    for(int d = 2; d < n; d++){
        if(n % d == 0){
            if(cont[d] && solve(s, d)){
                ans += cont[d];
            }
        }
    }

    cout << ans << ENDL;

    return 0;
}
