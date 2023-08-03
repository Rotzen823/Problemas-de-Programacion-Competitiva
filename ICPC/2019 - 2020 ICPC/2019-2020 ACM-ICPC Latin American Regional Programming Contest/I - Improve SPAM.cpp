#include <bits/stdc++.h>
#define MAX 2005
#define MOD 1000000007
 
using namespace std;
 
typedef long long int ll;
 
vector< vector <int> > lists;
int n,l, gen = 0;
vector <ll> clin(MAX,0);
 
ll busqueda(int i = 1){
    if(clin[i]){
        return clin[i];
    }
 
    if(i > l){
        clin[i] = 1;
        gen++;
        return clin[i];
    }
 
    ll sum = 0;
 
    for(int x : lists[i]){
        sum += busqueda(x);
        sum %= MOD;
    }
 
    return clin[i] = sum;;
}
 
int main(){
    int x,ax;
    cin >> n >> l;
 
    lists.resize(l + 1);
 
    for(int k = 1; k <= l; k++){
        cin >> x;
        while(x--){
            cin >> ax;
            lists[k].push_back(ax);
        }
    }
 
    cout << busqueda() << " " << gen << "\n";
    return 0;
}
