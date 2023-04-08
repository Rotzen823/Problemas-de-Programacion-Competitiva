#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    string pista;

    getline(cin, pista);

    int saltos = 0, n = pista.length();

    for(int k = 0; k < n; k++){
        if(pista[k] == ' '){
            saltos++;
            int lim = min(k + 5, n - 1);
            for(int j = lim; j > k; j--){
                if(pista[j] == '#'){
                    k = j;
                    break;
                }
            }
        }
    }

    printf("%d\n", saltos);
 
    return 0;
}