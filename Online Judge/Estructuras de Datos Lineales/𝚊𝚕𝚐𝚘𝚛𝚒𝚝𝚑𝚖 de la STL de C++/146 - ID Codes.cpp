#include <bits/stdc++.h>
 
using namespace std;

int main() {
    string ax;

    while(cin >> ax){
        if(ax == "#"){
            break;
        }

        if(next_permutation(ax.begin(), ax.end())){
            cout << ax << "\n";
        }
        else{
            cout << "No Successor\n";
        }
    }
    
    return 0;
}