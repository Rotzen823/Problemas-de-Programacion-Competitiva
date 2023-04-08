#include<bits/stdc++.h>
#define MAX 1000005
 
using namespace std;
 
bool lista [MAX][30];
vector <bool> existL (30, false);
 
int main(){
    int n;
    cin >> n;
 
    for(int k = 0; k < n; k++){
        string ax;
        cin >> ax;
        
        for(char x : ax){
            lista[k][x - 'A'] = true;
        }
 
        existL[ax[0] - 'A'] = true;
    }
    
    bool b;
 
    vector<int> letFal;
 
    for(int k = 0; k < 26; k++){
        if(!existL[k]){
            letFal.push_back(k);
        }
    }
    
    for(int k = 0; k < n; k++){
        b = true;
        
        for(int x : letFal){
            if(lista[k][x]){
                b = false;
                break;
            }
        }
 
        if(b){
            cout << "Y\n";
            return 0;
        }
    }
 
    cout << "N\n";
 
    return 0;
}