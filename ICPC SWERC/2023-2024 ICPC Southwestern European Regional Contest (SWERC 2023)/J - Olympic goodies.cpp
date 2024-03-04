#include <bits/stdc++.h>

#define INF 1000000000
#define MOD 1000000007
#define MAX 100005
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

    int n, p;
    cin >> n >> p;

    vector<vi> tree(n, vi());
    vector<bool> ready(n, false);

    for(int i = 1; i < n; i++){
        int a, b;
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    int leafs = 0;
    
    for(int i = 0; i < n; i++){
        if(tree[i].size() == 1){
            leafs++;
        }
    }

    int ans = (p / leafs) * 2; 
    if(p % leafs == 1){
        ans++;
    }
    else if(p % leafs >= 2){
        ans += 2;
    }

    cout << ans << ENDL;

    return 0;
}
