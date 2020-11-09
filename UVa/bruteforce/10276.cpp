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
vector<vector<ll>> pegs;
ll max_ball;

void search(ll idx){
    bool recurse = 0;
    for(ll i=0; i<N; i++){
        if (pegs[i].empty()){
            pegs[i].push_back(idx);
            recurse = 1;
            search(idx+1);
            pegs[i].pop_back();
            break;
        }

        ll top_ball = *pegs[i].rbegin();
        double sqrt = pow(top_ball+idx, 0.5);
        if (floor(sqrt) == sqrt){
            pegs[i].push_back(idx);
            recurse = 1;
            search(idx+1);
            pegs[i].pop_back();
            break;
        }
    }

    if(!recurse){
        // for(vector<ll> st : pegs){
        //     for(ll num : st){
        //         cout << num << ' ';
        //     }
        //     cout << endl;
        // }
        // cout << endl;
        max_ball = max(max_ball, idx-1);
        return;
    }
}

void solve(){
    cin>>N;
    pegs.resize(0);
    pegs.resize(N);
    max_ball = 0;
    search(1);
    cout << max_ball << endl;
}

int main(){
    int tc; cin>>tc;
    for(int i=0; i<tc; i++){
        // cout << "Case #" << i+1 << ": ";
        solve();
    }

    return 0;
}
