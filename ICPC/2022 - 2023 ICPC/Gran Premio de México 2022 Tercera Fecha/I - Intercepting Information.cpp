#include<bits/stdc++.h>

using namespace std;

int main() {
    int ax;
    bool res = true;

    for(int k = 0; k < 8; k++){
        scanf("%d", &ax);
        if(ax == 9){
            res = false;
        }
    }

    if(res){
        printf("S\n");
    }
    else{
        printf("F\n");
    }

    return 0;
}