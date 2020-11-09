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
#define MAXLL (1ll<<60)
#define MAXI (1<<30)

vector<iii> ranking;

bool comp(iii a, iii b){
    if (a.first.first != b.first.first){
        return a.first.first>b.first.first;
    } else if (a.first.second != b.first.second){
        return a.first.second>b.first.second;
    }

    return a.second>b.second;
}

void solve(){
    ranking.resize(0);
    int n,m; cin>>n>>m;
    string lookid; cin>>lookid;
    iii ls;
    for(int i=0; i<n; i++){
        string id; cin>>id;
        int one,two,three; cin>>one>>two>>three;
        ranking.push_back({{three,two},one});
        if (lookid==id){
            ls = {{three,two},one};
        }
    }

    sort(ranking.begin(),ranking.end(),comp);

    int urutan;
    for(int i=0; i<n; i++){
        if (ranking[i]==ls){
            urutan = i+1;
            break;
        }
    }

    cout << ( (urutan>m) ? "TIDAK" : "YA") << endl;

}

int main(){
    int tc; cin>>tc;
    for(int i=0; i<tc; i++){
        // cout << "Case #" << i+1 << ": ";
        solve();
    }

    return 0;
}