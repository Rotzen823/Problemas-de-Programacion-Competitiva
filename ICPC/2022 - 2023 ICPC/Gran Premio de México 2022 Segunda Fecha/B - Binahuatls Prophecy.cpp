#include<bits/stdc++.h>
#define MAX 1000000

using namespace std;
vector<int> palind;
int p = 0;

void palindromos(int n, int i, int j){
    //printf("%d %d\n", i, j);
    if(i > j){
        palind.push_back(n);
        return;
    }

    palindromos(n, i + 1, j - 1);

    n |= (1 << i);
    n |= (1 << j);

    palindromos(n, i + 1, j - 1);
}

int main(){
    //palind.push_back(0);
    palind.push_back(1);
    for(int k = 1; k < 32; k++){
        int num = (1 << k) + 1;
        palindromos(num, 1, k - 1);
    }

    sort(palind.begin(), palind.end());
    
    p = palind.size();

    /*for(int k = 0; k < 10; k++){
        printf("%d: %d\n", k, palind[k]);
    }*/

    int n, a, b;

    scanf("%d", &n);

    while(n--){
        scanf("%d %d", &a, &b);

        int x = lower_bound(palind.begin(), palind.end(), a) - palind.begin();
        int y = lower_bound(palind.begin(), palind.end(), b) - palind.begin();
        //printf("%d %d %d %d\n",x, y, palind[x], palind[y]);
        if(palind[y] == b){
            y++;
        }
        //printf("%d %d %d\n", y, p, palind[y]);

        printf("%d\n", (y - x));
    }

	return 0;
}