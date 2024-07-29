#include <bits/stdc++.h>

using namespace std;

#define MAX 10000
#define INF 1000000000
#define MOD 1000000009
#define fi first
#define se second
#define ENDL '\n'
#define pb push_back
#define SZ(x) ((int)(x).size())
#define ALL(x) begin(x), end(x)

typedef long long ll;
typedef pair <int, int> ii;
typedef vector<int> vi;
typedef vector <ii> vii;

template<class T>
struct SparseTable{
    vector<vector<T> > jmp;
    void init(const vector<T>& V){
        jmp.emplace_back(V);
        for(int pw = 1, k = 1; pw * 2 <= SZ(V); pw *= 2, k++){
            jmp.emplace_back(SZ(V) - pw * 2 + 1);
            for(int j = 0; j < SZ(jmp[k]); j++)
                jmp[k][j] = max(jmp[k - 1][j], jmp[k - 1][j + pw]);
        }

    }
    T query(int l, int r){
        int dep = 31 - __builtin_clz(r - l);
        return max(jmp[dep][l], jmp[dep][r - (1 << dep)]);
    }
};

SparseTable<int> st[2];

int main(){
    
    ios_base::sync_with_stdio;
    cin.tie(0); cout.tie(0);
    
    int n;
    cin >> n; 
    vi a(n), b(n);

    map<int, ii> pesas;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        if(pesas.count(a[i])){
            pesas[a[i]].se = i;
        }
        else{
            pesas[a[i]].fi = i;
        }
    }

    int ans = 0;
    for(int i = 0; i < n; i++){
        cin >> b[i];
        if(pesas.count(b[i])){
            if(b[pesas[b[i]].fi] == b[i] && pesas[b[i]].fi < i){
                pesas[b[i]].se = i;
            }
            else{
                ans = max(ans, b[i]);
            }
        }
        else{
            pesas[b[i]].fi = i;
        }
    }

    st[1].init(a);
    st[0].init(b);

    for(auto p = pesas.rbegin(); p != pesas.rend(); p++){
        int x = p->first;
        //cout << x << ENDL;
        if(ans >= x){
            break;
        }
        ii ran = p->second;

        int l = ran.fi, r = ran.se;
        int id = a[l] == x;
        //cout << l << ' ' << r << ENDL;
        if(l + 1 == r){
            continue;
        }
        
        int ax = st[id].query(l + 1, r);
        //cout << "R: " << ax << ENDL;

        if(ax > x){
            ans = x;
            break;
        }
        else{
            ans = max(ans, ax);
        }
    }

    cout << ans << ENDL;
    
    return 0;
}
