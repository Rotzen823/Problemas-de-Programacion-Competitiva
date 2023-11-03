#include<bits/stdc++.h>
 
using namespace std;
 
int leerDia(string dia){
    switch(dia[0]){
        case 'M':
        return 1;
        break;
        case 'T':
        switch (dia[1]){
            case 'u':
            return 2;
            break;
            case 'h':
            return 4;
            break;
        }
        break;
        case 'W':
        return 3;
        break;
        case 'F':
        return 5;
        break;
        case 'S':
        switch(dia[1]){
            case 'a':
            return 6;
            break;
            case 'u':
            return 7;
            break;
        }
        break;
    }
 
    return -1;
}
 
int diaAtras(int d, int c){
    int res = c % 7;
    int ax = (7 + d - res) % 7;
    return ax;
}
 
int main(){
 
    string dia;
    int n, d, men = 100;
 
    cin >> dia >> n;
 
    d = leerDia(dia);
 
    while(n--){
        int x;
        cin >> x;
 
        int diaD = diaAtras(d, x);
 
        if(diaD == 2 && x > 30){
            x -= 30;
            diaD = 4;
        }
 
        if(diaD == 4 && x > 32){
            x -= 32;
            diaD = 1;
        }
 
        if(diaD == 3 && x > 30){
            x -= 30;
            diaD = 5;
        }
 
        if(diaD == 5 && x > 31){
            x -= 31;
            diaD = 1;
        }
 
        if(diaD == 1){
            x = x % 91;
 
            if(x > 60){
                diaD = 5;
                x -= 60;
            }
            else if(x > 30){
                diaD = 3;
                x-= 30;
            }
        }
 
        int res = 30 - x;
        if(diaD == 4){
            res += 2;
        }
        else if(diaD == 5){
            res++;
        }

        men = min(res, men);
    }
 
    cout << men << "\n";
    return 0;
}
