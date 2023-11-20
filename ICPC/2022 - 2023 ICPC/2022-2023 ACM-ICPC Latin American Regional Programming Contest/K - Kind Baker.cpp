#include <bits/stdc++.h>
#define MAX 105
 
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

int mat[MAX][MAX];
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int k;
    cin >> k;

    int t = 0;
    while(k > (1 << t)){
        t++;
    }

    int id = 1, x = 0;
    for(int i = 1; i <= 100; i++){
        if(id >= k){
            break;
        }
        for(int j = 1; j <= 100; j++){
            if(id >= k){
                break;
            }
            if(i & 1 || j == 100){
                mat[i][j] = (1 << t) - 1;
            }
            else{
                mat[i][j] = x++;
                id++;
            }
        }
    }

    cout << t << "\n";
    for(int p = 0; p < t; p++){
        vii res;
        for(int i = 1; i <= 100; i++){
            for(int j = 1; j <= 100; j++){
                if(mat[i][j] & (1 << p)){
                    res.push_back(ii(i, j));
                } 
            }
        }
        cout << res.size();
        for(ii d : res){
            cout << " " << d.first << " " << d.second;
        }
        cout << "\n";
    }
    
    return 0;
}
