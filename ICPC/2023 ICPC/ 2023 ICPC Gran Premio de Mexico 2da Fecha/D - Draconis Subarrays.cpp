#include <bits/stdc++.h>
#define MAX 1000005

using namespace std;

typedef long long ll;
typedef vector<int> vi;

int b[MAX], T[MAX], P[MAX], n, m;  
void kmpPreprocess(){ 
    int i = 0, j = -1; b[0] = -1;  
    while(i < m){ 
        while(j >= 0 && P[i] != P[j]) j = b[j]; 
        i++; j++; 
        b[i] = j;
    }
}

int kmpSearch(){ 
    kmpPreprocess();

    int i = 0, j = 0, res = 0;   
    while(i < n){ 
        while(j >= 0 && T[i] != P[j]) j = b[j]; 
        i++; j++;
        if(j == m){
            res++;
            j = b[j];
        }
    }

    return res;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> m >> n;

    if(m == 1){
        cout << n << "\n";
        return 0;
    }

    m--; n--;
    int ax;
    cin >> ax;
    for(int k = 0; k < m; k++){
        int x;
        cin >> x;
        P[k] = x - ax;
        ax = x;
    }

    cin >> ax;
    for(int k = 0; k < n; k++){
        int x;
        cin >> x;
        T[k] = x - ax;
        ax = x;
    }

    cout << kmpSearch() << "\n";

	return 0;
}
