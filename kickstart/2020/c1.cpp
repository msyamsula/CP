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

vi arr;

void solve(){
    int n,k; cin>>n>>k;
    arr.resize(0);
    for(int i=0; i<n; i++){
        int ntemp; cin>>ntemp;
        arr.push_back(ntemp);
    }

    // for(int num : arr){
    //     cout << num << ' ';
    // }
    // cout << endl;

    vi target;
    for(int i=k; i>=1; i--){
        target.push_back(i);
    }

    int count = 0;
    for(int i=0; i<=n-k; i++){
        vi vtemp(arr.begin()+i, arr.begin()+i+k);
        if (vtemp == target) count++;
        // for(int num : vtemp){
        //     cout << num << ' ';
        // }
        // cout << endl;
    }

    cout << count << endl;
}

int main(){
    int tc; cin>>tc;
    for(int i=0; i<tc; i++){
        cout << "Case #" << i+1 << ": ";
        solve();
    }

    return 0;
}
