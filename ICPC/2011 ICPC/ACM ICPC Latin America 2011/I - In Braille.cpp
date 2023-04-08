#include <bits/stdc++.h>
 
using namespace std;

typedef long long ll; 
typedef pair<int, int> ii;
typedef vector<int> vi;

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    map<string, int> braile;

    braile["*....."] = 1;
    braile["*.*..."] = 2;
    braile["**...."] = 3;
    braile["**.*.."] = 4;
    braile["*..*.."] = 5;
    braile["***..."] = 6;
    braile["****.."] = 7;
    braile["*.**.."] = 8;
    braile[".**..."] = 9;
    braile[".***.."] = 0;

    string numbers[] = {".***..", "*.....", "*.*...", "**....", "**.*..", "*..*..",
        "***...", "****..", "*.**..", ".**...", ".***.."};

    int n;
    while(cin >> n){
        if(n == 0){
            break;
        }

        char op;
        string res[n];
        cin >> op;

        switch(op){
            case 'S':
            for(int k = 0; k < n; k++){
                char num;
                cin >> num;
                res[k] = numbers[num - '0'];
            }

            for(int k = 0; k < 3; k++){
                for(int j = 0; j < n; j++){
                    for(int i = k * 2; i < (k * 2) + 2; i++){
                        cout << res[j][i];
                    }
                    cout << " ";
                }
                cout << "\n";
            }
            break;
            case 'B':
            string ax;
            for(int k = 0; k < 3; k++){
                for(int j = 0; j < n; j++){
                    cin >> ax;
                    res[j] += ax;
                }
            }

            for(int k = 0; k < n; k++){
                cout << braile[res[k]];
            }
            cout << "\n";
            break;
        }
    }
    
    return 0;
}