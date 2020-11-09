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

vector<pair<string, ll>> arr;

bool comp(pair<string, ll> a, pair<string, ll> b){
    if (a.second != b.second) return a.second>b.second;
    return a.first<b.first;
}

void solve(){
    ll n; cin>>n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    arr.resize(0);
    for(ll i=0; i<n; i++){
        string s; getline(cin,s);
        // cout << s << endl;
        ll m=s.size();
        set<char> uc;
        for(ll j=0; j<m; j++){
            if(s[j]!=' ') uc.insert(s[j]);
        }
        arr.push_back({s,uc.size()});
    }

    sort(arr.begin(),arr.end(),comp);
    // for(pair<string, ll> temp : arr){
    //     cout << temp.first << ' ' << temp.second << endl;
    // }
    cout << arr[0].first << endl;
}

int main(){
    int tc; cin>>tc;
    for(int i=0; i<tc; i++){
        cout << "Case #" << i+1 << ": ";
        solve();
    }

    return 0;
}
