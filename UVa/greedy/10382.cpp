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

ll n,l,w;
vvl sprinkler;
vector<vector<double>> sprinkler_range;

bool comp(vector<double> a, vector<double> b){
    if (a[0] != b[0]) return a[0]<b[0];
    // if (a[2] != b[2]) return a[2]>b[2];

    return a[1]<b[1];
}

void solve(){
    // cout << "l: " << l << endl;
    sprinkler.resize(0);
    sprinkler_range.resize(0);
    for(ll i=0; i<n; i++){
        ll x,r; cin>>x>>r;
        if ((double)r<=(double)w/2) continue;
        double dx = pow(r,2)- pow((double)w/2,2);
        dx = pow(dx,0.5);
        sprinkler.push_back({x,r});
        double left = (double)x-dx, right = (double)x+dx;
        sprinkler_range.push_back({left,right,right-left});
    }

    sort(sprinkler_range.begin(), sprinkler_range.end(), comp);

    // cout << "sprinkler_range : " << endl;
    // for(vector<double> a : sprinkler_range){
    //     for(double num : a){
    //         cout << num << ' ';
    //     }
    //     cout << endl;
    // }

    double start=-MAXLL,end=0;
    ll ans = 0;
    for(ll i=0; i<sprinkler_range.size(); i++){
        double max_right = end;
        ll choice = -1;
        for(ll j=i; j<sprinkler_range.size(); j++){
            double left_j = sprinkler_range[j][0], right_j = sprinkler_range[j][1];
            // cout << left_j << ' ' << right_j << endl;
            if (left_j > end) break;
            if (right_j <= end) continue;
            if (right_j>max_right){
                // cout << j << endl;
                max_right = right_j;
                choice = j;
            }
        }

        // cout << "choices: " << i << ' ' << choice << endl;
        if (choice == -1) break;
        i = choice-1;
        end = max_right;
        ans++;
        if (end >= double(l)) break;

        // if (left > end){
        //     cout << -1 << endl;
        //     return;
        // }
        // if (right<=end) continue;
        // end = right; ans++;
        // if (end >= l) break;
    }

    if (end < (double)l){
        cout << -1 << endl;
        return;
    }

    cout << ans << endl;
}

int main(){
    while(cin>>n>>l>>w){
        solve();
    }
    // cout << 2^2 << endl;

    return 0;
}
