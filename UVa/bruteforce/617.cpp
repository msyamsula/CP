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
vvl arr;
vector<double> len;
vvl times;

void solve(){
    arr.resize(0); arr.resize(n);
    double maxl= -1;
    for(ll i=0; i<n; i++){
        double l;
        ll g,y,r;
        cin>>l>>g>>y>>r;
        ll sum3 = g+y+r, sum2=g+y;
        arr[i] = {sum2,sum3};
        maxl = max(maxl, l);
        len.push_back(l);
    }
    // for(vl temp:arr){
    //     for(ll num:temp){
    //         cout << num << ' ';
    //     }
    //     cout << endl;
    // }

    ll maxd = ceil(maxl*3600/30);
    // ll maxd=20;
    times.resize(0); times.assign(n, vl(maxd+1, 0));
    for(ll k=0; k<n; k++){
        for(ll i=1; i<=maxd; i++){
            if((i-1)%arr[k][1] < arr[k][0]) times[k][i]=1;
        }
    }

    // for(vl temp: times){
    //     for(ll num : temp){
    //         cout << num << ' ';
    //     }
    //     cout << endl;
    // }

    vl ans;
    for(ll v=30; v<=60; v++){
        bool can = 1;
        for(ll k=0; k<n; k++){
            ll t = floor(len[k]*3600/v);
            // cout << t << endl;
            if(times[k][t] == 0){
                // cout<<'-'<<endl;
                can=0;
                break;
            };
        }
        // cout << '-' << endl;
        if (can) ans.push_back(v);
    }

    if (ans.empty()){
        cout << "No acceptable speeds." << endl;
        return;
    }

    // for(ll num : ans) cout << num << ' ';
    vvl tidy; tidy.resize(1);
    ll curr = 0, idx = 0;
    for(ll i=1; i<ans.size(); i++){
        if (ans[i]-ans[i-1]==1) continue;
        else {
            tidy[idx].push_back(ans[i-1]);
            tidy.push_back({ans[i]});
            idx++;
        }
    }
    tidy[idx].push_back(*ans.rbegin());
    // cout << endl;
    // for(vl temp:tidy){
    //     for(ll num : temp){
    //         cout << num << ' ';
    //     }
    //     cout << endl;
    // }

    for(ll i=0; i<tidy.size(); i++){
        if(i!=0) cout << ", ";
        if (tidy[i].size()==1) cout << tidy[i][0];
        else cout << tidy[i][0] << '-' << tidy[i][1];
    }
    cout << endl;
}

int main(){
    ll i=1;
    while(cin>>n){
        if(n==-1) break;
        cout << "Case " << i << ": ";
        solve();
        i++;
    }
    // int tc; cin>>tc;
    // for(int i=0; i<tc; i++){
    //     cout << "Case #" << i+1 << ": ";
    //     solve();
    // }

    return 0;
}
