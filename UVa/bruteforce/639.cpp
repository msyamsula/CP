#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<long long> vl;
typedef vector<vl> vvl;
typedef vector<string> vs;
typedef vector<vs> vvs;
typedef pair<int, int> ii;
typedef pair<ii, int> iii;
typedef long long ll;
#define MAXLL (1ll<<60)
#define MAXI (1<<30)

vs grid;
ll n;
ll ans;

void search(ll num){
    // num += 65;
    char big = num+65;
    char small = big+32;
    // cout << char(big) << endl;
    // for(string a : grid){
    //     cout << a << endl;
    // }
    // cout << endl;
    bool pass = 1;
    for(ll i=0; i<n; i++){
        for(ll j=0; j<n; j++){
            if (grid[i][j]=='.'){
                grid[i][j]=big;
                ll ii=i;
                while(1){ //up
                    if(grid[ii][j]=='.') grid[ii][j] = small;
                    ii--;
                    if (ii<0 || grid[ii][j]=='X') break;
                }

                ii=i;
                while(1){ //down
                    if(grid[ii][j]=='.') grid[ii][j] = small;
                    ii++;
                    if (ii>=n || grid[ii][j]=='X') break;
                }

                ll jj=j;
                while(1){ //bot
                    if(grid[i][jj]=='.') grid[i][jj] = small;
                    jj--;
                    if (jj<0 || grid[i][jj]=='X') break;
                }

                jj=j;
                while(1){ //bot
                    if(grid[i][jj]=='.') grid[i][jj] = small;
                    jj++;
                    if (jj>=n || grid[i][jj]=='X') break;
                }

                search(num+1);

                ii=i;
                while(1){ //up
                    if(grid[ii][j]==small) grid[ii][j] = '.';
                    ii--;
                    if (ii<0 || grid[ii][j]=='X') break;
                }

                // cout << i << ' ' << j << endl;
                
                ii=i;
                while(1){ //down
                    if(grid[ii][j]==small) grid[ii][j] = '.';
                    ii++;
                    if (ii>=n || grid[ii][j]=='X') break;
                }

                jj=j;
                while(1){ //bot
                    if(grid[i][jj]==small) grid[i][jj] = '.';
                    jj--;
                    if (jj<0 || grid[i][jj]=='X') break;
                }

                jj=j;
                while(1){ //bot
                    if(grid[i][jj]==small) grid[i][jj] = '.';
                    jj++;
                    if (jj>=n || grid[i][jj]=='X') break;
                }
                grid[i][j]='.';

                // for(string a : grid){
                //     cout << a << endl;
                // }

                pass = 0;

            }
        }
    }

    // vs gridC = grid;
    if(pass){
        // for(ll i=0; i<n; i++){
        //     for(ll j=0; j<n; j++){
        //         if (gridC[i][j]=='X') continue;
        //         if (gridC[i][j]>=97) gridC[i][j]='.';
        //         if (gridC[i][j]>=65) gridC[i][j]='1';
        //     }
        // }

        // for(string a : grid){
        //     cout << a << endl;
        // } cout << endl;

        // for(string a : gridC){
        //     cout << a << endl;
        // } cout << endl;
        // ans.insert(gridC);
        ans = max(ans,num);
    }
}

void solve(){
    ans = 0;
    grid.resize(n);
    for(ll i=0; i<n; i++){
        cin>>grid[i];
    }
    search(0);
    cout << ans << endl;
    // for(vs temp : ans){
    //     for(string a : temp){
    //         cout << a << endl;
    //     }
    //     cout << endl;
    // }

}

int main(){
    while(cin>>n){
        if(!n) break;
        solve();
    }
    // int tc; cin>>tc;
    // for(int i=0; i<tc; i++){
    //     cout << "Case #" << i+1 << ": ";
    //     solve();
    // }

    return 0;
}
