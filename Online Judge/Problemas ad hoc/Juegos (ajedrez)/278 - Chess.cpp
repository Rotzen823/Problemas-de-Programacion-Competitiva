#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    scanf("%d", &n);

    while(n--){
        char ax;
        int a, b;
        scanf("%c", &ax);
        scanf("%c %d %d", &ax, &a, &b);
        int res;
        int x, y;
        switch(ax){
            case 'r':
            case 'Q':
            res = min(a, b);
            break;
            case 'K':
            x = a / 2;
            y = b / 2;
            if(a & 1){
                x++;
            }
            if(b & 1){
                y++;
            }
            res = x * y;
            break;
            case 'k':
            x = a * b;
            y = x / 2;
            if(x & 1){
                y++;
            }
            res = y;
        }

        printf("%d\n", res);
    }

    return 0;
}