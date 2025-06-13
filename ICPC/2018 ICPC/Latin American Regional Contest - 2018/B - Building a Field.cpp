#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define pb push_back
#define MOD 1000000007
#define INF 1000000000
#define MAX 1000
#define ENDL '\n'
#define SZ(x) ((int)(x).size())
#define ALL(x) begin(x), end(x)

typedef long long ll;
typedef pair <int, int> ii;
typedef vector <int> vi;
typedef vector <ll> vll;
typedef vector <ii> vii;

bool solve(vi &L, int n, int sumAll){
    if(sumAll & 1){
        return false;
    }

    sumAll /= 2;

    int i = 0, j = 0;
    int sum = 0;
    bool flag = false;
    while(j < 2 * n){
        if(sum == sumAll){
            flag = true;
            break;
        }
        else if(sum > sumAll){
            sum -= L[i];
            i++;
        }
        else{
            sum += L[j];
            j++;
        }
    }

    if(!flag){
        return false;
    }

    int k = j, lim = i + n - 1;
    int sumA = 0, sumB = 0;
    while(i < j && k < lim){
        if(sumA < sumB){
            sumA += L[i];
            i++;
        }
        else{
            sumB += L[k];
            k++;
        }
        if(sumA == sumB){
            return true;
        }
    }

    while(i < j){
        sumA += L[i];
        i++;
        if(sumA == sumB){
            return true;
        }
    }

    while(k < lim){
        sumB += L[k];
        k++;
        if(sumA == sumB){
            return true;
        }
    }
    return false;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);   

    int n;
    cin >> n;

    vi L(n * 2);
    int sumAll = 0;
    for(int i = 0; i < n; i++){
        cin >> L[i];
        L[i + n] = L[i];
        sumAll += L[i];
    }

    if(solve(L, n, sumAll)){
        cout << "Y\n";
    }
    else{
        cout << "N\n";
    }

    return 0;
}
