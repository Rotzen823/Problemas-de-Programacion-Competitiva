#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    int m, n, u, f, d, res = 0;

    cin >> m >> n >> u >> f >> d;

    u += d; d = u; f *= 2;

    bool bandera = false;
    char ax;
    while(n--){
        scanf("%c", &ax);
        scanf("%c", &ax);

        if(bandera){
            continue;
        }

        int x;

        switch(ax){
            case 'U':
            x = u;
            break;
            case 'F':
            x = f;
            break;
            case 'D':
            x = d;
            break;
        }

        if(m - x < 0){
            bandera = true;
        }
        else{
            m -= x;
            res++;
        }
    }

    cout << res << "\n";
 
    return 0;
}