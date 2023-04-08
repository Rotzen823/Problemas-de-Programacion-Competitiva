#include<bits/stdc++.h>

using namespace std;
 
int main() {
    string marca;

    while(getline(cin, marca), !(marca == "Game Over")){
        int n = 0;
        int tiros[30][2] = {0};
        int ax = 0;
        for(int k = 0; k < 10; k++){
            if(marca[ax] == 'X'){
                tiros[n++][0] = 10;
                ax += 2;
                continue;
            }
            else{
                tiros[n++][0] = marca[ax] - '0';
                ax += 2;
            }

            if(marca[ax] == '/'){
                tiros[n][1] = 1;
                tiros[n][0] = 10 - tiros[n - 1][0];
                n++;
            }
            else{
                tiros[n++][0] += (marca[ax] - '0');
            }

            ax += 2;
        }

        if(tiros[n - 1][0] == 10 || tiros[n - 1][1]){
            if(marca[ax] == 'X'){
                tiros[n][0] = 10;
            }
            else{
                tiros[n][0] = marca[ax] - '0';
            }

            if(tiros[n - 1][0] == 10){
                ax += 2;
                if(marca[ax] == 'X'){
                    tiros[n + 1][0] = 10;
                }
                else if(marca[ax] == '/'){
                    tiros[n + 1][0] = 10 - tiros[n][0];
                }
                else{
                    tiros[n + 1][0] = (marca[ax] - '0');
                }
            }
        }

        int sum = 0;
        for(int k = n - 1; k >= 0; k--){
            if(tiros[k][1]){
                sum += (tiros[k][0] + tiros[k + 1][0]);
            }
            else if(tiros[k][0] == 10){
                sum += (10 + tiros[k + 1][0] + tiros[k + 2][0]);
            }
            else{
                sum += tiros[k][0];
            }
        }

        printf("%d\n", sum);
    }

    return 0;
}