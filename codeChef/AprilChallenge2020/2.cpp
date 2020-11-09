#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
#define MAX (1<<30)
#define MIN (1<<30)

void solve(){
    int n; cin>>n;
    vi line(n);
    // bitset<103> line;
    for(int i=0; i<n; i++){
        cin>>line[i];
        // int temp;cin>>temp;
        // if (temp) line[i] = 1;
    }

    int min_distance = MAX;
    int base;
    for(int i=0; i<n; i++){
        if (line[i]){
            base = i;
            break;
        }
    }

    for(int i=base+1; i<n; i++){
        if (line[i]){
            int d = i-base;
            base = i;
            min_distance = min(min_distance, d);
        }

        if (min_distance < 6){
            cout << "NO" << endl;
            return;
        }
    }

    cout << "YES" << endl;

}

int main(){
    int tc; cin>>tc;
    for(int i=0; i<tc; i++){
        solve();
    }

    return 0;
}