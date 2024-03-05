#include<bits/stdc++.h>
#define INF 1000000
#define ENDL '\n';

using namespace std;

typedef vector<int> vi;

class SegmentTree{
    private:
        int n;
        vi st;
        int left(int v){
            return (v << 1);
        }
        int right(int v){
            return (v << 1) + 1;
        }
        void build(int id, int value, int v, int l, int r){
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
            st[v] = st[left(v)] + st[right(v)];
        }

        int query(int i, int v, int l, int r){
            if(l == r){
                return l;
            }

            int m = (l + r) / 2;

            if(st[left(v)] >= i){
                return query(i, left(v), l, m);
            }
            else{
                return query(i - st[left(v)], right(v), m + 1, r);
            }
        }
 
    public:
        SegmentTree(int N){
            n = N;
            st.assign(4 * n, 0);
        }
 
        int query(int i){
            return query(i, 1, 0, n - 1);
        }
 
        void update(int id, int value){
            build(id, value, 1, 0, n - 1);
        }
};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;

    SegmentTree st(n);

    for(int i = 0; i < n; i++){
        st.update(i, 1);
    }

    vi a(n / 2);
    for(int i = 0; i < n / 2; i++){
        cin >> a[i];
    }

    vi resA(n / 2), resB(n / 2);
    for(int i = 0; i < n / 2; i++){
        int b;
        cin >> b;

        resA[i] = st.query(a[i]) + 1;
        st.update(resA[i] - 1, 0);
        resB[i] = st.query(b) + 1;
        st.update(resB[i] - 1, 0);
    }

    cout << resA[0];
    for(int i = 1; i < n / 2; i++){
        cout << ' ' << resA[i];
    }
    cout << ENDL;

    cout << resB[0];
    for(int i = 1; i < n / 2; i++){
        cout << ' ' << resB[i];
    }
    cout << ENDL;
    
    return 0;
}
