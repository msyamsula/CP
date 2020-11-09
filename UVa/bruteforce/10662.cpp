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

ll t,r,h;
vvl travel, rest, hotel;
vl tp, rp, hp;

vl state, min_state;
ll cur_price, min_price;


void search(ll type){
    // cout << type << endl;
    if (type == 3){
        ll t_r = travel[state[0]][state[1]];
        ll r_h = rest[state[1]][state[2]];
        ll h_t = hotel[state[2]][state[0]];

        if (t_r == 0 && r_h == 0 && h_t == 0){
            if (cur_price < min_price){
                min_price = cur_price;
                min_state = state;
                return;
            }
        }

        // cout << "impossible state" << endl;
        // for(ll num : state){
        //     cout << num << ' ';
        // }
        // cout << endl << endl;

        return;
    }


    vvl context;
    vl prices;
    if (type == 0){
        context = travel;
        prices = tp;
    } else if (type == 1){
        context = rest;
        prices = rp;
    } else if (type == 2){
        context = hotel;
        prices = hp;
    }
    ll n = context.size();
    for(ll i=0; i<n; i++){
        cur_price += prices[i];
        state.push_back(i);
        search(type+1);
        cur_price -= prices[i];
        state.erase(state.begin()+type);
    }
}


void solve(){
    min_price = MAXLL;
    cur_price = 0;
    min_state.resize(0);
    // cout << t << ' ' << r << ' ' << h << endl;
    travel.resize(0); travel.assign(t, vl(r, 0));
    rest.resize(0); rest.assign(r, vl(h, 0));
    hotel.resize(0); hotel.assign(h, vl(t, 0));
    tp.resize(0); rp.resize(0); hp.resize(0);
    tp.assign(t, 0); rp.assign(r, 0); hp.assign(h, 0);

    for(ll i=0; i<t; i++){
        // cout << "tes" << endl;
        for(ll j=0; j<r+1; j++){
            ll temp; cin>>temp;
            if (j==0){
                tp[i]=temp;
                continue;
            }

            travel[i][j-1] = temp;
        }
    }


    for(ll i=0; i<r; i++){
        for(ll j=0; j<h+1; j++){
            ll temp; cin>>temp;
            if (j==0){
                rp[i]=temp;
                continue;
            }

            rest[i][j-1] = temp;
        }
    }

    for(ll i=0; i<h; i++){
        for(ll j=0; j<t+1; j++){
            ll temp; cin>>temp;
            if (j==0){
                hp[i]=temp;
                continue;
            }

            hotel[i][j-1] = temp;
        }
    }

    search(0);

    if (min_state.size() == 0){
        cout << "Don't get married!" << endl;
        return;
    }

    for(ll i=0; i<3; i++){
        cout << min_state[i] << " :"[i==2];
    }
    cout << min_price << endl;

    // for(ll num : tp){
    //     cout << num << ' ';
    // }
    // cout << endl;

    // for(vl temp : travel){
    //     for(ll num : temp){
    //         cout << num << ' ';
    //     }
    //     cout << endl;
    // }
    // cout << endl;

    // for(ll num : rp){
    //     cout << num << ' ';
    // }
    // cout << endl;

    // for(vl temp : rest){
    //     for(ll num : temp){
    //         cout << num << ' ';
    //     }
    //     cout << endl;
    // }
    // cout << endl;

    // for(ll num : hp){
    //     cout << num << ' ';
    // }
    // cout << endl;

    // for(vl temp : hotel){
    //     for(ll num : temp){
    //         cout << num << ' ';
    //     }
    //     cout << endl;
    // }
    // cout << endl;
}

int main(){
    while(cin>>t>>r>>h){
        solve();
    }
    // int tc; cin>>tc;
    // for(int i=0; i<tc; i++){
    //     cout << "Case #" << i+1 << ": ";
    //     solve();
    // }

    return 0;
}
