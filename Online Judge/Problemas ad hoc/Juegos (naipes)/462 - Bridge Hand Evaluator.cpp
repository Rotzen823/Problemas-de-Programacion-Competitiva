#include <bits/stdc++.h>
 
using namespace std;

char op[50];

int main() {
    char ax;
    while(scanf("%[^\n]", op) != EOF){
        scanf("%c", &ax);
        int cartas[13][2];
        int palos[] = {0, 0, 0, 0, 0};
        bool stopped[] = {0, 0, 0, 0, 0};
        int r1 = 0;
        for(int k = 0, j = 0; k < 13; k++, j++){
            //printf("%c ", op[j]);
            switch(op[j]){
                case 'A':
                cartas[k][0] = 1;
                r1 += 4;
                break;
                case 'T':
                cartas[k][0] = 10;
                break;
                case 'J':
                r1++;
                cartas[k][0] = 11;
                break;
                case 'Q':
                r1 += 2;
                cartas[k][0] = 12;
                break;
                case 'K':
                r1 += 3;
                cartas[k][0] = 13;
                break;
                default:
                cartas[k][0] = (op[j] - '0');
                break;
            }
            j++;
            //printf("%c\n", op[j]);
            switch(op[j]){
                case 'S':
                cartas[k][1] = 1;
                palos[1]++;
                break;
                case 'H':
                cartas[k][1] = 2;
                palos[2]++;
                break;
                case 'D':
                cartas[k][1] = 3;
                palos[3]++;
                break;
                case 'C':
                cartas[k][1] = 4;
                palos[4]++;
                break;
            }
            j++;
        }

        for(int k = 0; k < 13; k++){
            switch(cartas[k][0]){
                case 13:
                if(palos[cartas[k][1]] <= 1){
                    r1--;
                }
                else{
                    stopped[cartas[k][1]] = true;
                }
                break;
                case 12:
                if(palos[cartas[k][1]] <= 2){
                    r1--;
                }
                else{
                    stopped[cartas[k][1]] = true;
                }
                break;
                case 11:
                if(palos[cartas[k][1]] <= 3){
                    r1--;
                }
                break;
                case 1:
                stopped[cartas[k][1]] = true;
                break;
            }
        }

        int r2 = 0;
        bool allStop = true;
        for(int k = 1; k <= 4; k++){
            switch(palos[k]){
                case 2:
                r2++;
                break;
                case 1:
                case 0:
                r2 += 2;
                break;
            }
            if(!stopped[k]){
                allStop = false;
            }
        }


        if((r1 + r2) < 14){
            printf("PASS\n");
        }
        else if(r1 >= 16 && allStop){
            printf("BID NO-TRUMP\n");
        }
        else{
            printf("BID ");
            int may = palos[1];
            char res = 'S';
            if(palos[2] > may){
                may = palos[2];
                res = 'H';
            }
            if(palos[3] > may){
                may = palos[3];
                res = 'D';
            }
            if(palos[4] > may){
                may = palos[4];
                res = 'C';
            }

            printf("%c\n", res);
        }

    }

    return 0;
}