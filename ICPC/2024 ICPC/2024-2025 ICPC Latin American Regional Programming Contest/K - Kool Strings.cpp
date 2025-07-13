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

    int k;
    string s;
    cin >> k >> s;

    int n = s.length();

    if(k == 2){
        string s1(n, '1'), s0(n, '0');
        for(int i = 1; i < n; i += 2){
            s1[i] = '0';
            s0[i] = '1';
        }

        int ans1 = 0, ans0 = 0;
        for(int i = 0; i < n; i++){
            if(s[i] == s1[i]){
                ans0++;
            }
            else{
                ans1++;
            }
        }

        if(ans0 < ans1){
            cout << ans0 << ' ' << s0 << ENDL;
        }
        else{
            cout << ans1 << ' ' << s1 << ENDL;
        }
        return 0;
    }

    int st = 0, ans = 0;
    for(int i = 1; i < n; i++){
        if(s[i] != s[i - 1]){
            for(int j = st + k - 1; j < i; j += k){
                if(j == i - 1){
                    j--;
                }
                s[j] = s[j] == '1' ? '0' : '1';
                ans++;
            }
            st = i;
        }
    }
    for(int j = st + k - 1; j < n; j += k){
        if(j == n - 1){
            j--;
        }
        s[j] = s[j] == '1' ? '0' : '1';
        ans++;
    }

    cout << ans << ' ' << s << ENDL;

    return 0;
}
