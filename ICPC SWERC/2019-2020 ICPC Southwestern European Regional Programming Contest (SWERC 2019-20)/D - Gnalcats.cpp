#include <bits/stdc++.h>
 
#define ENDL '\n'
#define INF 1000000000
#define MOD 1000000009
#define MAX 200005
 
using namespace std;
 
typedef long long ll;
typedef pair <int, int> ii;
typedef vector <int> vi;
typedef vector <ii> vii;

stack<int> st[2];
map<ii, int> hashing;
vii pares;

void D(int i){
    st[i].pop();
}

void S(int i){
    int ax, bx;
    ax = st[i].top(); st[i].pop();
    bx = st[i].top(); st[i].pop();
    st[i].push(ax); st[i].push(bx);
}

bool U(int i){
    int ax;
    ax = st[i].top(); st[i].pop();
    if(pares[ax].second == -1){
        return false;
    }
    st[i].push(pares[ax].second);
    st[i].push(pares[ax].first);
    return true;
}

bool simular(string &a, int i){
    int ax, bx, cx;
    ii nPar;
    for(char x : a){
        switch(x){
            case 'C':
                ax = st[i].top();
                st[i].push(ax);
                break; 
            case 'D':
                D(i);
                break;
            case 'S':
                S(i);
                break; 
            case 'P':
                ax = st[i].top(); st[i].pop();
                bx = st[i].top(); st[i].pop();
                nPar = ii(ax, bx);
                if(hashing.count(nPar)){
                    cx = hashing[nPar];
                }
                else{
                    cx = pares.size();
                    pares.push_back(nPar);
                    hashing[nPar] = cx;
                }
                st[i].push(cx);
                break;
            case 'U':
                if(!U(i)){
                    return false;
                }
                break;
            case 'R':
                if(!U(i)){
                    return false;
                }
                D(i);
                break;
            case 'L':
                if(!U(i)){
                    return false;
                }
                S(i);
                D(i);
                break;
        }
    }

    return true;
}
 
int main(){
 
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    string aS, bS;
    cin >> aS >> bS;
    
    int maxL = max(aS.length(), bS.length()) + 5;

    for(int k = maxL - 1; k >= 0; k--){
        ii ax = ii(k, -1);
        hashing[ax] = pares.size();
        st[0].push(pares.size());
        st[1].push(pares.size());
        pares.push_back(ax);
    }

    bool a = simular(aS, 0), b = simular(bS, 1);
    if(!a && !b){
        cout << "True\n";
        return 0;
    }

    if(!a || !b || st[0].size() != st[1].size()){
        cout << "False\n";
        return 0;
    }

    while(!st[0].empty()){
        int ax = st[0].top(); st[0].pop();
        int bx = st[1].top(); st[1].pop();
        if(ax != bx){
            cout << "False\n";
            return 0;
        }
    }
    
    cout << "True\n";
    return 0;
}
