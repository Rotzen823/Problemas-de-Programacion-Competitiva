#include<bits/stdc++.h>

using namespace std;
 
int main() {
    int n;
    while(scanf("%d", &n), !(n == -1)){
        string pal;
        string letras;
        bool let[30] = {0};
        int cLet = 0;
        cin >> pal >> letras;
        for(auto x : pal){
            if(!let[x - 'a']){
                cLet++;
                let[x - 'a'] = true;
            }
        }

        int lifes = 7;
        bool fin = false;
        printf("Round %d\n", n);
        for(auto x : letras){
            if(let[x - 'a']){
                let[x - 'a'] = false;
                cLet--;
                if(cLet <= 0){
                    printf("You win.\n");
                    fin = true;
                    break;
                }
            }
            else{
                lifes--;
                if(lifes <= 0){
                    printf("You lose.\n");
                    fin = true;
                    break;
                }
            }
        }

        if(!fin){
            printf("You chickened out.\n");
        }
    }

    return 0;
}