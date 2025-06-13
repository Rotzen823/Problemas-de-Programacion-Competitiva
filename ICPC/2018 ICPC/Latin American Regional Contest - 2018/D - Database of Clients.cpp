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
typedef vector <ll> vll;
typedef vector <ii> vii;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);   

    int n;
    cin >> n;
    set<string> emails;

    while(n--){
        string s;
        cin >> s;

        string realS = "";
        for(char x : s){
            if(x == '+' || x == '@'){
                break;
            }
            else if(x != '.'){
                realS += x;
            }
        }

        int posArroba = s.find('@');
        string provider = s.substr(posArroba + 1, s.length() - posArroba);
        realS += ('@' + provider);
        emails.insert(realS);
    }

    cout << emails.size() << ENDL;

    return 0;
}
