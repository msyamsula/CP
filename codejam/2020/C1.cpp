#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<long long> vl;
typedef vector<vl> vvl;
typedef vector<string> vs;
typedef vector<vs> vvs;
#define MAXLL (1ll<<60)
#define MAXI (1<<30)

// vvi grid;
map<char, pair<int,int>> o;
map<pair<int,int>, vi> furTime;
map<pair<int,int>,int> myTime;
// int n,m;

// void walk(char c, int &x, int &y, int time){
//     int nx = x+o[c].first, ny = y+o[c].second;
//     if (!(nx < 0 || nx>=m || ny < 0 || ny >= n)) grid[n-1-ny][nx] = time+1;
//     x=nx; y=ny;
// }

void solve(){
    furTime.clear(); myTime.clear();
    int x, y; cin>>x>>y;
    furTime[{x,y}].push_back(0);
    string tour; cin>>tour;
    // n = y+tour.size()+1; m = x+tour.size()+1;
    // grid.resize(0); grid.assign(n, vi(m, -1));
    // grid[n-1-y][x] = 0;
    for(int i=0; i<tour.size(); i++){
        // cout << tour[i] << endl;
        // walk(tour[i],x,y,i);
        x+=o[tour[i]].first; y+=o[tour[i]].second;
        furTime[{x,y}].push_back(i+1);
    }

    int minTime = MAXI;
    for(pair<pair<int,int>, vi> a : furTime){
        pair<int,int> loc = a.first;
        int xx = loc.first, yy = loc.second;
        int lb = abs(xx)+abs(yy);
        vi temp = a.second;
        vi::iterator it = lower_bound(temp.begin(), temp.end(), lb);
        if (it == temp.end()) continue;
        minTime = min(*it,minTime);
    }

    // for(vi a:grid){
    //     for(int b:a){
    //         cout << b << ' ';
    //     }
    //     cout << endl;
    // }

    // int meetTime = MAXI;
    // for(int i=0; i<n; i++){
    //     for(int j=0; j<m; j++){
    //         if (grid[i][j] == -1) continue;
    //         int xx = j, yy = n-1-i;
    //         int mytime = xx+yy;
    //         if (mytime <= grid[i][j]){
    //             int currentTime = max(mytime, grid[i][j]);
    //             meetTime = min(currentTime, meetTime);
    //         }
    //     }
    // }

    if (minTime != MAXI)cout << minTime << endl;
    else cout << "IMPOSSIBLE" <<endl;

}

int main(){
    o = {
        {'N', {0,1}},
        {'E', {1,0}},
        {'S', {0,-1}},
        {'W', {-1,0}}
    };
    int tc; cin>>tc;
    for(int i=0; i<tc; i++){
        cout << "Case #" << i+1 << ": ";
        solve();
    }

    return 0;
}