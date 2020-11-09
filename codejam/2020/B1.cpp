#include<bits/stdc++.h>
using namespace std;
typedef vector<long> vi;
typedef vector<vi> vvi;
#define SIZE 201
#define INF 1000
vvi grid;

// void dfs(long x, long y, long move, long count){
//     cout << x << ' ' << y << endl;
//     grid[y][x] = min(grid[y][x],count);
//     long dx[] = {0, move, 0, -move};
//     long dy[] = {-move, 0, move,  0};
//     for(long i=0; i<4; i++){
//         long nx = x+dx[i], ny = y+dy[i];
//         if (nx < 0 || nx >= SIZE || ny < 0 || ny >= SIZE) continue;
//         // if (grid[ny][nx] != INF) continue;
//         dfs(nx, ny, move*2, count+1);
//     }
// }

void bfs(long x, long y){
    long n = (SIZE-1)/2;
    long num = y*SIZE+x;
    queue<long> q; q.push(num);
    grid[num/SIZE][num%SIZE] = 0;
    long dx[] = {0, 1, 0, -1};
    long dy[] = {-1, 0, 1,  0};
    while(!q.empty()){
        long u = q.front(); q.pop();
        long x = u%SIZE, y = u/SIZE;
        long move = pow(2,grid[y][x]);
        for(long i=0; i<4; i++){
            long nx = x+dx[i]*move, ny = y+dy[i]*move;
            if (nx < 0 || nx >= SIZE || ny < 0 || ny >= SIZE) continue;
            if (grid[ny][nx] != INF) continue;
            grid[ny][nx] = grid[y][x]+1;
            q.push(ny*SIZE+nx);
        }
    }
}

void printAns(long x, long y){
    // cout << x << ' ' << y << endl;
    long move = pow(2,grid[y][x]-1);
    long dx[] = {0, move, 0, -move};
    long dy[] = {-move, 0, move,  0};
    for(long i=0; i<4; i++){
        long nx = x+dx[i], ny = y+dy[i];
        if (nx < 0 || nx >= SIZE || ny < 0 || ny >= SIZE) continue;
        if (grid[ny][nx] == grid[y][x]-1){
            printAns(nx, ny);
            if (i == 0) cout << 'S';
            else if (i == 1) cout << 'W';
            else if (i == 2) cout << 'N';
            else if (i == 3) cout << 'E';
            break;
        }
    }
}

void solve(){
    // grid.resize(0);
    long xt,yt; cin>>xt>>yt;
    long comp = (SIZE-1)/2;
    long r = comp-yt, c = xt+comp;
    if (grid[r][c] == INF || grid[r][c] == 0){
        cout << "IMPOSSIBLE" << endl;
    } else {
        printAns(c,r);
        cout << endl;
    }
}

int main(){
    grid.assign(SIZE, vi(SIZE, INF));
    long comp = (SIZE-1)/2;
    // dfs(comp, comp, 1, 0);
    bfs(comp,comp);
    // for(vi temp : grid){
    //     for(long num : temp){
    //         cout << num << ' ';
    //     }
    //     cout << endl;
    // }
    long tc; cin>>tc;
    for(long i=0; i<tc; i++){
        cout << "Case #" << i+1 << ": ";
        solve();
    }

    return 0;
}