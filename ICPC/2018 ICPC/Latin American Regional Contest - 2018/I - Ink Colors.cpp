#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define pb push_back
#define MOD 1000000007
#define INF 1000000
#define MAX 100005
#define ENDL '\n'
#define SZ(x) ((int)(x).size())
#define ALL(x) x.begin(), x.end()

typedef long long ll;
typedef pair <int, int> ii;
typedef vector <int> vi;
typedef vector <ll> vll;
typedef vector <ii> vii;

vector<vi> tree;
int memo[MAX][5];

int dp(int, int);

vii minimum(int node){
    vii sons(4, ii(INF, INF));
    for(int i = 0; i < SZ(tree[node]); i++){
        int son = tree[node][i];
        sons[3] = ii(dp(son, 1) - dp(son, 0), i);
        for(int i = 2; i >= 0; i--){
            if(sons[i + 1] < sons[i]){
                swap(sons[i + 1], sons[i]);
            }
            else{
                break;
            }
        }
    }
    return sons;
}

int dp(int node, int level){
    if(memo[node][level] != -1){
        return memo[node][level];
    }

    if(level == 0){
        int ans = 0;
        for(int son : tree[node]){
            ans += dp(son, 1);
        }
        return memo[node][level] = ans;
    }

    int op1 = dp(node, 0);
    if(level == 1){
        if(SZ(tree[node]) < 3){
            return memo[node][level] = op1;
        }
        int ans = op1;
        vii sons = minimum(node);

        int restSons = op1 - (dp(tree[node][sons[0].se], 1) + dp(tree[node][sons[1].se], 1));
        int handA = dp(tree[node][sons[0].se], 0);
        int handB = dp(tree[node][sons[1].se], 0);
        int handC = dp(tree[node][sons[2].se], 0);
        int hands = handA + handB;
        for(int i = 0; i < SZ(tree[node]); i++){
            int son  = tree[node][i];
            int handAct = hands;
            int restAct = restSons; 
            if(i == sons[0].se){
                handAct = (hands - handA) + handC;
                restAct -= dp(tree[node][sons[2].se], 1);
            }
            else if(i == sons[1].se){
                handAct = (hands - handB) + handC;
                restAct -= dp(tree[node][sons[2].se], 1);
            }
            else{
                restAct -= dp(son, 1);
            }

            ans = max(ans, dp(son, 2) + restAct + handAct);
        }

        return memo[node][level] = ans;
    }

    if(SZ(tree[node]) < 2){
        return memo[node][level] = op1;
    }

    vii sons = minimum(node);
    int op2 = op1 - (dp(tree[node][sons[0].se], 1) + dp(tree[node][sons[1].se], 1));
    op2 += (dp(tree[node][sons[0].se], 0) + dp(tree[node][sons[1].se], 0));
    int ans = max(op1, op2 + 1);
    return memo[node][level] = ans;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);  
    
    memset(memo, -1, sizeof(memo));

    int n;
    cin >> n;

    tree.assign(n, vi());
    for(int i = 1; i < n; i++){
        int p;
        cin >> p; p--;
        tree[p].pb(i);
    }

    cout << dp(0, 0) << ENDL;

    return 0;
}
