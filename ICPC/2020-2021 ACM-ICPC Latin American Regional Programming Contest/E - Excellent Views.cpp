#include <bits/stdc++.h>

#define ENDL '\n'
#define MAX 1005
#define MOD 1000000007
#define INF 1000000000

using namespace std;

typedef long long ll;
typedef pair <int, int> ii;
typedef vector <int> vi;
typedef vector <ii> vii;

class Lazy{
    private:
        int n;
        vi st, lazy;
        int left(int v){
            return (v << 1);
        }
        int right(int v){
            return (v << 1) + 1;
        }

        int query(int sl, int sr, int v, int l, int r){
            if(sl > r || sr < l){
                return 0;
            }
            if(lazy[v]!=0){
                st[v]+=lazy[v]*(r-l+1);
                if(r!=l){
                    lazy[left(v)]+=lazy[v];
                    lazy[right(v)]+=lazy[v];
                }
                lazy[v]=0;
            }
            if(l>=sl && r<=sr){
                return st[v];
            }
            int m=(l+r)/2;
            return query(sl,sr,left(v),l,m)+ query(sl,sr,right(v),m+1,r);
        }

        void update(int sl, int sr, int value, int v, int l, int r){
            if(sl > r || sr<l){
                return;
            }

            if(lazy[v]){
                st[v]+=lazy[v]*(r-l+1);
                if(r!=l){
                    lazy[left(v)]+=lazy[v];
                    lazy[right(v)]+=lazy[v];
                }
                lazy[v]=0;
            }

            if(l>=sl && r<=sr){
                st[v]+=value*(r-l+1);
                if(r!=l){
                    lazy[left(v)]+=value;
                    lazy[right(v)]+=value;
                }
                return;
            }
            int m=(l+r)/2;
            update(sl,sr,value,left(v),l,m);
            update(sl,sr,value,right(v),m+1,r);
        }
        public:
        Lazy(int N){
            n=N;
            st.assign(4*n,0);
            lazy.assign(4*n,0);
        }
        int query(int l, int r){
            return query(l,r,1,0,n-1);
        }

        void update(int l, int r, int value){
            return update(l,r,value,1,0,n-1);
        }
};

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    int num[n];

    priority_queue<ii> q;

    for(int k = 0; k < n; k++){
        cin >> num[k];
        q.push(ii(num[k], k));
    }

    Lazy stl(n);

    int izq[n], der[n];

    stack <int> st;

    izq[0] = -1;
    st.push(0);

    for(int i = 1; i < n; i++){

        while(!st.empty()){
            if(num[st.top()] < num[i]){
                st.pop();
            }
            else{
                break;
            }
        }

        if(st.empty()){
            izq[i] = -1;
        }
        else{
            izq[i] = st.top();
        }
        st.push(i);
    }

    while(!st.empty()){
        st.pop();
    }

    der[n - 1] = n;
    st.push(n - 1);

    for(int i = n - 2; i >= 0; i--){

        while(!st.empty()){
            if(num[st.top()] < num[i]){
                st.pop();
            }
            else{
                break;
            }
        }

        if(st.empty()){
            der[i] = n;
        }
        else{
            der[i] = st.top();
        }
        st.push(i);
    }

    while(!q.empty()){
        int i = q.top().second; q.pop();
        if(izq[i] + 1 < i){
            if(izq[i] == -1){
                stl.update(0, i - 1, 1);
            }
            else{
                int j = (i - izq[i] - 1) / 2;
                if(j > 0){
                    stl.update(i - j, i - 1, 1);
                }
            }
        }

        if(der[i] - 1 > i){
            if(der[i] == n){
                stl.update(i + 1, n - 1, 1);
            }
            else{
                int j = (der[i] - i - 1) / 2;
                if(j > 0){
                    stl.update(i + 1, i + j, 1);
                }
            }
        }
    }

    cout << stl.query(0, 0);
    for(int k = 1; k < n; k++){
        cout << " " << stl.query(k, k);
    }
    cout << ENDL;

    return 0;
}
