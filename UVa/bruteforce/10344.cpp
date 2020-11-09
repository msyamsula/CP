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

vl arr;
vl zonk = {0,0,0,0,0};
ll cur_target;
vs operation;
vl number;

bool search(vl arr, ll idx){
    if (idx == 5){
        if (cur_target == 23){
            // for(ll num : number){
            //     cout << num << ' ';
            // }
            // cout << endl;
            // for(string s : operation){
            //     cout << s << ' ';
            // }
            // cout << endl;
            return 1;
        }
        return 0;
    }

    for(ll i=0; i<3; i++){
        if (i==0) {cur_target += arr[idx]; operation.push_back("+"); number.push_back(arr[idx]); }
        if (i==1) {cur_target -= arr[idx]; operation.push_back("-"); number.push_back(arr[idx]); }
        if (i==2) {cur_target *= arr[idx]; operation.push_back("*"); number.push_back(arr[idx]); }
        if (search(arr, idx+1)) return 1;
        if (i==0) cur_target -= arr[idx];
        if (i==1) cur_target += arr[idx];
        if (i==2) cur_target /= arr[idx];
        operation.pop_back();
        number.pop_back();
    }

    return 0;
}

void solve(){
    sort(arr.begin(), arr.end());
    do{
        cur_target = arr[0];
        number.resize(0);
        number.push_back(arr[0]);
        operation.resize(0);
        if(search(arr, 1)){
            cout << "Possible" << endl;
            return;
        }
    } while(next_permutation(arr.begin(), arr.end()));

    cout << "Impossible" << endl;
}

int main(){
    while(1){
        arr.resize(0);
        for(ll i=0; i<5; i++){
            ll temp; cin>>temp;
            arr.push_back(temp);
        }
        if (arr == zonk) break;
        solve();
    }

    return 0;
}
