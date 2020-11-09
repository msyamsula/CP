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
void showV(vl temp){
    for(ll t : temp){
        cout << t << ' ';
    }
    cout << endl;
}

void showVV(vvl temp){
    for (vl t : temp){
        for(ll t1 : t){
            cout << t1 << ' ';
        }
        cout << endl;
    }
    cout << endl;
}

ll n,a,b,c;

void solve(){
    cin>>n>>a>>b>>c;
    string imp = "IMPOSSBILE";
    // if see by both greater than total building = IMPOSSIBLE
    if (a+b-c > n){
        cout << imp << endl;
        return;
    }

    // building vector
    vl building(n,-1);

    // see only by A
    ll obsA = a-c;
    // if A see negative value then impossible
    if (obsA < 0){
        cout << imp << endl;
        return;
    }

    // check 2nd building height, if <=0 then can't build
    ll ch = n-1;
    if (ch<=0){
        cout << imp << endl;
        return;
    }
    // place 2nd building on the left (*)
    for(ll i=0; i<obsA; i++){
        building[i]=ch;
    }

    // see only by B
    ll obsB = b-c;
    // if b see negative value then impossible
    if (obsB < 0){
        cout << imp << endl;
        return;
    }

    // check lapak B
    ll lapakB = n-obsA;

    // if no lapak for B or lapakB is less than what B see
    if (lapakB < 0 || lapakB < obsB){
        cout << imp << endl;
        return;
    }

    // iterate from right, and add 2nd building up until obsB (**)
    for(ll i=1; i<=obsB; i++){
        ll index = n-i;
        building[index] = ch;
    }

    // 1st building
    ch = n;
    // assign 1st building after step (*) and (**)
    ll cnt = 0;
    for(ll i=0; i<n; i++){
        if (building[i] == -1){
            building[i] = ch;
            cnt++;
            if (cnt == c) break;
        }
    }

    // count space for 3rd building
    cnt = 0;
    for(ll i=0; i<n; i++){
        if (building[i] == -1) cnt++;
    }

    // fill other building by 3rd building
    ch = n-2; // 3rd building
    // check if, 3rd building is 0 or negative then can't build
    if (ch <= 0){
        cout << imp << endl;
        return;
    }
    // if obsB == 0 (special case)
    if (obsB == 0){
        for(ll i=0; i<cnt; i++){
            building.insert(building.begin()+1, ch);
        }

        for(ll i=0; i<cnt; i++){
            building.pop_back();
        }
    } else {
        for(ll i=0; i<n; i++){
            if (building[i] == -1) building[i] = ch;
        }
    }


    for (ll i=0; i<n; i++){
        if (i!=0) cout << ' ';
        cout << building[i];
    }
    cout << endl;
    
}

int main(){
    int tc; cin>>tc;
    for(int i=0; i<tc; i++){
        cout << "Case #" << i+1 << ": ";
        solve();
    }

    return 0;
}
