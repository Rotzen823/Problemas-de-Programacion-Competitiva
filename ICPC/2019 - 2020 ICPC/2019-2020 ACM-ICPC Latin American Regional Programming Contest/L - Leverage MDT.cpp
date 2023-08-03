#include <bits/stdc++.h>
#define MAX 1005
 
using namespace std;
 
int terr[MAX][MAX];
int n,m;
 
bool check(int x){
    for(int j = 0; j < m; j++){
        int c = 0;
        for(int k = 0; k < n; k++){
            if(terr[k][j] >= x){
                c++;
            }
            else{
                c = 0;
            }
 
            if(c >= x){
                return true;
            }
        }
    }
    return false;
}
 
int main(){
    string fila;
    cin >> n >> m;
 
    for(int k = 0; k < n; k++){
        cin >> fila;
        terr[k][0] = 1;
        for(int j = 1; j < m; j++){
            if(fila[j] == fila[j-1]){
                terr[k][j] = terr[k][j-1] + 1;
            }
            else{
                terr[k][j] = 1;
            }
        }
    }
 
    int st = 1, fn = min(n,m), med;
 
    while(st < fn){
        med = (st + fn) / 2 + 1;
        //cout << st << " " << fn << " " << med << "\n";
        if(check(med)){
            st = med;
        }
        else{
            fn = med - 1;
        }
    }
 
    cout << (st * st) << "\n";
	
    return 0;
}
