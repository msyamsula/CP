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
}

ll r,c;
vs grid;
vl dx={0,1,0,-1}, dy={-1,0,1,0};
vvl grid_dist;

bool can_deliver(ll val){

    ll max_botright=-MAXLL;
    vl botright = {0,0};
    for(ll i=0; i<r; i++){
        for(ll j=0; j<c; j++){
            if (grid_dist[i][j]>=val){
                if (i+j>max_botright){
                    max_botright=i+j;
                    botright = {i,j};
                }
            }
        }
    }

    ll min_topleft=MAXLL;
    vl topleft = {r-1,c-1};
    for(ll i=0; i<r; i++){
        for(ll j=0; j<c; j++){
            if (grid_dist[i][j]>=val){
                if (i+j<min_topleft){
                    min_topleft=i+j;
                    topleft = {i,j};
                }
            }
        }
    }

    ll max_topright=-MAXLL;
    vl topright = {0,c-1};
    for(ll i=0; i<r; i++){
        for(ll j=0; j<c; j++){
            if (grid_dist[i][j]>=val){
                if (j-i>max_topright){
                    max_topright=j-i;
                    topright = {i,j};
                }
            }
        }
    }

    ll min_botleft=MAXLL;
    vl botleft = {r-1,0};
    for(ll i=0; i<r; i++){
        for(ll j=0; j<c; j++){
            if (grid_dist[i][j]>=val){
                if (j-i<min_botleft){
                    min_botleft=j-i;
                    botleft = {i,j};
                }
            }
        }
    }


    ll solution = MAXLL;
    for(ll i=0; i<r; i++){
        for(ll j=0; j<c; j++){
            if (grid[i][j] == '1') continue;
            ll man1 = abs(topright[0]-i) + abs(topright[1]-j);
            ll temp = man1;
            // solution = max(solution, man1);
            ll man2 = abs(topleft[0]-i) + abs(topleft[1]-j);
            // solution = max(solution, man2);
            temp = max(temp, man2);
            ll man3 = abs(botleft[0]-i) + abs(botleft[1]-j);
            // solution = max(solution, man3);
            temp = max(temp, man3);
            ll man4 = abs(botright[0]-i) + abs(botright[1]-j);
            // solution = max(solution, man4);
            temp = max(temp, man4);
            solution = min(solution, temp);
        }
    }

    solution = (solution == MAXLL) ? 0 : solution;
    // cout << "solution: " << solution << endl;
    if (solution <= val) return 1;
    return 0;
}

ll bin_search(ll a, ll b){
    if (a==b) return a;

    ll mid = (a+b)/2;
    if(can_deliver(mid)){
        return bin_search(a,mid);
    }

    return bin_search(mid+1,b);
}

void solve(){
    grid.resize(0);
    cin>>r>>c;
    grid.assign(r,string(c, ' '));
    for(ll i=0; i<r; i++){
        cin>>grid[i];
    }

    queue<vl> q;
    grid_dist.resize(0); grid_dist.assign(r,vl(c,0));
    vvl visited; visited.assign(r,vl(c,0));

    for(ll i=0; i<r; i++){
        for(ll j=0; j<c; j++){
            if (grid[i][j] == '1'){
                q.push({i,j});
                grid_dist[i][j] = 0;
                visited[i][j]=1;
            }
        }
    }

    ll max_dist = 0;

    while(!q.empty()){
        vl u = q.front(); q.pop();
        ll ui = u[0], uj=u[1];
        for(ll ii=0; ii<4; ii++){
            ll vi = ui+dy[ii], vj = uj+dx[ii];
            if (vi <0 || vi>=r || vj<0 || vj>=c) continue;
            if (visited[vi][vj] == 0){
                visited[vi][vj] = 1;
                grid_dist[vi][vj] = grid_dist[ui][uj]+1;
                q.push({vi,vj});
                max_dist = max(max_dist, grid_dist[vi][vj]);
            }
        }
    }

    // cout << "grid_dist:" << endl;
    // showVV(grid_dist);
    // cout << "max_dist: " << max_dist << endl;

    ll ans = bin_search(0,max_dist);
    cout << ans << endl;
    // cout << can_deliver(max_dist) << endl;
}

int main(){
    int tc; cin>>tc;
    for(int i=0; i<tc; i++){
        cout << "Case #" << i+1 << ": ";
        solve();
    }

    return 0;
}
