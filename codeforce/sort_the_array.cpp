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
vl arr;

void solve(){
    // enak
    arr.resize(0);
    cin>>n;
    for(ll i=0; i<n; i++){
        ll temp; cin>>temp;
        arr.push_back(temp);
    }

    vl arrsort = arr;
    sort(arrsort.begin(), arrsort.end());
    if (arrsort == arr){
        cout << "yes" << endl;
        cout << "1 1" << endl;
        return;
    }

    ll start, end;
    for(ll i=n-2; i>=0; i--){
        // cout << i << endl;
        if (arr[i]>arr[i+1]){
            end = i;
            ll j=i-1;
            while(arr[j]>arr[j-1] && j>=0) j--;
            j++;
            start = j;
            break;
        }
    }

    end+=1;
    // cout << start+1 << ' ' << end+1 << endl;
    sort(arr.begin()+start, arr.begin()+end+1);

    if (arr == arrsort){
        cout << "yes" << endl;
        cout << start+1 << ' ' << end+1 << endl;
    } else {
        cout << "no" << endl;
    }
}

int main(){
    solve();
    // int tc; cin>>tc;
    // for(int i=0; i<tc; i++){
    //     cout << "Case #" << i+1 << ": ";
    // }

    return 0;
}
