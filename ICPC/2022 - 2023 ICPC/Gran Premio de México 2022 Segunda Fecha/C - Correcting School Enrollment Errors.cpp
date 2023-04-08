#include <bits/stdc++.h>
#define MAX 100005
 
using namespace std;

typedef struct Alumno{
    priority_queue<int> materiasSol;
    priority_queue<int> materiasReq;
}Alumno;

map<int, Alumno> alumnos;

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    while(n--){
        int a, b, x;
        scanf("%d %d", &a, &b);
        while(b--){
            scanf("%d", &x);
            alumnos[a].materiasSol.push(-x);
        }
    }

    while(m--){
        int a, b, x;
        scanf("%d %d", &a, &b);
        while(b--){
            scanf("%d", &x);
            alumnos[a].materiasReq.push(-x);
        }
    }

    int mistakes = 0, nrec = 0, mis = 0;
    for(auto alm : alumnos){
        bool correct = true;
        int a = -1, b = -1;
        while(!alm.second.materiasSol.empty() || !alm.second.materiasReq.empty()){
            if(a == -1 && !alm.second.materiasSol.empty()){
                a = -alm.second.materiasSol.top(); 
                alm.second.materiasSol.pop();
            }

            if(b == -1 && !alm.second.materiasReq.empty()){
                b = -alm.second.materiasReq.top(); 
                alm.second.materiasReq.pop();
            }
            //printf("\n%d %d\n", a, b);
            if(a == b){
                a = -1;
                b = -1;
                continue;
            }

            if(correct){
                correct = false;
                mistakes++;
                printf("%d", alm.first);
            }

            if(a == -1){
                printf(" -%d", b);
                nrec++;
                b = -1;
                continue;
            }

            if(b == -1){
                printf(" +%d", a);
                mis++;
                a = -1;
                continue;
            }

            if(a > b){
                printf(" -%d", b);
                nrec++;
                b = -1;
            }
            else{
                printf(" +%d", a);
                mis++;
                a = -1;
            }
        }
        //printf("\n%d %d\n", a, b);

        if(a != -1){
            printf(" +%d", a);
            mis++;
            a = -1;
        }
        if(b != -1){
            printf(" -%d", b);
            nrec++;
            b = -1;
        }

        if(!correct){
            printf("\n");
        }
    }

    if(mistakes == 0){
        printf("GREAT WORK! NO MISTAKES FOUND!\n");
    }
    else{
        printf("MISTAKES IN %d STUDENTS: %d NOT REQUESTED, %d MISSED\n", mistakes, nrec, mis);
    }
    
    return 0;
}