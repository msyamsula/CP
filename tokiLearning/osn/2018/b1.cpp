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

ll N;
vl row,col;
vvl row_pos;
vl used, row_sum, col_sum;
vvl grid;
bool found;

ll cost(){
    ll ans = 0;
    for(ll i=0; i<N; i++){
        if (row[i] != -1) ans += abs(row_sum[i] - row[i]);
        if (col[i] != -1) ans += abs(col_sum[i] - col[i]);
    }
    return ans;
}

bool is_valid(ll r, ll c){
    for(ll i=0; i<N; i++){
        if (row[i] == -1) continue;
        if (row_sum[i]>row[i]) return 0;
    }

    for(ll i=0; i<N; i++){
        if (col[i] == -1) continue;
        if (col_sum[i]>col[i]) return 0;
    }

    return 1;
}

void create(ll r, ll c){
    // if (row_sum[r] >= row[r] && r < N) return;
    // if (col_sum[c] >= col[c] && c < N) return;
    // cout << r << ' ' << c << endl;
    // cout << "grid: " << endl;
    // for(vl arr : grid){
    //     for(ll num : arr){
    //         cout << num << ' ';
    //     }
    //     cout << endl;
    // }
    // cout << "row_sum: ";
    // for(ll num : row_sum){
    //     cout << num << ' ';
    // }
    // cout << endl;
    // cout << "col_sum: ";
    // for(ll num : col_sum){
    //     cout << num << ' ';
    // }
    // cout << endl;
    // if (r==2) return;
    if (found) return;
    if (!is_valid(r,c)) return;
    if (r == N){
        if (cost() != 0) return;
        found = 1;
        cout << "grid: " << endl;
        for(vl arr : grid){
            for(ll num : arr){
                cout << num << ' ';
            }
            cout << endl;
        }
        // cout << endl;
        return;
    }

    vvl choice;
    for(ll i=1; i<=N*N; i++){
        if (used[i] == 1) continue;
        row_sum[r] += i;
        col_sum[c] += i;
        ll hn = cost();
        row_sum[r] -= i;
        col_sum[c] -= i;
        choice.push_back({hn,i});
    }

    sort(choice.begin(), choice.end());
    // cout << "choice: " << endl;
    // for( vl arr : choice){
    //     for(ll num : arr){
    //         cout << num << ' ';
    //     }
    //     cout << endl;
    // }

    ll n = choice.size();
    for(ll i=0; i<n; i++){
        ll num = choice[i][1];
        grid[r][c] = num;
        used[num] = 1;
        row_sum[r] += num;
        col_sum[c] += num;
        if ( row[r] != -1 && row_sum[r] >= row[r] && c<N-1){
            grid[r][c] = 0;
            used[num] = 0;
            row_sum[r] -= num;
            col_sum[c] -= num;
            continue;
        }
        if ( col[c] != -1 && col_sum[c] >= col[c] && r<N-1){
            grid[r][c] = 0;
            used[num] = 0;
            row_sum[r] -= num;
            col_sum[c] -= num;
            continue;
        }
        if (c+1 == N) create(r+1, 0);
        else create(r,c+1);
        grid[r][c] = 0;
        used[num] = 0;
        row_sum[r] -= num;
        col_sum[c] -= num;
    }
}

void solve(){
    cin>>N;
    row.resize(0);
    for(ll i=0; i<N; i++){
        string temp; cin>>temp;
        ll val = (temp == "-") ? -1 : stoll(temp);
        row.push_back(val);
    }

    col.resize(0);
    for(ll i=0; i<N; i++){
        string temp; cin>>temp;
        ll val = (temp == "-") ? -1 : stoll(temp);
        col.push_back(val);
    }
    cout << "row: ";
    for(ll num : row){
        cout << num << ' ';
    }
    cout << endl;

    cout << "col: ";
    for(ll num : col){
        cout << num << ' ';
    }
    cout << endl;
    used.resize(0); used.assign(N*N+1, 0);
    grid.resize(0); grid.assign(N, vl(N, 0));
    row_sum.resize(0); row_sum.assign(N, 0);
    col_sum.resize(0); col_sum.assign(N, 0);
    found = 0;
    create(0,0);
}

int main(){
    solve();
    // int tc; cin>>tc;
    // for(int i=0; i<tc; i++){
    //     cout << "Case #" << i+1 << ": ";
    //     solve();
    // }

    return 0;
}
