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
void showV(vl temp){
    for(ll t : temp){
        cout << t << ' ';
    }
    cout << endl;
}

void showVV(vvl temp){
    for (vl t : temp){
        for(ll t1 : t){
            cout << t1 << ' ';
        }
        cout << endl;
    }
    cout << endl;
}

ll r,c,r0,c0,r1,c1;
vvl grid;
vvl visited;
vvl result;
vl dy = {0,-1,0,1}, dx = {-1,0,1,0};
ll mark;
bool found;

void dfs(ll y, ll x){
    visited[y][x] = 1;
    result[y][x] = mark;
    if (found) return;

    if (y==r1 && x==c1){
        found = 1;
        return;
    }


    bool recurse = 0;
    for(ll i=0; i<4; i++){
        ll ny = y + dy[i], nx = x + dx[i];
        if (ny < 0 || ny >= r || nx <0 || nx>=c) continue;
        if (visited[ny][nx] == 1) continue;
        if (i==2 && (grid[y][x] == 1 || grid[y][x] == 3)) continue;
        if (i==3 && (grid[y][x] == 2 || grid[y][x] == 3)) continue;
        if (i==0 && (grid[ny][nx] == 1 || grid[ny][nx] == 3)) continue;
        if (i==1 && (grid[ny][nx] == 2 || grid[ny][nx] == 3)) continue;
        recurse = 1;
        mark++;
        dfs(ny, nx);
        mark--;
        if (found) break;
    }

    if (!found){
        result[y][x] = -1;
    }
}

void printResult(){
    ll lenc = 4*c;
    cout << '+';
    for(ll i=0; i<lenc; i++){
        if (i%4 == 3) cout << '+';
        else cout << '-';
    }
    cout << endl;

    for(ll i=0; i<r; i++){
        cout << '|';
        for(ll j=0; j<c; j++){
            if (result[i][j] == -1) cout << "???";
            else if (result[i][j] == 0) cout << "   ";
            else if (result[i][j] == -2) cout << "  S";
            else if (result[i][j] == -3) cout << "  E"; 
            else cout << setw(3) << result[i][j];

            if (j==c-1) cout << '|';
            else if (grid[i][j] == 1 || grid[i][j] == 3) cout << '|';
            else cout << ' ';
        }
        cout << endl;

        cout << '+';
        for(ll j=0; j<c; j++){
            if (i==r-1) cout << "---+";
            else if (grid[i][j] == 2 || grid[i][j] == 3) cout << "---+";
            else cout << "   +";
        }
        cout << endl;
    }
}

void solve(ll tc){
    for(ll i=0; i<r; i++){
        for(ll j=0; j<c; j++){
            cin>>grid[i][j];
        }
    }
    r0--;c0--;r1--;c1--;
    visited.resize(0); visited.assign(r, vl(c, 0));
    result.resize(0); result.assign(r, vl(c, 0));
    mark = 1;
    result[r0][c0] = mark;
    found = 0;
    dfs(r0,c0);
    // result[r0][c0] = -2;
    // result[r1][c1] = -3;
    // showVV(result);
    cout << "Maze " << tc << endl << endl;
    printResult();
    cout << endl << endl;
}

int main(){

    ll tc=1;
    while(cin>>r>>c>>r0>>c0>>r1>>c1){
        if(!r && !c && !r0 && !c0 && !r1 && !c1) break;
        grid.resize(0); grid.assign(r,vl(c, 0));
        solve(tc);
        tc++;
    }
    // int tc; cin>>tc;
    // for(int i=0; i<tc; i++){
    //     cout << "Case #" << i+1 << ": ";
    //     solve();
    // }

    return 0;
}
