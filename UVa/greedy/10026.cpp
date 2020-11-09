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
bool comp(vector<double> a, vector<double> b){
    if (a[1]!=b[1]) return a[1]>b[1];
    return a[0] < b[0];
}

void solve(){
    cin>>n;
    vector<vector<double>> arr;
    for(double i=0; i<n; i++){
        double a, b;
        cin >> a>>b;
        double ratio = b/a;
        arr.push_back({i,ratio});
    }

    sort(arr.begin(), arr.end(), comp);

    for(ll i=0; i<arr.size(); i++){
        if (i!=0) cout << ' ';
        cout << (ll)arr[i][0]+1;
    }
    cout << endl;
}

int main(){
    int tc; cin>>tc;
    for(int i=0; i<tc; i++){
        // cout << "Case #" << i+1 << ": ";
        if (i!=0) cout << endl;
        solve();
    }

    return 0;
}
