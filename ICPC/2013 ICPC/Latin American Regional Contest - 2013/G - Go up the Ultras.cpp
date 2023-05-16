#include <bits/stdc++.h>
#define MAX 100005
#define INF 100000000

using namespace std;

typedef long long ll;
typedef vector<int> vi;

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
            st[v] = min(st[left(v)], st[right(v)]);
        }
        //Continuación en la siguiente página 
        int query(int sl, int sr, int v, int l, int r){
            if(sl > r || sr < l){
                return INF;
            }
 
            if(l >= sl && r <= sr){
                return st[v];
            }
 
            int m = (l + r) / 2;
 
            return min(query(sl, sr, left(v), l, m), query(sl, sr, right(v), m + 1, r));
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
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n;
    const int d = 150000;
    cin >> n;

    int peaks[n];

    SegmentTree st(n);
    
    for(int k = 0; k < n; k++){
        cin >> peaks[k];
        st.update(k, peaks[k]);
    }

    int leftGreat[n], rightGreat[n];

    stack<int> pila;

    for(int k = 0; k < n; k++){
        while(!pila.empty() && peaks[pila.top()] <= peaks[k]){
            pila.pop();
        }

        if(pila.empty()){
            leftGreat[k] = -1;
        }
        else{
            leftGreat[k] = pila.top();
        }

        pila.push(k);
    }

    while(!pila.empty()){
        pila.pop();
    }

    for(int k = n - 1; k >= 0; k--){
        while(!pila.empty() && peaks[pila.top()] <= peaks[k]){
            pila.pop();
        }

        if(pila.empty()){
            rightGreat[k] = n;
        }
        else{
            rightGreat[k] = pila.top();
        }

        pila.push(k);
    }

    vector<int> res;
    for(int k = 0; k < n; k++){
        if(leftGreat[k] == -1 && rightGreat[k] == n){
            res.push_back(k + 1);
        }
        else if(leftGreat[k] == -1){
            if(peaks[k] - st.query(k, rightGreat[k]) >= d){
                res.push_back(k + 1);
            }
        }
        else if(rightGreat[k] == n){
            if(peaks[k] - st.query(leftGreat[k], k) >= d){
                res.push_back(k + 1);
            }
        }
        else if(peaks[k] - st.query(leftGreat[k], k) >= d && peaks[k] - st.query(k, rightGreat[k]) >= d){
            res.push_back(k + 1);
        }
    }

    cout << res[0];

    for(int k = 1; k < (int) res.size(); k++){
        cout << " " << res[k];
    }

    cout << "\n";

    return 0;
}
