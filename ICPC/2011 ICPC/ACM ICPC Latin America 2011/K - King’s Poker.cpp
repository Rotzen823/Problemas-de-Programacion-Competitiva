#include <bits/stdc++.h>
 
using namespace std;

typedef long long ll; 
typedef pair<int, int> ii;
typedef vector<int> vi;

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int a, b, c;
    while(cin >> a >> b >> c){
        if(a == 0 && b == 0 && c == 0){
            break;
        }

        if(a == 13 && b == 13 && c == 13){
            cout << "*\n";
            continue;
        }

        if(a == b && a == c && b == c){
            cout << a + 1 << " " << b + 1 << " " << c + 1 << "\n";
            continue;
        }

        int p = 0, ax = 0;
        if(a == b){
            p = a;
            ax = c;
        }
        else if(a == c){
            p = a;
            ax = b;
        }
        else if(b == c){
            p = b;
            ax = a;
        }
        else{
            cout << "1 1 2\n";
            continue;
        }

        if(ax + 1 == p || ax == 13){
            if(p == 13){
                cout << "1 1 1\n";
                continue;
            }
            else if(ax >= 12){
                p++;
                ax = 1;
            }
            else{
                ax += 2;
            }
        }
        else{
            ax++;
        }

        if(p < ax){
            cout << p << " " << p << " " << ax << "\n";
        }
        else{
            cout << ax << " " << p << " " << p << "\n";
        }
    }
    
    return 0;
}