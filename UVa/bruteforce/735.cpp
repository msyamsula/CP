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

set<ll> score;
// vl arr_score;
ll x;
set<vl> combinations;
vvl permutations;
vl cur_permutation;

void search(ll target){
    if (cur_permutation.size() == 2){
        if (score.find(target) != score.end()){
            cur_permutation.push_back(target);
            permutations.push_back(cur_permutation);
            vl temp = cur_permutation;
            sort(temp.begin(),temp.end());
            combinations.insert(temp);
            cur_permutation.pop_back();
            return;
        }

        return;
    }

    for(ll num : score){
        ll new_target = target-num;
        if (new_target < 0) continue;
        cur_permutation.push_back(num);
        search(new_target);
        cur_permutation.pop_back();
    }
}

void solve(){
    permutations.resize(0);
    combinations.clear();
    cur_permutation.resize(0);
    
    // arr_score.resize(0);
    // for(ll num : score){
    //     arr_score.push_back(num);
    // }

    // for(ll num : score){
    //     cout << num << ' ';
    // }
    // cout << endl;

    search(x);
    if (permutations.size() == 0){
        cout << "THE SCORE OF " << x << " CANNOT BE MADE WITH THREE DARTS." << endl;
        return;
    }
    ll p = permutations.size();
    ll c = combinations.size();
    cout << "NUMBER OF COMBINATIONS THAT SCORES "<< x <<" IS " << c << '.' << endl;
    cout << "NUMBER OF PERMUTATIONS THAT SCORES " << x <<" IS " << p << '.' << endl;

    // for(vl temp: permutations){
    //     for(ll num : temp){
    //         cout << num << ' ';
    //     }
    //     cout << endl;
    // }
    // cout << endl;

    // cout << endl;

    // for(vl temp : permutations){
    //     for(ll num : temp){
    //         cout << num << ' ';
    //     }
    //     cout << endl;
    // }
    // cout << endl;
}

int main(){
    for(ll i=0; i<21; i++){
        score.insert(i);
        score.insert(i*2);
        score.insert(i*3);
    }
    score.insert(50);
    ll idx=0;
    while(cin>>x){
        if (idx != 0) cout << setw(70) << setfill('*') << '*' << endl;
        if(x<=0){
            cout << "END OF OUTPUT" << endl;
            break;
        }
        solve();
        idx++;
    }
    // int tc; cin>>tc;
    // for(int i=0; i<tc; i++){
    //     cout << "Case #" << i+1 << ": ";
    //     solve();
    // }

    return 0;
}
