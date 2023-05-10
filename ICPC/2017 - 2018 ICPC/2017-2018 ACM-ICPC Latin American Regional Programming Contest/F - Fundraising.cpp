#include<bits/stdc++.h>
#define MAX 100005

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ii, ll> iii;

iii ricos[MAX];
iii ricosD[MAX];

class SegmentTree{
    private:
        int n;
        vector<ll> st;
        int left(int v){
            return (v << 1);
        }
        int right(int v){
            return (v << 1) + 1;
        }
        void build(int id, ll value, int v, int l, int r){
            if(l == r){
                st[v] = value;
                return;
            }
            int m = (l + r) / 2;
            if(id <= m){
                build(id, value, left(v), l, m);
            }
            else{
                build(id, value, right(v), m + 1, r);
            }
            st[v] = max(st[left(v)] , st[right(v)]);
        }
        //Continuación en la siguiente página 
        ll query(int sl, int sr, int v, int l, int r){
            if(sl > r || sr < l){
                return 0;
            }
 
            if(l >= sl && r <= sr){
                return st[v];
            }
 
            int m = (l + r) / 2;
 
            return max(query(sl, sr, left(v), l, m), query(sl, sr, right(v), m + 1, r));
        }
 
    public:
        SegmentTree(int N){
            n = N;
            st.assign(4 * n, 0);
        }
 
        ll query(int l, int r){
            return query(l, r, 1, 0, n - 1);
        }
 
        void update(int id, ll value){
            return build(id, value, 1, 0, n - 1);
        }
};

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

    int n;
    cin >> n;

    vector<int> sec;
    for(int i = 0; i < n; i++){
        int a, b, c;
        cin >> a >> b >> c;
        ricos[i] = iii(ii(a, b), c);
    }

    sort(ricos, ricos + n);

    int nN = 1;
    ricosD[0] = ricos[0];
    sec.push_back(ricos[0].first.second);
    for(int k = 1; k < n; k++){
        if(ricos[k].first == ricosD[nN - 1].first){
            ricosD[nN - 1].second += ricos[k].second;
        }
        else{
            ricosD[nN] = ricos[k];
            nN++;
            sec.push_back(ricos[k].first.second);
        }
    }

    sort(sec.begin(), sec.end());
    n = nN;

    for(int i = 0; i < n; i++){
        ricosD[i].first.second = lower_bound(sec.begin(), sec.end(), ricosD[i].first.second) - sec.begin();
    }

    SegmentTree st(n + 1);

    int lv = -1;
    vector<pair<int, ll> > level;
    for(int i = 0; i < n; i++){
        if(ricosD[i].first.first != lv){
            while(!level.empty()){
                st.update(level.back().first, level.back().second);
                level.pop_back();
            }
            lv = ricosD[i].first.first;
        }

        ll x = st.query(0, ricosD[i].first.second - 1) + ricosD[i].second;
        x = max(x, st.query(ricosD[i].first.second, ricosD[i].first.second));
        level.push_back({ricosD[i].first.second, x});
    }

    while(!level.empty()){
        st.update(level.back().first, level.back().second);
        level.pop_back();
    }

    cout << st.query(0, n - 1) << "\n";
    
	return 0;
}
