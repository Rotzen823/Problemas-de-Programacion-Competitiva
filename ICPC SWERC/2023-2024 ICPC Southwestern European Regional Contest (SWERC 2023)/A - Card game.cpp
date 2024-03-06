#include<bits/stdc++.h>
#define INF 1000000
#define ENDL '\n';

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;

    vii cards;

    for(int i = 0; i < n; i++){
        char p;
        int x;
        cin >> p >> x;
        int id;
        switch(p){
            case 'S':
            id = 0;
            break;
            case 'W':
            id = 1;
            break;
            case 'E':
            id = 2;
            break;
            case 'R':
            id = 3;
            break;
            case 'C':
            id = 4;
            break;
        }
        cards.push_back(ii(id, x));
    }

    int per[] = {0, 1, 2, 3};
    int res = n;
    do{
        vii lis;
        for(int i = 0; i < n; i++){
            ii ax = cards[i];
            if(ax.first != 4){
                ax.first = per[ax.first];
            }

            if(lis.empty() || lis.back() <= ax){
                lis.push_back(ax);
            }
            else{
                int j = upper_bound(lis.begin(), lis.end(), ax) - lis.begin();
                lis[j] = ax;
            }
        }

        res = min(res, n - (int) lis.size());
    }while(next_permutation(per, per + 4));

    cout << res << "\n";
    
    return 0;
}
