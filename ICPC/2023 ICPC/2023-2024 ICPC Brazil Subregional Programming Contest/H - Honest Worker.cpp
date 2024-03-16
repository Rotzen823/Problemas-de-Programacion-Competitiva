//Pura gente del coach moy
#include <bits/stdc++.h>

#define MOD 1000000007
#define ENDL '\n'
#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector <ll> vi;

const ll INF = 1e18;

template <class T>
class LazySegmentTree {
    private:
    int n;
    const T neutral = -INF; //Cambiar segun la operacion
    vector<T> A, st, lazy;

    inline int l(int p) { return (p << 1) + 1; }  // ir al hijo izquierdo
    inline int r(int p) { return (p << 1) + 2; }  // ir al hijo derecho

    //Cambiar segun la operacion
    T merge(T a, T b)
    {
        return max(a, b);
    }

    // Nota: Si se utiliza para el minimo o maximo de un rango no se le agrega el (end - start + 1)
    void propagate(int index, int start, int end, T dif) {
        st[index] += dif;
        if (start != end) {
            lazy[l(index)] += dif;
            lazy[r(index)] += dif;
        }
        lazy[index] = 0;
    }

    void add(int index, int start, int end, int i, int j, T val) {
        if(lazy[index]){
            propagate(index, start, end, lazy[index]);
        }
        
        if ((end < i) || (start > j))
            return;

        if (start >= i && end <= j) {
            propagate(index, start, end, val);
            return;
        }
        int mid = (start + end) / 2;

        add(l(index), start, mid, i, j, val);
        add(r(index), mid + 1, end, i, j, val);

        st[index] = merge(st[l(index)], st[r(index)]);
    }

    T query(int index, int start, int end, int i, int j) {
        if(lazy[index]){
            propagate(index, start, end, lazy[index]);
        }

        if (end < i || start > j)
            return neutral;
        if ((i <= start) && (end <= j))
            return st[index];

        int mid = (start + end) / 2;

        return merge(query(l(index), start, mid, i, j), query(r(index), mid + 1, end, i, j));
    }

    public:
    LazySegmentTree(int sz) : n(sz), st(4 * n, -INF), lazy(4 * n) {}
    // [i, j]
    void add(int i, int j, T val) { add(0, 0, n - 1, i, j, val); }  // [i, j]
    T query(int i, int j) { return query(0, 0, n - 1, i, j); }      // [i, j]
};

typedef struct Work{
    ll l, r, c;
}Work;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    ll s;
    cin >> n >> s;

    Work works[n];

    vector<pair<ll, ii> > events;
    for(int i = 0; i < n; i++){
        cin >> works[i].l >> works[i].r >> works[i].c;
        events.push_back({works[i].l, ii(1, i)});
        events.push_back({works[i].r + 1, ii(0, i)});
    }

    sort(events.begin(), events.end());
    LazySegmentTree<ll> st(n);

    ll lastDay = 0;
    ll ans = 0;

    ll val[n];

    for(auto e : events){
        ll day = e.first;
        int op = e.second.first;
        int id = e.second.second;

        if(day > lastDay){
            st.add(0, n - 1, (day - lastDay) * s);
            lastDay = day;
        }

        if(op){
            val[id] = max(ans, st.query(0, n - 1)) - works[id].c; 

            ll pre = st.query(id, id);
            st.add(id, id, -pre);
            st.add(id, id, val[id]);
        }
        else{
            ll pre = st.query(id, id);
            st.add(id, id, -pre);
            st.add(id, id, -INF);
            ans = max(ans, val[id] + (works[id].r - works[id].l + 1) * s);
        }
    }

    cout << ans << ENDL;

    
    return 0;
}
