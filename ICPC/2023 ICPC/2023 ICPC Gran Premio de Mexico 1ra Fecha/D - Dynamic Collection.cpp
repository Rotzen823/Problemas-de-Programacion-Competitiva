#include <bits/stdc++.h>
#define MOD 1000000007

using namespace std;

typedef long long ll;
typedef vector<int> vi;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

	int n, q;

    cin >> n >> q;

    vi array;
    array.assign(n, 0);

    for(int k = 0; k < n; k++){
        cin >> array[k];
    }

    sort(array.begin(), array.end());

    while(q--){
        int op, a, b;
        int i, izq, der, res;
        cin >> op;
        n = array.size();
        switch(op){
            case 1:
            cin >> a;

            if(binary_search(array.begin(), array.end(), a)){
                continue;
            }
            i = upper_bound(array.begin(), array.end(), a) - array.begin();

            if(i == n){
                array.push_back(a);
            }
            else{
                array[i] = a;
            }
            break;
            case 2:
            cin >> a >> b;
            izq = lower_bound(array.begin(), array.end(), a) - array.begin();
            der = upper_bound(array.begin(), array.end(), b) - array.begin();
            res = (n - izq) - (n - der);
            cout << res << "\n";
            break;
        }
    }

	return 0;
}
