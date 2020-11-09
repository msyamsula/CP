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

ll n;
set<string> word;
string cur_word;
vs grid;
vvl visited;
vl dx = {0,1,1,1,0,-1,-1,-1}, dy = {1,1,0,-1,-1,-1,0,1};

bool comp(string a, string b){
    if (a.size() != b.size()) return a.size()<b.size();
    return a<b;
}

void search(ll i, ll j){
    // cout << i << ' ' << j << endl;
    visited[i][j] = 1;
    cur_word += grid[i][j];
    // cout << cur_word << endl;
    // for(vl a : visited){
    //     for(ll num : a){
    //         cout << num << ' ';
    //     }
    //     cout << endl;
    // }
    if (cur_word.size()>=3){
        // cout << cur_word << endl;
        word.insert(cur_word);
    }
    // bool recurse = 0;
    for(ll ii =0; ii<8; ii++){
        ll ni = i+dy[ii], nj=j+dx[ii];
        if (ni<0 || ni>=n || nj<0 || nj>=n) continue;
        if (grid[ni][nj] <= grid[i][j]) continue;
        if (visited[ni][nj] == 1) continue;
        // cout << ni << ' ' << nj << endl;
        // recurse = 1;
        search(ni, nj);
        visited[ni][nj] = 0;
        cur_word = cur_word.substr(0, cur_word.size()-1);
    }

    // visited[i][j] = 0;
    // cur_word = cur_word.substr(0, cur_word.size()-1);
}

void solve(){
    // word.resize(0);
    word.clear();
    cur_word.resize(0);
    grid.resize(0);
    visited.resize(0);
    cin>>n;
    grid.assign(n, string(n, ' '));
    visited.assign(n, vl(n, 0));
    for(ll i=0; i<n; i++){
        string temp; cin>>temp;
        grid[i] = temp;
    }
    for(ll i=0; i<n; i++){
        for(ll j=0; j<n; j++){
            // cout << i << ' ' << j << endl;
            search(i,j);
            // cout << cur_word << endl;
            cur_word = cur_word.substr(0, cur_word.size()-1);
            visited[i][j]=0;
        }
    }

    // if (word.empty()){
    //     cout << endl;
    //     return;
    // }

    // sort(word.begin(), word.end(), comp);
    vs ans;
    for(string s : word){
        ans.push_back(s);
    }

    sort(ans.begin(), ans.end(), comp);
    for(string s : ans){
        cout << s << endl;
    }
}

int main(){
    int tc; cin>>tc;
    for(int i=0; i<tc; i++){
        // cout << "Case #" << i+1 << ": ";
        if (i!=0) cout << endl;
        solve();
    }

    return 0;
}
