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

ll y,p;
vl election;

void solve(){
    cin>>p;
    election.resize(0);
    for(ll i=0; i<p; i++){
        ll temp; cin>>temp;
        election.push_back(temp);
    }

    sort(election.begin(), election.end());

    auto it = election.begin();
    ll pope_max = 0;
    ll pope_start,pope_end;
    for(it = election.begin(); it!=election.end(); it++){
        ll start = *it;
        ll end = start+y-1;
        auto nit = upper_bound(election.begin(), election.end(), end);
        ll pope_cnt = distance(it, nit);
        if (pope_cnt > pope_max){
            pope_max = pope_cnt;
            pope_start = start;
            nit--;
            pope_end = *nit;
        }
    }

    cout << pope_max << ' ' << pope_start << ' ' << pope_end << endl;
}

int main(){
    while(cin>>y){
        solve();
    }

    return 0;
}
