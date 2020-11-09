#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef vector<vector<long double> > vvld;
typedef vector<long double> vld;
#define for(i, s, inc) for(int i=0; i<s; i+=inc)


void showMatL(vvld a, int s){
    for(i,s,1){
        for(j,s,1){
            cout << a[i][j] << " \n"[j==s-1];
        }
    }
}

vvld major(vvld a, int s, int ii, int jj){
    
    vvld b;
    int idx=0;
    int idxj=0;
    for(i,s,1){
        if(i==ii){
            continue;
        }
        vld temp;
        for(j,s,1){
            if (j==jj){
                continue;
            }
            temp.push_back(a[i][j]);
        }
        b.push_back(temp);
    }



    return b;
}

ld determinant(vvld B, int s){
    ld det=0;
    if (s==1){
        det = B[0][0];
        return det;
    }

    for(i,s,1){
        vvld maj = major(B,s,0,i);
        int d = determinant(maj, s-1);
        det += pow(-1,i)*B[0][i]*d;
    }

    return det;
}

vvld transpose(vvld a, int s){
    vvld b;
    for(i,s,1){
        vld temp;
        for(j,s,1){
            temp.push_back(a[j][i]);
        }
        b.push_back(temp);
    }

    return b;
}

vvld inverse(vvld a, int s){
    ld det = determinant(a,s);
    vvld inv;
    for(i,s,1){
        vld temp;
        for(j,s,1){
            vvld maj = major(a,s,i,j);
            ld value = pow(-1,i+j)*determinant(maj, s-1)/det;
            temp.push_back(value);
        }
        inv.push_back(temp);
    }

    return transpose(inv, s);
}


int main(){

    vvld a = {
        {2,1,1,1,1,1},
        {4,2,1,1,1,1},
        {8,2,2,1,1,1},
        {16,4,2,2,1,1},
        {32,4,2,2,2,1},
        {64,8,4,2,2,2}
    };
    int s = 6;
    showMatL(a,s);
    vvld inv = inverse(a,s);
    cout << endl;
    showMatL(inv,s);

    return 0;
}

// int main(){
//     int T, W;
//     scanf("%i %i", &T, &W);
//     for(t,T,1){
//         vld ans;
//         for(w,W,1){
//             cout << w+1 << endl << flush;
//             ld a;
//             cin >> a;
//             ans.push_back(a)
//         }
//     }

//     return 0;
// }
