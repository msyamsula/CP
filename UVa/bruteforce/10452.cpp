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
string word = "IEHOVA#";
vl dx = {-1, 0 , 1}, dy = {0, -1, 0};
vs command;

bool dfs(vl start, ll idx){
    if (idx == word.size()){
        for(ll i=0; i<command.size(); i++){
            if (i!=0) cout << ' ';
            cout << command[i];
        }
        cout << endl;
        return 1;
    }

    ll i = start[0], j = start[1];
    // cout << i << ' ' << j << ' ' << idx << endl;
    // for(string s : command){
    //     cout << s << ' ';
    // }
    // cout << endl;
    for(ll ii=0; ii<3; ii++){
        ll ni = i+dy[ii], nj = j +dx[ii];
        if (ni < 0 || nj <0 || nj >= C) continue;
        if (grid[ni][nj] == word[idx]){
            if (ii==0) command.push_back("left");
            if (ii==1) command.push_back("forth");
            if (ii==2) command.push_back("right");
            if (dfs({ni,nj}, idx+1)) return 1;
            command.pop_back();
        }
    }

    return 0;
}

void solve(){
    cin>>R>>C;
    grid.resize(0);
    for(ll i=0; i<R; i++){
        string temp; cin>>temp;
        grid.push_back(temp);
    }

    vl start;
    for(ll i=0; i<C; i++){
        if (grid[R-1][i] == '@'){
            start = {R-1, i};
            break;
        }
    }

    // cout << start[0] << ' ' << start[1] << endl;
    command.resize(0);
    dfs(start, 0);
}

int main(){
    int tc; cin>>tc;
    for(int i=0; i<tc; i++){
        // cout << "Case #" << i+1 << ": ";
        solve();
    }

    return 0;
}
