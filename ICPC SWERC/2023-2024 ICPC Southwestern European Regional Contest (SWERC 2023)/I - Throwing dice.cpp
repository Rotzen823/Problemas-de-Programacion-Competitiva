#include <bits/stdc++.h>

#define INF 1000000000
#define MOD 1000000007
#define MAX 30
#define fi first
#define se second
#define ENDL '\n'

using namespace std;

typedef long long ll;
typedef pair <int, int> ii;
typedef vector <int> vi;
typedef vector <ii> vii;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, m;;
    cin >> n >> m;

    ll resA = n, resB = m;
    for(int i = 0; i < n; i++){
        ll x;
        cin >> x;

        resA += x;
    }

    for(int i = 0; i < m; i++){
        ll x;
        cin >> x;

        resB += x;
    }

    if(resA > resB){
        cout << "ALICE\n";
    }
    else if(resA == resB){
        cout << "TIED\n";
    }
    else{
        cout << "BOB\n";
    }

    return 0;
}
