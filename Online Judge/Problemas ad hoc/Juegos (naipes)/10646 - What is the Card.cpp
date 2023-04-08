#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);

    for(int i = 1; i <= n; i++){
        string ax;
        stack<string> pila;
        int y = 0;

        for(int k = 0; k < 27; k++){
            cin >> ax;
            pila.push(ax);
        }

        for(int k = 0; k < 3; k++){
            string carta = pila.top();
            pila.pop();

            int x = (carta[0] >= '0' && carta[0] <= '9') ? (carta[0] - '0') : 10;
            y += x;

            int lim = 10 - x;
            while(lim--){
                pila.pop();
            }
        }

        string ans = "";
        if(y <= pila.size()){
            int lim = pila.size() - y;
            while(lim--){
                pila.pop();
            }
            ans = pila.top();
            for(int k = 0; k < 25; k++){
                cin >> ax;
            }
        }
        else{
            int lim = y - pila.size() - 1;
            for(int k = 0; k < lim; k++){
                cin >> ax;
            }
            cin >> ans;

            for(int k = lim + 1; k < 25; k++){
                cin >> ax;
            }
        }   

        cout << "Case " << i << ": " <<ans << "\n";
    }
    

    return 0;
}