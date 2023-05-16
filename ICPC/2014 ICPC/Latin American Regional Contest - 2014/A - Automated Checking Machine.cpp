#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int num[5], num2[5];

    for(int k = 0; k < 5; k++){
        cin >> num[k];
    }

    for(int k = 0; k < 5; k++){
        cin >> num2[k];
    }

    for(int k = 0; k < 5; k++){
        if(num[k] == num2[k]){
            cout << "N\n";
            return 0;
        }
    }

    cout << "Y\n";
    return 0;
}
