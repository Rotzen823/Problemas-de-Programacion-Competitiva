#include <bits/stdc++.h>
 
#define ENDL '\n'
#define INF 1000000000
#define MOD 1000000009
#define MAX 10000
 
using namespace std;
 
typedef long long ll;
typedef pair <int, int> ii;
typedef vector <int> vi;
typedef vector <ii> vii;
 
int w, l;
priority_queue <int> pq;
 
void solve(int n){
 
    int sn = (int) sqrt(n);
 
    for(int i = 1; i <= sn; i++){
        if(n % i == 0){
            pq.push(i);
            pq.push(n / i);
        }
    }
}
 
int main(){
 
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
 
    int t;
    cin >> t;
 
    for(int i = 0; i < t; i++){
 
        cin >> w >> l;
 
        solve(__gcd(w, l - 2));
        solve(__gcd(w - 2, l));
        solve(__gcd(w - 1, l - 1));
        solve(__gcd(w - 1, __gcd(l - 2, l)));
        solve(__gcd(l - 1, __gcd(w, w - 2)));
 
        stack <int> st;
        st.push(pq.top());
 
        int ant = pq.top(); pq.pop();
 
        while(!pq.empty()){
 
            int aux = pq.top(); pq.pop();
 
            if(aux != ant){
                ant = aux;
                st.push(ant);
            }
 
        }
 
        cout << st.size();
        while(!st.empty()){
            cout << " " << st.top();
            st.pop();
        }
        cout << '\n';
 
    }
 
    return 0;
}
