#include <bits/stdc++.h>
#define MAX 365

using namespace std;
typedef pair<int, int> ii;
typedef vector<ii> vii;

bool grades[MAX];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int h = 0, m = 0;
    grades[0] = true;
    for(int k = 0; k < 12; k++){
        for(int j = 1; j <= 60; j++){
            if(j % 12 == 0){
                h++;
                h %= 60;
            }

            m++;
            m %= 60;

            if(h > m){
                grades[(h - m) * 6] = true;
            }
            else{
                grades[(m - h) * 6] = true;
            }
        }
    }

    int n;

    while(cin >> n){
        if(grades[n]){
            cout << "Y\n";
        }
        else{
            cout << "N\n";
        }
    }

    return 0;
}
