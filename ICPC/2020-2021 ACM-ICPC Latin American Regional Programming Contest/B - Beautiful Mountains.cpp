#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define pb push_back
#define sz size
#define all(x) x.begin(), x.end()
#define forn(i, n) for(int i = 0; i < n; i++)
#define forns(i, s, n) for(int i = s; i < n; i++)
#define ENDL '\n'
#define INF 1000000000
#define MOD 1000000007
#define MAX 10005

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

vector<bool> validDiv;
vector<vi> divs;

void mark(int x, int minim){
    for(int div : divs[x]){
        if(div >= minim){
            validDiv[div] = false;
        }
    }
}

void check(vi &A, bool inverted){
    int n = A.sz() - 1;
    int lastDef = -1, comp = -1, state = 0, lastGreat = -1, inv = -1;
    if(A[1] != -1){
        lastDef = 1;
    }

    for(int i = 2; i <= n; i++){
        comp = lastDef == -1 ? A[i] : A[lastDef];
        if(A[i] == comp || A[i] == -1){
            if(state == 0){
                state = 1;
            }
            else if(state <= 2){
                state = 2;
            }
            else if(state == 3){
                state = 3;
            }
            else{
                state = 4;
            }
        }
        else if(A[i] < comp){
            if(state == 0 || state == 4){
                state = 4;
            }
            else {
                state = 3;
            }
        }
        else{ //A[i] > comp
            if(state <= 2){
                state = 1;
            }
            else{
                state = 4;
            }
        }

        if(state != 2 && state != 3){
            if(!inverted){
                mark(i, i);
            }
            else{
                mark(n - i, i);
            }
        }

        if(!inverted && A[i] != -1 && A[i - 1] != -1){
            if(A[i] > A[i - 1]){
                mark(i, 0);
            }
            else if(A[i] < A[i - 1]){
                mark(i - 2, 0);
            }
        }

        if(A[i] != -1){
            if(lastDef != -1 && A[lastDef] > A[i]){
                lastGreat = lastDef;
            }
            else if(lastDef != -1 && lastGreat != -1 && A[lastDef] < A[i]){
                
            }
            lastDef = i;
        }
        if(inv != -1){
            if(!inverted){
                mark(i, i - inv + 1);
            }
            else{
                mark(n - i, i);
            }
        }

    }
}

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    vi A(n + 1), Arev(n + 1);
    validDiv.assign(n + 1, true);

    for(int i = 1; i <= n; i++){
        cin >> A[i];
        Arev[n - i + 1] = A[i];
    }

    divs.assign(n + 1, vi());
    for(int i = 1; i <= n; i++){
        for(int j = i; j <= n; j += i){
            divs[j].pb(i);
        }
    }

    check(A, false);
    check(Arev, true);

    bool flag = false;
    for(int i = 3; i <= n; i++){
        if(validDiv[i]){
            flag = true;
            break;
        }
    }

    if(flag){
        cout << "Y\n";
    }
    else{
        cout << "N\n";
    }

    return 0;
}
