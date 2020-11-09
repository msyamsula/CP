#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

void solve(int tc){
    int n; cin>>n;
    vi get(n,0);
    vi use(n,0);
    int getf=0, usef=0;
    for (int i=0; i<n; i++){
        cin>>get[i];
        getf+=get[i];
    }

    for (int i=0; i<n; i++){
        cin>>use[i];
        usef+=use[i];
    }

    // cout << getf << ' ' << usef << endl;

    if (usef > getf){
        cout << "Case " << tc << ": Not possible" << endl;
        return;
    }

    int i=0, count=0, fuel=0, start=1;
    while(count < n){
        int cp = i%n;
        fuel += get[cp] - use[cp];
        if (fuel < 0){
            count = 0; fuel = 0;
            int istart = (cp+1)%n;
            start = istart+1;
            i++;
            continue;
        }

        count++;
        i++;
    }

    cout << "Case " << tc << ": Possible from station " << start << endl;

}

int main(){
    int tc; cin>>tc;
    for (int i=0; i<tc; i++){
        solve(i+1);
    }

    return 0;
}