#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<long> vl;
typedef vector<vl> vvl;
typedef vector<string> vs;
typedef vector<vs> vvs;

vvi mat;
int ci, cj;
int Dx[4] = {0,-1,0,1}, Dy[4] = {-1,0,1,0};
int target;
bool found;

void moveSpi(int dir, int &num, int dis){
    int dx = Dx[dir], dy = Dy[dir];
    for(int i=1; i<=dis; i++){
        int ni = ci+dy, nj = cj+dx;
        if (ni<0 || ni>=mat.size() || nj<0 || nj>=mat.size()) return;
        num++;
        mat[ni][nj] = num;
        ci = ni; cj=nj;
        if (num == target){
            found = 1; return;
        }
        // cout << ci << ' ' << cj << endl;
    }
}

// void solve(int sz, int p){
//     if (p==1){
//         cout << "Line = " << sz/2+1 << ", column = " << sz/2+1 << '.' << endl;
//         return;
//     }
//     found = 0;
//     target = p;
//     mat.resize(0);
//     mat.assign(sz, vi(sz, -1));
//     int num = 1;
//     int i=0;
//     int up=0,left=0,down=0,right=0;
//     ci = sz/2; cj = sz/2;
//     mat[ci][cj] = num;
//     // for(vi temp: mat){
//     //     for(int num : temp){
//     //         cout << num << ' ';
//     //     }
//     //     cout << endl;
//     // }
//     // moveSpi(0,num,1);
//     // // num--;
//     // moveSpi(1,num,1);
//     // // num--;
//     // moveSpi(2,num,2);
//     while(num<sz*sz){
//         int dis;
//         if (i==0){
//             up = down+1;
//             dis = up;
//         } else if (i==1){
//             left = right+1;
//             dis = left;
//         } else if (i==2){
//             down = up+1;
//             dis = down;
//         } else if (i==3){
//             right = left+1;
//             dis = right;
//         }
//         // cout << i << ' ' << dis << endl;
//         moveSpi(i, num, dis);
//         if (found){
//             cout << "Line = " << sz-ci << ", column = " << cj+1 << '.' << endl;
//             for(vi temp: mat){
//                 for(int num : temp){
//                     cout << setw(3) << setfill('0') << num << ' ';
//                 }
//                 cout << endl;
//             }
//             return;
//         }
//         // num--;
//         i++;
//         i%=4;
//     }

//     for(vi temp: mat){
//         for(int num : temp){
//             cout << num << ' ';
//         }
//         cout << endl;
//     }
// }

void solve(int sz, int p){
    target = p;
    if (target == 1){
        cout << "Line = " << sz/2+1 << ", column = " << sz/2+1 << '.' << endl;
        return;
    }

    bool foundRing = 0;
    int ring = 1;
    while(!foundRing){
        if (p<=ring*ring){
            foundRing=1;
        } else {
            ring+=2;
        }
    }

    int partition = ring*ring - (ring-2)*(ring-2);
    int pl = partition/4;
}

int main(){
    int sz, p;
    while(cin>>sz>>p){
        if (!sz && !p) break;
        // cout << "Case #" << i+1 << ": ";
        solve(sz,p);
    }

    return 0;
}