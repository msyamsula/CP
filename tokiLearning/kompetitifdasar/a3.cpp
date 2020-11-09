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

void solve(){

}
vi arr;

int main(){
    arr.resize(0);
    int n, x; cin>>n>>x;
    for(int i=0; i<n; i++){
        int temp; cin>>temp;
        arr.push_back(temp);
    }

    sort(arr.begin(),arr.end());

    int minim = MAXI;
    int ans;
    for(int i=0; i<n; i++){
        int cal = abs(arr[i]-x);
        if (cal < minim){
            minim = cal;
            ans = arr[i];
        }
    }

    cout << ans << endl;
    // int tc; cin>>tc;
    // for(int i=0; i<tc; i++){
    //     cout << "Case #" << i+1 << ": ";
    //     solve();
    // }

    return 0;
}
