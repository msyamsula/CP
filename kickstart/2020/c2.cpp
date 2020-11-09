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

map<char, vector<char>> graph;
vvl visited;
ll R,C;
vs grid;

void solve(){
    cin>>R>>C;
    graph.clear();
    visited.resize(0); visited.assign(R, vl(C, 0));
    grid.resize(0); grid.assign(R, string(C, ' '));
    for(ll i=0; i<R; i++){
        string temp; cin>>temp;
        grid[i] = temp;
    }

    set<char> characters;
    map<char, ll> indegree;
    for(ll i=0; i<R; i++){
        for(ll j=0; j<C; j++){
            characters.insert(grid[i][j]);
            if ( (i+1<R) && grid[i][j] != grid[i+1][j]){
                graph[grid[i+1][j]].push_back(grid[i][j]);
                indegree[grid[i][j]]++;
            }
        }
    }

    if (characters.size() == 1){
        cout << grid[0][0] << endl;
        return;
    }

    ll n = characters.size();
    queue<char> q;
    vector<char> toposort;
    for(char temp : characters){
        if (indegree[temp] == 0){
            q.push(temp);
            toposort.push_back(temp);
        }
    }

    while(!q.empty()){
        char u = q.front(); q.pop();
        for(char v : graph[u]){
            indegree[v]--;
            if(indegree[v] == 0){
                q.push(v);
                toposort.push_back(v);
            }
        }
    }

    if (toposort.size() < characters.size()){
        cout << -1 << endl;
        return;
    }

    for(char temp: toposort){
        cout << temp;
    }
    cout << endl;

    
}

vl a = {0,1,2,3,4,5};
vvl all_combination;
vl cur_combination;
vl used;

void combination(ll idx, ll size, ll nc){
    if (nc == size){
        all_combination.push_back(cur_combination);
        return;
    }

    for(ll i=idx; i<=a.size()-nc+size; i++){
        if (used[i] == 0){
            used[i] = 1;
            cur_combination.push_back(a[i]);
            combination(i, size+1, nc);
            cur_combination.pop_back();
            used[i] = 0;
        }
    }
}


int main(){
    // int tc; cin>>tc;
    // for(int i=0; i<tc; i++){
    //     cout << "Case #" << i+1 << ": ";
    //     solve();
    // }
    ll n = a.size();
    all_combination.resize(0); cur_combination.resize(0);
    used.resize(0); used.assign(n, 0);
    combination(0, 0,2);
    for(vl temp: all_combination){
        for (ll t : temp){
            cout << t << ' ';
        }
        cout << endl;
    }
    cout << endl;

    return 0;
}
