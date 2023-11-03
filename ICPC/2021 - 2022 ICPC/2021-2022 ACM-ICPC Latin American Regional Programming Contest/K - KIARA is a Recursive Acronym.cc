#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n;
    cin >> n;
    string pal[n];
    bool let[26] = {0};

    for(int k = 0; k < n; k++){
        cin >> pal[k];
        let[pal[k][0] - 'A'] = true;
    }

    for(int k = 0; k < n; k++){
        bool flag = true;
        for(char x : pal[k]){
            if(!let[x - 'A']){
                flag = false;
                break;
            }
        }
        
        if(flag){
            cout << "Y\n";
            return 0;
        }
    }

    cout << "N\n";
    return 0;
}
