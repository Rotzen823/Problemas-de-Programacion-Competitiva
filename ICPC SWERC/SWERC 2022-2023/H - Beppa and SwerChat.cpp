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

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;

        vi a(n + 1), b(n);

        for(int i = 0; i < n; i++){
            int x;
            cin >> x;
            a[x] = i;
        }

        for(int i = 0; i < n; i++){
            cin >> b[i];
        }

        int c = 0;
        int ax = n;
        for(int i = n - 1; i >= 0; i--){
            if(a[b[i]] < ax){
                c++;
                ax = a[b[i]];
            }
            else{
                break;
            }
        }   

        cout << n - c << "\n";
    }

    return 0;
}
