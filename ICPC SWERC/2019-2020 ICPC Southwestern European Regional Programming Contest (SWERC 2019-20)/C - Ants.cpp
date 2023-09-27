#include <bits/stdc++.h>
#define MAX 1000005
 
using namespace std;
 
#define ENDL '\n'
typedef long long ll;
typedef pair<int,int>ii;
typedef vector<int>vi;
typedef vector<ii>vii;
 
int cont[MAX];
 
string s;
int num(){
    int n = s.length();
    int res = 0;
    for(int k = 0; k < n; k++){
        res *= 10;
        res += (s[k] - '0');
    }
    return res;
}
 
int main(){
 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
 
    int n;
    cin >> n;
 
    while(n--){
        cin >> s;
        if(s[0] == '-'){
            continue;
        }
        if(s.length() > 7){
            continue;
        }
        int res = num();
        if(res > 1000000){
            continue;
        }
        cont[res] = true;
    }
 
    for(int k = 0; k <= 1000001; k++){
        if(!cont[k]){
            cout << k << "\n";
            return 0;
        }
    }
    return 0;
}
