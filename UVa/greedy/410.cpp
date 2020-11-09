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

ll C,S;
vl arr;

void solve(){
    arr.resize(0);
    // cin>>C>>S;
    ll sum = 0;
    for(ll i=0; i<S; i++){
        ll temp; cin>>temp;
        sum += temp;
        arr.push_back(temp);
    }


    sort(arr.begin(), arr.end());
    for(ll num : arr){
        cout << num << ' ';
    }
    cout << endl;
    double average = double(sum)/C;
    cout << "average " << average << endl;

    vl chamber; chamber.assign(C, 0);
    vvl status; status.resize(C);
    for(ll i=0; i<S; i++){
        double min_imbalance = MAXLL;
        ll choice = 0;
        for(ll j=0; j<C; j++){
            double tot_weight = double(chamber[j] + arr[i]);
            double imbalance = abs(tot_weight - average);
            if (imbalance < min_imbalance){
                choice = j;
                min_imbalance = imbalance;
            }
        }
        chamber[choice] += arr[i];
        status[choice].push_back(arr[i]);
    }

    cout << "chamber mass" << endl;
    for(ll num : chamber){
        cout << num << ' ';
    }
    cout << endl;
    cout << "chamber status" << endl;
    for(vl a : status){
        for(ll num : a){
            cout << num << ' ';
        }
        cout << endl;
    }
    double tot_imbalance = 0;
    for(ll num : chamber){
        tot_imbalance += abs(num-average);
    }
    cout << "total_imbalance :" << tot_imbalance << endl;
    cout << endl;
}

int main(){
    while(cin>>C>>S){
        solve();
    }
    // int tc; cin>>tc;
    // for(int i=0; i<tc; i++){
    //     cout << "Case #" << i+1 << ": ";
    //     solve();
    // }

    return 0;
}
