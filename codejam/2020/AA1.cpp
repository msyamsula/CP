#include<bits/stdc++.h>
using namespace std;
typedef vector<long> vl;
typedef vector<vl> vvl;
typedef queue<long> ql;
typedef pair<long, long> ll;
typedef queue<ll> qll;

vvl pt;
// vl visited;
// int sz = 101;
// int dy[] = {-1,-1,0,0,1,1};
// int dx[] = {-1,0,-1,1,0,1};

// void bfs(vvl pt, long is, long js){
//     qll q; q.push({is,js});
//     long idx = is*sz+js;
//     visited[idx] = 1;
//     while(!q.empty()){
//         long iu = q.front().first, ju = q.front().second; q.pop();
//         for(long i=0; i<6; i++){
//             long iv = iu+dx[i], jv = ju+dy[i];
//             if (iv <0 || iv>=sz || jv<0 || jv>=sz) continue;
//             if (pt[iv][jv] == 0) continue;
//         }
//     }     
// }

// void dfs(vvl pt, long iu, long ju, long &total){
//     long idx = iu*sz+ju;
//     visited[idx] = 1;
//     for(int i=0; i<6; i++){
//         long iv = iu+dx[i], jv = ju+dy[i];
//         if (iv <0 || iv>=sz || jv<0 || jv>=sz) continue;
//         if (pt[iv][jv] == 0) continue;
//         long vidx = iv*sz+jv;
//         if (visited[vidx] == 0){
//             dfs(pt, iv, jv, total);
//         }
//     }
// }

void solve(){
    int n; cin>>n;
    // visited.assign(sz*sz,0);
    cout << endl << 1 << ' ' << 1;
    n--;
    int next = 1;
    int i = 2;
    while(n >= next){
        n-=next;
        next +=1;
        cout << endl << i << ' ' << 2;
        i++;
    }
    
    i--;
    // cout << endl << i;
    for(int ii=0; ii<n;ii++){
        cout << endl << i << ' ' << 1;
        i++;
    }

    cout << endl;
    // if (n==501){
    //     cout << endl << 2 << ' ' << 1;
    //     cout << endl << 3 << ' ' << 2;
    //     cout << endl << 4 << ' ' << 2;
    //     for(int i=3; i<=n; i++){
    //         cout << endl << i << ' ' << 1;
    //     }
    //     cout << endl;

    //     return;
    // }

    // for(int i=1; i<=n; i++){
    //     cout << endl << i << ' ' << 1;
    // }
    // cout << endl;
}

int main(){
    // pt.assign(sz, vl(sz,0));
    // pt[0][0]=1;
    // pt[1][0]=1; pt[1][1]=1;
    // for(int i=2; i<sz; i++){
    //     pt[i][0]=1; pt[i][i]=1;
    //     for(int j=1; j<i; j++){
    //         pt[i][j] = pt[i-1][j]+pt[i-1][j-1];
    //     }
    // }

    // for( vl temp : pt){
    //     for(long num : temp){
    //         cout << num << ' ';
    //     }
    //     cout << endl;
    // }


    int tc; cin>>tc;
    for(int i=0; i<tc; i++){
        cout <<"Case #" << i+1 << ": ";
        solve();
    }

    return 0;
}