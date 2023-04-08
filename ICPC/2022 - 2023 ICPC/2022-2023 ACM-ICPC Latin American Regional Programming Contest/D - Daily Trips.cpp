#include <bits/stdc++.h>

using namespace std;

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, h, w;

    cin >> n >> h >> w;

    while(n--){
        char x, y;
        cin >> x >> y;
        if(x == 'Y' || !w){
            cout << "Y ";
            h--; w++;
        }
        else{
            cout << "N ";
        }

        if(y == 'Y' || !h){
            cout << "Y\n";
            w--; h++;
        }
        else{
            cout << "N\n";
        }
    }

    return 0;
}