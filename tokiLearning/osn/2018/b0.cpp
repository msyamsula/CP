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

ll N,S;
map<ll, ll> pizza, c_pizza;
map<ll, ll> me, de;

ll me_take(){
    if (!c_pizza.empty()){
        ll f = c_pizza.begin()->first;
        c_pizza.at(f)--;
        if (c_pizza.at(f) == 0) c_pizza.erase(f);
        return f;
    }

    if (!me.empty()){
        ll f = me.begin()->first;
        me.at(f)--;
        if (me.at(f) == 0) me.erase(f);
        return f;
    }

    return 0;
}

ll de_opt(){
    if (!c_pizza.empty()){
        ll f = c_pizza.begin()->first;
        c_pizza.at(f)--;
        if (c_pizza.at(f) == 0) c_pizza.erase(f);
        return f;
    }

    if (!de.empty()){
        ll f = de.begin()->first;
        de.at(f)--;
        if (de.at(f) == 0) de.erase(f);
        return f;
    }

    return 0;
}

ll de_take(){
    //from c
    //from de
    ll f_c = -1, f_de = -1;
    if (!c_pizza.empty()) f_c = c_pizza.begin()->first;
    if (!de.empty()) f_de = de.begin()->first;
    // pick the lowest index
    if (f_c == -1 && f_de == -1) return 0;
    if (f_c == -1){
        de.at(f_de)--;
        if (de.at(f_de) == 0) de.erase(f_de);
        return f_de;
    }
    if (f_de == -1){
        // cout << "goes here" << endl;
        c_pizza.at(f_c)--;
        if (c_pizza.at(f_c) == 0) c_pizza.erase(f_c);
        return f_c;
    }

    if (f_c < f_de){
        c_pizza.at(f_c)--;
        if (c_pizza.at(f_c) == 0) c_pizza.erase(f_c);
        return f_c;
    }

    de.at(f_de)--;
    if (de.at(f_de) == 0) de.erase(f_de);
    return f_de;
    // return
}

void solve(){
    // cout << N << ' ' << S << endl;
    pizza.clear(); c_pizza.clear();
    me.clear(); de.clear();    
    for(ll i=0; i<N; i++){
        ll temp; cin>>temp;
        // cout << temp << ' ';
        pizza[i+1] = temp;
    }
    // cout << endl;

    ll P; cin>>P;
    // cout << P << ' ';
    map<ll, ll> me_local;
    for(ll i=0; i<P; i++){
        ll temp; cin>>temp;
        // cout << temp << ' ';
        me_local[temp] = pizza[temp];
    }
    // cout << endl;

    ll Q; cin>>Q;
    // cout << Q << ' ';
    for(ll i=0; i<Q; i++){
        ll temp; cin>>temp;
        // cout << temp << ' ';
        if (me_local.find(temp) != me_local.end()){
            c_pizza[temp] = pizza[temp];
            continue;
        }
        de[temp] = pizza[temp];
    }
    // cout << endl;

    for(auto it=me_local.begin(); it!=me_local.end(); it++){
        if (c_pizza.find(it->first) == c_pizza.end()) me[it->first] = it->second;
    }

    // cout << "c_pizza: "<<endl;
    // for(auto it = c_pizza.begin(); it!=c_pizza.end(); it++){
    //     cout << it->first << ' ' << it->second << endl;
    // }

    ll round = 1;
    while(1){
        // cout << "round " << round << endl;
        //me take, cout
        ll mine = me_take();
        // cout << mine << endl << flush;
        // de take, cout
        cout << mine << endl << flush;
        ll opponent;
        cin >> opponent;
        if (c_pizza.find(opponent) != c_pizza.end()){
            c_pizza.at(opponent)--;
            if (c_pizza.at(opponent)==0) c_pizza.erase(opponent);
        }
        // cout << "me: " 
        // cout << "d: " 
        // if me take = 0 and de take = 0 break
        if (!mine && !opponent) break;
        // round++;
    }
}

// void solve(){
//     // pizza.resize(0);
//     // cout << N << ' ' << S << endl;
//     pizza.clear(); c_pizza.clear();
//     me.clear(); de.clear();
//     for(ll i=0; i<N; i++){
//         ll temp; cin>>temp;
//         // cout << temp << ' ';
//         pizza[i+1] = temp;
//     }
//     // cout << endl;

//     ll P; cin>>P;
//     // cout << P << ' ';
//     map<ll, ll> me_local;
//     for(ll i=0; i<P; i++){
//         ll temp; cin>>temp;
//         // cout << temp << ' ';
//         me_local[temp] = pizza[temp];
//     }
//     // cout << endl;

//     ll Q; cin>>Q;
//     // cout << Q << ' ';
//     for(ll i=0; i<Q; i++){
//         ll temp; cin>>temp;
//         // cout << temp << ' ';
//         if (me_local.find(temp) != me_local.end()){
//             c_pizza[temp] = pizza[temp];
//             continue;
//         }
//         de[temp] = pizza[temp];
//     }
//     // cout << endl;

//     for(auto it=me_local.begin(); it!=me_local.end(); it++){
//         if (c_pizza.find(it->first) == c_pizza.end()) me[it->first] = it->second;
//     }

//     // cout << "c_pizza: "<<endl;
//     // for(auto it = c_pizza.begin(); it!=c_pizza.end(); it++){
//     //     cout << it->first << ' ' << it->second << endl;
//     // }

//     // ll round = 1;
//     while(1){
//         // cout << "round " << round << endl;
//         //me take, cout
//         ll mine = me_take();
//         // cout << mine << endl << flush;
//         // de take, cout
//         ll opponent;
//         if (S==1) opponent = de_take();
//         else opponent = de_opt();
//         // cout << "me: " 
//         cout << mine << endl << flush;
//         // cout << "d: " 
//         cout << opponent << endl << flush;
//         // if me take = 0 and de take = 0 break
//         if (!mine && !opponent) break;
//         // round++;
//     }
// }

int main(){
    string s; cin>>s;
    // cout << s << endl;
    while(cin>>N>>S){
        solve();
    }
    // int tc; cin>>tc;
    // for(int i=0; i<tc; i++){
    //     cout << "Case #" << i+1 << ": ";
    //     solve();
    // }

    return 0;
}
