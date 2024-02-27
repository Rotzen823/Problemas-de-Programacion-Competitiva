#include <bits/stdc++.h>

#define ENDL '\n'
#define fi first
#define se second
#define MOD 1000000007
#define INF 1000000000
#define MAX 100005

using namespace std;

typedef long long ll;
typedef pair <int, int> ii;
typedef vector <int> vi;
typedef vector <ii> vii;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

	int n;
    string s;
    
    cin >> n >> s;

    int c = 0;
    for(int i = 0; i < n; i++){
        if(s[i] == 'W'){
            c++;
        }
    }

    vi cont(n + 2, 0);
    cont[c]++;
    for(int i = 0, j = n; j < (int) s.length(); i++, j++){
        if(s[i] == 'W'){
            c--;
        }
        if(s[j] == 'W'){
            c++;
        }
        cont[c]++;
    }

    for(int i = 0; i <= n; i++){
        if(cont[i] >= n){
            cout << i << "\n";
            return 0;
        }

        cont[i + 1] += cont[i];
    }

    cout << "0\n";
    return 0;
}
