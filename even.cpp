#include<bits/stdc++.h>
using namespace std;

void solve(int tc){
    string num; cin>>num;
    long long ans = 0;
    // if (num.size() == 1){
    //     int n = int(num[0]) - '0';
    //     if (n%2 != 0 ){
    //         ans = 1;
    //         cout << "Case #" << tc << ": " << ans << endl;
    //         return;
    //     }
    // }


    for(long long i=0; i<num.size(); i++){
        long long n = long(num[i]) - '0';
        if (n%2 != 0){
            if (i == num.size()-1){
                ans = 1;
                break;
            }

            long long big = pow(10, num.size()-1-i);
            string temp = num.substr(i+1, num.size());
            long long small = stoll(temp.c_str());
            string a = "";
            for (long long j=i+1; j<num.size(); j++){
                a += '1';
            }

            long long one = stoll(a.c_str())+1;
            // cout << big << ' ' << small << ' ' << one << endl;
            ans = min(big-small, small+one);

            break;
        }
    }

    cout << "Case #" << tc << ": " << ans << endl;

}

int main(){
    int tc; cin>>tc;
    for(int i=0; i<tc; i++){
        solve(i+1);
    }

    return 0;
}