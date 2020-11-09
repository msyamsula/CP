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
#define MAXLL (1ll<<60)
#define MAXI (1<<30)

void solve(string a){
    string amaster = a;
    int n = a.size();
    
    deque<string> arr;
    arr.push_back(a);
    int i=0;
    for(i=0; i<10; i++){
        // cout << a << endl;
        next_permutation(a.begin(),a.end());
        arr.push_back(a);
    }

    for(i=0; i<10; i++){
        // cout << a << endl;
        prev_permutation(amaster.begin(),amaster.end());
        arr.push_front(amaster);
    }

    sort(arr.begin(),arr.end());

    int lma = -MAXI;
    string ans;
    for(string word : arr){
        int m = word.size();
        int minabs = MAXI;
        for(int i=0; i<m-1; i++){
            minabs = min(minabs, abs(word[i]-word[i+1]));
        }

        minabs = (minabs == MAXI) ? 0 : minabs;
        if (minabs > lma){
            lma = minabs;
            ans = word;
        }
        // cout << word << ' ' << minabs << endl;

    }
    cout << ans << lma << endl;
}

int main(){
    string a;
    while(cin>>a){
        solve(a);
    }
    // int tc; cin>>tc;
    // for(int i=0; i<tc; i++){
    //     cout << "Case #" << i+1 << ": ";
    //     solve();
    // }

    

    // do{
    //     int minabs = MAXI;
    //     for(int i=0; i<n-1; i++){
    //         minabs = min(minabs, abs(a[i]-a[i+1]));
    //     }
    //     lma = max(lma, minabs);
    //     cout << a << ' ' << lma << endl;
    // } while(next_permutation(a.begin(), a.end()));

    return 0;
}