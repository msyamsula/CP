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

ll f,r;
vl front, rear;
vector<double> rat;

void solve(){
    front.resize(0); rear.resize(0); rat.resize(0);
    for(ll i=0; i<f; i++){
        ll temp; cin>>temp;
        front.push_back(temp);
    }

    for(ll i=0; i<r; i++){
        ll temp; cin>>temp;
        rear.push_back(temp);
    }

    // for(ll num : front){
    //     cout << num << ' ';
    // }
    // cout << endl;

    // for(ll num : rear){
    //     cout << num << ' ';
    // }
    // cout << endl;

    for(ll i=0; i<f; i++){
        for(ll j=0; j<r; j++){
            double cratio = double(rear[j])/front[i];
            rat.push_back(cratio);
        }
    }


    // for(double num : rat){
    //     cout << num << ' ';
    // }
    // cout << endl;
    sort(rat.begin(), rat.end());
    // for(double num : rat){
    //     cout << num << ' ';
    // }
    // cout << endl;

    double spread = -1;
    for(ll i=1; i<rat.size(); i++){
        // cout << rat[i] << ' ' << rat[i-1] << endl;
        double cspread = rat[i]/rat[i-1];
        // cout << cspread << endl;
        spread = max(spread, cspread);
    }

    cout << fixed << setprecision(2) << spread << endl;
}

int main(){
    while(cin>>f){
        if(!f)break;
        cin>>r;
        solve();
    }

    return 0;
}
