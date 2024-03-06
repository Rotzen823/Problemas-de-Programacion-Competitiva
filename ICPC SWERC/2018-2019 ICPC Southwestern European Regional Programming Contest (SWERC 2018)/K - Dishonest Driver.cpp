#include <bits/stdc++.h>
#define ENDL '\n'
#define INF 1000000000
#define MOD 1000000007
#define MAX 705
#define se second
#define fi fisrt

using namespace std;

typedef long long ll;
typedef pair <int, int> ii;
typedef vector <int> vi;
typedef vector <ii> vii;

struct KMP{
    int N;
    string P;
    vi b;

    void init(string s){
        P = s;
        N = s.length();
        b.assign(N + 1, 0);
        kmpPreprocess();
    }
    
    void kmpPreprocess(){ 
        int i = 0, j = -1; b[0] = -1;  
        while(i < N){ 
            while(j >= 0 && P[i] != P[j]) j = b[j]; 
            i++; j++; 
            b[i] = j;
        }
    }   

    
    int kmpSearch(string T){ 
        int M = T.length();
        int i = 0, j = 0; 
        bool flag = false;  
        while(i < M){ 
            while(j >= 0 && T[i] != P[j]) j = b[j]; 
            i++; j++; 
            if(j == N){
                if(flag){
                    return i - j;
                }
                flag = true;
                j = b[j];
            }
        }
        return -1;
    }
};

int n;
string x;
int memo[MAX][MAX];

int dp(int i, int j){
    if(i + 1 == j){
        return 1;
    }

    if(memo[i][j]){
        return memo[i][j];
    }
    
    int ans = INF;
    for(int k = i + 1; k < j; k++){
        ans = min(ans, dp(i, k) + dp(k, j));
    }

    KMP kmp;
    string P = x.substr(i, j - i);
    string T = P + P;
    kmp.init(P);    

    int ac = kmp.kmpSearch(T);
    if(ac < (j - i)){
        ans = min(ans, dp(i, i + ac));
    }

    return memo[i][j] = ans;
}


int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> x;

    int res = dp(0, n);

    cout << res << "\n";

    return 0;
}
