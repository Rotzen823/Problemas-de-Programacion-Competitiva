#include <bits/stdc++.h>
 
using namespace std;

typedef struct Nodo{
    int id;
    int problems;
    int penaltis;
}Nodo;

bool comparacion(Nodo a, Nodo b){
    if(a.problems != b.problems){
        return a.problems > b.problems;
    }

    if(a.penaltis != b.penaltis){
        return a.penaltis > b.penaltis;
    }

    return a.id < b.id;
}

char lect[100];
bool ready[105];
int penalties[105][15];
int ides[105];
vector<Nodo> res;

int main() {
    int t;
    char ax;

    scanf("%d", &t);
    scanf("%c", &ax);
    scanf("%c", &ax);

    bool bandera = false;

    while(t--){
        res.clear();
        int c = 0;

        for(int k = 0; k <= 100; k++){
            ready[k] = false;
            ides[k] = -1;
            for(int j = 1; j <= 9; j++){
                penalties[k][j] = 0;
            }
        }


        while(gets(lect)){
            if(lect[0] == '\0'){
                break;
            }
            //printf("%s\n", lect);
            int id, idP, min;
            char resp;
            sscanf(lect, "%d %d %d %c", &id, &idP, &min, &resp);

            if(!ready[id]){
                ready[id] = true;
                res.push_back({id, 0, 0});
                ides[id] = c++;
            }

            id = ides[id];
            if(penalties[id][idP] == -1){
                continue;
            }

            switch(resp){
                case 'C':
                res[id].problems++;
                res[id].penaltis += (min + (20 * penalties[id][idP]));
                penalties[id][idP] = -1;
                //printf("%d %d %d\n", res[id].id, res[id].problems, res[id].penaltis);
                break;
                case 'I':
                penalties[id][idP]++;
                break;
            }
        }

        sort(res.begin(), res.end(), comparacion);

        if(bandera){
            printf("\n");
        }
        else{
            bandera = true;
        }

        for(int k = 0; k < res.size(); k++){
            Nodo x = res[k];
            printf("%d %d %d\n", x.id, x.problems, x.penaltis);
        }
    }
    
    return 0;
}