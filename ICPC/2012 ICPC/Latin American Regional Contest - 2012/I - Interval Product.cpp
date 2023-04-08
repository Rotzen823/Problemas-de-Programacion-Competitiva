#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> ii;
typedef vector<ii> vii;

class SegmentTree{
    private:
        int n;
        vector<int> st;
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
            st[v] = st[left(v)] * st[right(v)];
        }
        //Continuación en la siguiente página 
        int query(int sl, int sr, int v, int l, int r){
            if(sl > r || sr < l){
                return 1;
            }
 
            if(l >= sl && r <= sr){
                return st[v];
            }
 
            int m = (l + r) / 2;
 
            return query(sl, sr, left(v), l, m) * query(sl, sr, right(v), m + 1, r);
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
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n, q;
    
    while(cin >> n >> q){
        SegmentTree st(n);

        for(int k = 0; k < n; k++){
            int x;
            cin >> x;
            if(x > 0){
                x = 1;
            }
            else if(x < 0){
                x = -1;
            }
            st.update(k, x);
        }

        while(q--){
            char op;
            int l, r;
            int res;
            cin >> op >> l >> r;

            switch(op){
                case 'C':
                if(r > 0){
                    r = 1;
                }
                else if(r < 0){
                    r = -1;
                }
                st.update(l - 1, r);
                break;
                case 'P':
                res = st.query(l - 1, r - 1);

                if(res == 1){
                    cout << "+";
                }
                else if(res == -1){
                    cout << "-";
                }
                else{
                    cout << "0";
                }
                break;
            }
        }
        cout << "\n";
    }

    return 0;
}
