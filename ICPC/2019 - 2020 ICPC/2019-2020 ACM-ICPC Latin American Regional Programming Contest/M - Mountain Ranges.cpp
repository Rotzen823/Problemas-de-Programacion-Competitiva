#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
    int n, x, an, act, c = 1, may = 1;
 
    cin >> n >> x;
    cin >> an;
 
    for(int k = 1; k < n; k++){
        cin >> act;
        if(an + x >= act){
            c++;
            if(c > may){
                may = c;
            }
        }
        else{
            c = 1;
        }
        
        an = act;
    }
 
    cout << may << "\n";
 
    return 0;
}
