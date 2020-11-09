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

ll m,n;
vvl grid;
vvl visited;
vl dx = {0,1,0,-1}, dy = {-1,0,1,0};

ll bfs(ll r, ll c){
    queue<pair<ll, ll>> q;
    visited[r][c] = 1;
    ll take = 1;
    q.push(make_pair(r,c));

    while(!q.empty()){
        pair<ll , ll> p = q.front(); q.pop();
        ll ur = p.first, uc = p.second;
        for(ll ii=0; ii<4; ii++){
            ll vr = ur+dy[ii], vc=uc+dx[ii];
            if (vr<0 || vr>=m || vc<0 || vc>=n) continue;
            if (visited[vr][vc] == 1) continue;
            if (grid[vr][vc] != grid[ur][uc]) continue;
            take++;
            visited[vr][vc] = 1;
            q.push(make_pair(vr,vc));
        }
    }

    return take;
}

void solve(){
    cin>>m>>n;
    grid.resize(0); grid.assign(m, vl(n, 0));
    visited.resize(0); visited.assign(m, vl(n, 0));
    for(ll i=0; i<m; i++){
        for(ll j=0; j<n; j++){
            ll temp; cin>>temp;
            grid[i][j] = temp;
        }
    }

    ll ans = 0;
    for(ll i=0; i<m; i++){
        for(ll j=0; j<n; j++){
            if (visited[i][j] == 1) continue;
            ll take = bfs(i,j);
            ans = max(take*(take-1), ans);
            // ll temp; cin>>temp;
            // grid[i][j] = temp;
        }
    }

    cout << ans << endl;
}

int main(){
    solve();

    return 0;
}
