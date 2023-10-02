#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    map<string, int> mapa;

    for(int i = 0; i < n; i++){
        string ax;
        cin >> ax;
        mapa[ax]++;
    }

    for(auto x : mapa){
        if(x.second > n - x.second){
            cout << x.first << "\n";
            return 0;
        }
    }

    cout << "NONE\n";
	
    return 0;
}
