#include <bits/stdc++.h>
#define MAX 205

using namespace std;

typedef vector<int> vi;

bool fri[MAX][MAX];
int it[MAX];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int s, l, n;
    cin >> s >> l >> n;
    string spices[s];
    unordered_map<string, int> ids;

    for(int k = 0; k < s; k++){
        cin >> spices[k];
    }

    sort(spices, spices + s);
    for(int k = 0; k < s; k++){
        ids[spices[k]] = k;
    }

    for(int k = 0; k < l; k++){
        string a, b;
        cin >> a >> b;
        int ida = ids[a];
        int idb = ids[b];
        fri[ida][idb] = fri[idb][ida] = true;
    }

    int ws[n];
    for(int k = 0; k < n; k++){
        string ax;
        cin >> ax;
        ws[k] = ids[ax];
    }

    vi res;
    while((int) res.size() < n){
        int ans = n, i = n;
        for(int k = 0; k < s; k++){
            for(; it[k] < n; it[k]++){
                if(ws[it[k]] == n || fri[ws[it[k]]][k]){
                    continue;
                }
                if(ws[it[k]] == k){
                    if(k < ans){
                        ans = k;
                        i = it[k];
                    }
                }
                break;
            }
        }
        res.push_back(ans);
        ws[i] = n;
    }

    cout << spices[res[0]];
    for(int k = 1; k < n; k++){
        cout << " " << spices[res[k]];
    }
    
    return 0;
}
