#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define pb push_back
#define sz size()
#define all(x) x.begin(), x.end()
#define forn(i, n) for(int i = 0; i < n; i++)
#define forns(i, s, n) for(int i = s; i < n; i++)
#define ENDL '\n'
#define INF 100000000000000
#define MOD 1000000007
#define MAX 1005
#define LOG 20

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
 
    int k, n;
    cin >> k >> n;

    vi cont(k + 1);
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        cont[x]++;
    }

    int ans = n / k;
    int op = 3;
    if((n + 1) % k == 0){
        ans = (n + 1) / k;
        op = 2;
    }
    else if((n - 1) % k == 0){
        ans = (n - 1) / k;
        op = 1;
    }
    else if(n % k > 0){
        cout << "*\n";
        return 0;
    }

    int less = 0, great = 0;
    for(int i = 1; i <= k; i++){
        if(cont[i] == ans - 1){
            if(great){
                cout << "*\n";
                return 0;
            }
            great = i;
        }
        else if(cont[i] == ans + 1){
            if(less){
                cout << "*\n";
                return 0;
            }
            less = i;
        }
        else if(cont[i] != ans){
            cout << "*\n";
            return 0;
        }
    }

    switch(op){
        case 1:
        if(less && !great){
            cout << "-" << less << ENDL;
            return 0;
        }
        break;
        case 2:
        if(!less && great){
            cout << "+" << great << ENDL;
            return 0;
        }
        break;
        case 3:
        if(less && great){
            cout << "-" << less << " +" << great << ENDL;
            return 0;
        }
        break;
    }
    
    cout << "*\n";
    return 0;
}
