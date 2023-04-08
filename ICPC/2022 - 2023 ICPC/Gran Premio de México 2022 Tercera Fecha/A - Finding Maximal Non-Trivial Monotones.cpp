#include<bits/stdc++.h>

using namespace std;

int main() {
    int n, c = 0;
    string pal;

    cin >> n >> pal;

    if(n == 1){
        printf("0\n");
        return 0;
    }
    if(pal[0] == 'a' && pal[1] == 'a'){
        c++;
    }

    for(int k = 1; k < n - 1; k++){
        if(pal[k] == 'a' && (pal[k - 1] == 'a' || pal[k + 1] == 'a')){
            c++;
        }
    }

    if(pal[n - 1] == 'a' && pal[n - 2] == 'a'){
        c++;
    }

    printf("%d\n", c);
    
    return 0;
}