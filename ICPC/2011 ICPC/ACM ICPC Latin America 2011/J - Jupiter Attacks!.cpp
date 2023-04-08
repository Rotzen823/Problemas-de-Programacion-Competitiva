#include <bits/stdc++.h>
#define MAX 100005
 
using namespace std;

typedef long long ll; 
typedef pair<int, int> ii;
typedef vector<int> vi;

ll B, P;
ll poten[MAX];

void potencias(int L){
    ll ax = 1;
    for(int k = 0; k < L; k++){
        poten[k] = ax;
        ax = (ax * B) % P;
    }
}

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
            ll ax = (st[left(v)] * poten[r - m]) % P;
            st[v] = (ax + st[right(v)]) % P;
        }

        ll query(int sl, int sr, int v, int l, int r){
            if(sl > r || sr < l){
                return 0;
            }
 
            if(l >= sl && r <= sr){
                return st[v];
            }
 
            int m = (l + r) / 2;

            ll op1, op2;
            op1 = query(sl, sr, left(v), l, m);
            op2 = query(sl, sr, right(v), m + 1, r);

            if(m < sl){
                return op2;
            }

            if((m + 1) > sr){
                return op1;
            }

            ll ax = (op1 * poten[min(sr, r) - m]) % P;
 
            return (ax + op2) % P;
        }
 
    public:
        SegmentTree(int N){
            n = N;
            st.assign(4 * n, 0);
        }
 
        int query(int l, int r){
            return query(l, r, 1, 0, n - 1);
        }
 
        void update(int id, int value){
            return build(id, value, 1, 0, n - 1);
        }
};


int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int L, N;

    while(cin >> B >> P >> L >> N){
        if(B == 0 && P == 0 && L == 0 && N == 0){
            break;
        }
        SegmentTree st(L);
        potencias(L);

        while(N--){
            char op;
            cin >> op;
            int a, b;
            ll v;

            switch(op){
                case 'E':
                cin >> a >> v;
                st.update(a - 1, v);
                break;
                case 'H':
                cin >> a >> b;
                cout << st.query(a - 1, b - 1) << "\n";
                break;
            }
        }
        cout << "-\n";
    }
    
    return 0;
}