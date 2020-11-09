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

ll n;
vl t;

ll calculateOnly(vl arr){
    ll sz = arr.size();
    if (sz == 1){
        // cout << arr[0] << endl;
        return arr[0];
    }
    if (sz == 2){
        // cout << arr[0] << ' ' << arr[1] << endl;
        return max(arr[0],arr[1]);
    }
    if (sz == 3){
        // cout << arr[0] << ' ' << arr[1] << endl;
        // cout << arr[0] << endl;
        // cout << arr[0] << ' ' << arr[2] << endl;
        return arr[0]+arr[1]+arr[2];
    }

    ll f=arr[0], sf = arr[1], l = arr[sz-1], sl = arr[sz-2];
    ll time1 = l+f+sl+f, time2 = sf+f+l+sf;
    arr.erase(arr.begin()+sz-2, arr.end());
    if (time1<=time2){
        // cout << f << ' ' << l << endl;
        // cout << f << endl;
        // cout << f << ' ' << sl << endl;
        // cout << f << endl;
        return time1 + calculateOnly(arr);
    }

    // cout << f << ' ' << sf << endl;
    // cout << f << endl;
    // cout << sl << ' ' << l << endl;
    // cout << sf << endl;

    return time2 + calculateOnly(arr);
}

ll calculate(vl arr){
    ll sz = arr.size();
    if (sz == 1){
        cout << arr[0] << endl;
        return arr[0];
    }
    if (sz == 2){
        cout << arr[0] << ' ' << arr[1] << endl;
        return max(arr[0],arr[1]);
    }
    if (sz == 3){
        cout << arr[0] << ' ' << arr[2] << endl;
        cout << arr[0] << endl;
        cout << arr[0] << ' ' << arr[1] << endl;
        return arr[0]+arr[1]+arr[2];
    }

    ll f=arr[0], sf = arr[1], l = arr[sz-1], sl = arr[sz-2];
    ll time1 = l+f+sl+f, time2 = sf+f+l+sf;
    arr.erase(arr.begin()+sz-2, arr.end());
    if (time1<=time2){
        cout << f << ' ' << l << endl;
        cout << f << endl;
        cout << f << ' ' << sl << endl;
        cout << f << endl;
        return time1 + calculate(arr);
    }

    cout << f << ' ' << sf << endl;
    cout << f << endl;
    cout << sl << ' ' << l << endl;
    cout << sf << endl;

    return time2 + calculate(arr);
}

void solve(){
    t.resize(0);
    cin>>n;
    for(ll i=0; i<n; i++){
        ll temp; cin>>temp;
        t.push_back(temp);
    }

    sort(t.begin(), t.end());

    ll ans = calculateOnly(t);
    cout << ans << endl;
    calculate(t);
}

int main(){
    int tc; cin>>tc;
    for(int i=0; i<tc; i++){
        // cout << "Case #" << i+1 << ": ";
        if (i!=0) cout << endl;
        solve();
    }

    return 0;
}
