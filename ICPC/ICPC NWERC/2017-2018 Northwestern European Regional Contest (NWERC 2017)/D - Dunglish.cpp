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
typedef pair <ll, ll> ii;
typedef vector <int> vi;
typedef vector <ii> vii;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;

    string s[n];

    for(int i = 0; i < n; i++){
        cin >> s[i];
    }

    map<string, string> trad;
    map<string, ii> punt;
    int m;
    cin >> m;

    while(m--){
        string a, b, c;
        cin >> a >> b >> c;

        if(c == "correct"){
            trad[a] = b;
            punt[a].fi++;
        }
        else{
            trad[a] = b;
            punt[a].se++;
        }
    }

    ll correct = 1;
    ll tot = 1;
    for(int i = 0; i < n; i++){
        correct *= punt[s[i]].fi;
        tot *= (punt[s[i]].fi + punt[s[i]].se);
    }

    if(tot == 1){
        cout << trad[s[0]];
        for(int i = 1; i < n; i++){
            cout << " " << trad[s[i]];
        }
        cout << ENDL;
        if(correct == 1){
            cout << "correct\n";
        }
        else{
            cout << "incorrect\n";
        }
    }
    else{
        cout << correct << " " << "correct\n";
        cout << tot - correct << " " << "incorrect\n";
    }


    return 0;
}
