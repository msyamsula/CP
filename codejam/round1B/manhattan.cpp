#include <bits/stdc++.h>
using namespace std;


int main(){

    int T;
    scanf("%i", &T);
    for (int t=0; t<T; t++){
        int P, Q, maxHor, maxVer;
        scanf("%i %i", &P, &Q);
        int manHor[Q];
        int manVer[Q];
        for (int q=0; q<Q+1; q++){
            manHor[q] = 0;
            manVer[q] = 0;
        }

        for (int p=0; p<P; p++){
            char direction;
            int x, y;
            scanf("%i %i %c", &x, &y, &direction);
            int i = Q-y;
            int j = x;

            if (direction == 'N'){
                for (int idx=0; idx<Q+1; idx++){
                    if (idx < i){
                        manVer[idx]++;
                    }
                }
            }

            if (direction == 'S'){
                for (int idx=0; idx<Q+1; idx++){
                    if (idx > i){
                        manVer[idx]++;
                    }
                }
            }

            if (direction == 'E'){
                for (int idx=0; idx<Q+1; idx++){
                    if (idx > j){
                        manHor[idx]++;
                    }
                }
            }

            if (direction == 'W'){
                for (int idx=0; idx<Q+1; idx++){
                    if (idx < j){
                        manHor[idx]++;
                    }
                }
            }


            // cout << "  ";
            // for (int count=0; count<Q+1; count++){
            //     // cout << manHor[i] << " ";
            //     printf("%i ", manHor[count]);
            // }
            // printf("\n");

            // for (int count=0; count<Q+1; count++){
            //     printf("%i\n", manVer[count]);
            //     // printf("\n");
            // }
        }

        int posX;
        int posY;
        maxHor = -1;
        maxVer = -1;
        for (int i=0; i<Q+1; i++){
            if (manHor[i]>maxHor){
                maxHor = manHor[i];
                posX = i; 
            }

            if (manVer[i]>=maxVer){
                maxVer = manVer[i];
                posY = Q-i; 
            }
        }
        printf("Case %c%i: %i %i\n", '#', t+1, posX, posY);
    }


    return 0;
}