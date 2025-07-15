#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define pb push_back
#define sz size
#define all(x) x.begin(), x.end()
#define forn(i, n) for(int i = 0; i < n; i++)
#define forns(i, s, n) for(int i = s; i < n; i++)
#define ENDL '\n'
#define INF 1000000000
#define MOD 1000000007
#define MAX 1005

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    vi A(n), Ar(n), Al(n);
    vector<bool> taked(n + 1);
    
    for(int i = 0; i < n; i++){
        cin >> A[i];
        taked[A[i]] = true;
    }

    Al[0] = 0;
    for(int i = 1; i < n; i++){
        Al[i] = A[i] == 0 ? Al[i - 1] : i; 
    }

    Ar[n - 1] = n - 1;
    for(int i = n - 2; i >= 0; i--){
        Ar[i] = A[i] == 0 ? Ar[i + 1] : i; 
    }

    int l = 0, r = n - 1;
    bool flag = true;
    for(int i = 1; i <= n; i++){
        if(A[l] == i){
            l++;
            continue;
        }
        else if(A[r] == i){
            r--;
            continue;
        }

        if((A[l] != 0 && A[r] != 0) || taked[i]){
            flag = false;
            break;
        }

        if(A[l] == 0 && A[r] != 0){
            A[l] = i;
            l++;
        }
        else if(A[r] == 0 && A[l] != 0){
            A[r] = i;
            r--;
        }
        else if(A[Ar[l]] < A[Al[r]] || (Ar[l] == Al[r] && (Ar[l] - l) < (r - Al[r]))){
            A[l] = i;
            l++;
        }
        else{
            A[r] = i;
            r--;
        }
    }

    if(flag){
        cout << A[0];
        for(int i = 1; i < n; i++){
            cout << ' ' << A[i];
        }
        cout << ENDL;
    }
    else{
        cout << "*\n";
    }

    return 0;
}
