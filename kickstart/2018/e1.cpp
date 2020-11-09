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

ll N;
vl bahu, bala;
ll arena = 3;
vl used;
vl cur_arr;
vector<vl> all_arr;

void constructDeck(vl cards){
    bool recurse = 0;
    for(ll i=0; i<arena*N-2; i++){
        if (used[i] == 0){
            for(ll j=i+1; j<arena*N-1; j++){
                if (used[j] == 0){
                    for(ll k=j+1; k<arena*N; k++){
                        if (used[k] ==0 ){
                            // cout << cards[i] << ' ' << cards[j] << ' ' << cards[k] << endl;
                            recurse = 1;
                            used[i]=used[j]=used[k]=1;
                            cur_arr.push_back(cards[i]+cards[j]+cards[k]);
                            constructDeck(cards);
                            cur_arr.erase(cur_arr.begin()+cur_arr.size()-1);
                            used[i]=used[j]=used[k]=0;
                        }
                    }
                }
            }
        }
    }

    if (!recurse){
        if (cur_arr.size()==arena){
            all_arr.push_back(cur_arr);
            // for(ll num : cur_arr){
            //     cout << num << ' ';
            // }
            // cout << endl;
            
        }
    }
}

bool check(vl a, vl b){
    ll awin = 0;
    for(ll i=0; i<arena; i++){
        if(a[i] > b[i]) awin++;
    }

    return awin>=2;
}

void solve(){
    // cout << arena << endl;
    cin>>N;
    bahu.resize(0); bala.resize(0);
    for(ll i=0; i<arena*N; i++){
        ll temp; cin>>temp;
        bahu.push_back(temp);
    }

    // for(ll num : bahu){
    //     cout << num << ' ';
    // }
    // cout << endl;

    for(ll i=0; i<arena*N; i++){
        ll temp; cin>>temp;
        bala.push_back(temp);
    }

    used.resize(0); used.assign(arena*N, 0);
    cur_arr.resize(0);
    all_arr.resize(0);
    constructDeck(bahu);
    // cout << all_arr.size() << endl;

    vvl bahuC = all_arr;

    used.resize(0); used.assign(arena*N, 0);
    cur_arr.resize(0);
    all_arr.resize(0);
    constructDeck(bala);

    vvl balaC = all_arr;

    ll max_win = 0;
    for(ll i=0; i<bahuC.size(); i++){
        ll win = 0;
        for(ll j=0; j<balaC.size(); j++){
            if (check(bahuC[i], balaC[j])) win++;
        }
        max_win = max(max_win, win);
    }

    cout << fixed << setprecision(7) << double(max_win)/bahuC.size() << endl;

    // for(vvl temp : all_arr){
    //     for(vl arena : temp){
    //         for(ll num : arena){
    //             cout << num << ' ';
    //         }
    //         cout << endl;
    //     }
    //     cout << endl;
    // }
}

int main(){
    int tc; cin>>tc;
    for(int i=0; i<tc; i++){
        cout << "Case #" << i+1 << ": ";
        solve();
    }

    return 0;
}
