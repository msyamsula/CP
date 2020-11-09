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

ll N,R,C,Sr,Sc;
map<ii, ii> No, Ea, So, We;

ii get(ll dir, ii coor){
    ii res;
    if (dir == 0){
        res = (No.find(coor) == No.end()) ? make_pair(coor.first-1, coor.second) : No.at(coor);
        return res;
    } else if (dir == 1){
        res = (Ea.find(coor) == Ea.end()) ? make_pair(coor.first, coor.second+1) : Ea.at(coor);
        return res;
    } else if (dir == 2){
        res = (So.find(coor) == So.end()) ? make_pair(coor.first+1, coor.second) : So.at(coor);
        return res;
    }

    res = (We.find(coor) == We.end()) ? make_pair(coor.first, coor.second-1) : We.at(coor);
    return res;
}

void update(ii coor){
    ii ncoor = get(0, coor);
    So[ncoor] = get(2, coor);

    ii ecoor = get(1, coor);
    We[ecoor] = get(3, coor);

    ii scoor = get(2, coor);
    No[scoor] = get(0, coor);

    ii wcoor = get(3, coor);
    Ea[wcoor] = get(1, coor);
}

void solve(){
    No.clear(); Ea.clear(); We.clear(); So.clear();
    cin>>N>>R>>C>>Sr>>Sc;
    string command; cin>>command;
    ii pos = {Sr,Sc};
    update(pos);
    for(ll i=0; i<command.size(); i++){
        char c = command[i];
        // cout << "from: " << pos.first << ' ' << pos.second;
        if (c=='N'){
            pos = get(0,pos);
        } else if (c=='E'){
            pos = get(1,pos);
        } else if (c=='S'){
            pos = get(2,pos);
        } else if (c=='W'){
            pos = get(3,pos);
        }
        update(pos);
        // cout << " to: " << pos.first << ' ' << pos.second << endl;
    }

    cout << pos.first << ' ' << pos.second << endl;
}

int main(){
    int tc; cin>>tc;
    for(int i=0; i<tc; i++){
        cout << "Case #" << i+1 << ": ";
        solve();
    }

    return 0;
}
