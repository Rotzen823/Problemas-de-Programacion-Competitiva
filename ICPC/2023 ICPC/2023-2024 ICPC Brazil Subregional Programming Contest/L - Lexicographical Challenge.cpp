//Pura gente del coach moy
#include <bits/stdc++.h>

#define MOD 1000000007
#define INF 10000000000
#define ENDL '\n'
#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef pair <int, ll> ii;
typedef vector <ii> vii;
typedef vector <int> vi;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    string s;
    int k;
    cin >> s >> k;

    int n = s.length();

    string res(n, ' ');

    for(int i = 0; i < k; i++){
        string ax;
        for(int j = i; j < n; j += k){
            ax.push_back(s[j]);
        }

        sort(ax.begin(), ax.end());

        for(int j = 0; j < (int) ax.length(); j++){
            res[j * k + i] = ax[j]; 
        }
    }

    cout << res << ENDL;

    return 0;
}
