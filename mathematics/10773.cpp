#include<bits/stdc++.h>
using namespace std;

void solve(int tc){
    int d, v, u;
    cin>>d>>v>>u;
    if (v >= u){
        cout << "Case " << tc << ": can't determine" << endl;
        return;
    }

    double y = pow(double(v)/u, 2);
    double a2 = double(1)/pow(1-y, 0.5);
    double ans = -(double(d)/u)*(1-a2);
    cout << "Case " << tc << ": " << fixed << setprecision(3) << ans << endl;

}

int main(){
    int tc; cin>>tc;
    for (int i=0; i<tc; i++){
        solve(i+1);
    }

    return 0;
}