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

ll R,C;
vs grid;

vector<pair<ll, ll>> cur;
vvl status;
vl dx = {1,0}, dy = {0,1};
set<pair<ll, ll>> set_of_path;


ll dfs(pair<ll, ll> loc){
    ll i = loc.first, j = loc.second;
    // cout << i << ' ' << j << endl;
    if (status[i][j] != 0) return status[i][j];
    if (grid[i][j] != '.'){
        status[i][j] = -1;
        return -1;
    }
    
    for(ll ii=0; ii<2; ii++){
        ll ni = i+dy[ii], nj = j+dx[ii];
        if (ni>=R || nj >=C) continue;
        
        status[ni][nj] = dfs({ni,nj});
        if (status[ni][nj] == 1 && set_of_path.find({i,j}) != set_of_path.end()){
            status[i][j] = 1;
            return 1;
        }

        if (status[ni][nj] == 1 && set_of_path.find({i,j}) == set_of_path.end()){
            status[i][j] = -1;
            grid[i][j] = 'x';
            return -1;
        }
    }

    return -1;
}

void solve(){
    string guide; cin>>guide;
    grid.resize(0);
    status.resize(0); status.assign(R, vl(C, 0));
    status[0][0] = 1;
    
    set_of_path.clear();
    for(ll i=0; i<R; i++){
        string row; cin>>row;
        grid.push_back(row);
    }

    pair<ll, ll> loc = {0,0};
    for(ll i=0; i<guide.size(); i++){
        if (guide[i] == '>'){
            loc = {loc.first, loc.second+1};
            set_of_path.insert(loc);
            status[loc.first][loc.second] = 1;
            continue;
        }

        loc = {loc.first+1, loc.second};
        set_of_path.insert(loc);
        status[loc.first][loc.second] = 1;
    }


    loc = {0,0};
    for(ll i=0; i<guide.size(); i++){
        // cout << i << ' ';
        if (guide[i] == '>'){
            // cout << '>' << endl;
            if(loc.first+1 < R){
                ll result = dfs({loc.first+1, loc.second});
            }
            
            loc = {loc.first, loc.second+1};
            continue;
        }

        // cout << 'v' << endl;

        if(loc.second+1 < C){
            ll result = dfs({loc.first, loc.second+1});
        }
        loc = {loc.first+1, loc.second};
    }


    for(string s : grid){
        cout << s << endl;
    }

    // for(vl arr : status){
    //     for(ll num : arr){
    //         cout << num << ' ';
    //     }
    //     cout << endl;
    // }
}

int main(){
    while(cin>>R>>C){
        solve();
    }
    // int tc; cin>>tc;
    // for(int i=0; i<tc; i++){
    //     cout << "Case #" << i+1 << ": ";
    //     solve();
    // }

    return 0;
}
