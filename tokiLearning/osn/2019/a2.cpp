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

ll N, M;

void solve(){
    vl start, end;
    vvl person;
    for(ll i=0; i<N; i++){
        ll a,b; cin>>a>>b;
        start.push_back(a);
        end.push_back(b);
        person.push_back({a,b});
    }

    sort(start.begin(), start.end());
    sort(end.begin(), end.end());

    for(ll i=0; i<N; i++){
        ll a = person[i][0], b= person[i][1];
        auto it = upper_bound(start.begin(), start.end(), b);
        ll start_idx = distance(start.begin(), it);
        auto it_end = lower_bound(end.begin(), end.end(), a);
        ll end_idx = distance(end.begin(), it_end);
        cout << start_idx-end_idx-1 << endl;
    }

}

int main(){
    while(cin>>N>>M){
        solve();
    }

    return 0;
}
