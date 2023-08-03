#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long int ll;
 
vector <ll> coef;
 
void multi(ll x){
    int n = coef.size();
    int sig = coef[n-1];
 
    for(int k = n - 1; k > 0; k--){
        coef[k] = coef[k] * x - coef[k - 1];
    }
 
    coef[0] *= x;
    coef.push_back(-sig);
}
 
int main(){
    string s;
    int n;
    cin >> s;
    
    n = s.length();
 
    if(s[0] == 'A'){
        coef.push_back(-1);
    }
    else{
        coef.push_back(1);
    }
 
    for(int k = 1; k < n; k++){
        if(s[k] != s[k-1]){
            multi(k * 2 + 1);
        }
    }
    int grado = coef.size() - 1;
 
    cout << grado << "\n";
 
    cout << coef[grado];
    for(int k = grado - 1; k >= 0; k--){
        cout << " " << coef[k];
    }
 
    cout << "\n";
 
    return 0;
}
