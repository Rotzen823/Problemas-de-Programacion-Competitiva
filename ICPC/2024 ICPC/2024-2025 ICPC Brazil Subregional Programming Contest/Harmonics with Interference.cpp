#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define pb push_back
#define MOD 1000000007
#define INF 1000000000
#define MAX 1000
#define ENDL '\n'
#define SZ(x) ((int)(x).size())
#define ALL(x) begin(x), end(x)

typedef long long ll;
typedef pair <int, int> pi;
typedef vector <int> vi;
typedef vector <pi> vii;

int cBit = 0;

string n, m;
string M;
ll N;

bool check(){
    ll carry = 0;

    for(int i = 0; i < SZ(M); i++){
        carry <<= 1LL;
        if(M[i] == '1'){
            carry |= 1LL;
        }

        carry %= N;
    }

    return carry == 0;
}

void setValues(ll mask){
    int ln = SZ(n), lm = SZ(m);
    int ap = 0;
    M = m; N = 0;
    for(int i = 0; i < lm; i++){
        if(M[i] == '*'){
            M[i] = '0';
            if(mask & (1 << ap)){
                M[i] = '1';
            }
            ap++;
        }
    }

    for(int i = 0; i < ln; i++){
        int b = ln - i - 1;
        if(n[i] == '*'){
            if(mask & (1LL << ap)){
                N |= (1LL << b);
            }
            ap++;
        }
        else if(n[i] == '1'){
            N |= (1LL << b);
        }
    }
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);   

    cin >> m >> n;

    for(char x : m){
        if(x == '*'){
            cBit++;
        }
    }

    for(char x : n){
        if(x == '*'){
            cBit++;
        }
    }

    int lim = (1 << cBit);
    for(ll mask = 0; mask < lim; mask++){
        setValues(mask);

        if(check()){
            cout << M << ENDL;
            return 0;
        }
    }

    cout << "-1\n";

    return 0;
}
