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

void solve(){

}

int main(){
    // int tc; cin>>tc;
    // for(int i=0; i<tc; i++){
    //     cout << "Case #" << i+1 << ": ";
    //     solve();
    // }

    string input; cin>>input;
    string ans;
    unordered_set<char> vowel;
    vowel.insert('a');
    vowel.insert('e');
    vowel.insert('i');
    vowel.insert('o');
    vowel.insert('u');
    vowel.insert('y');
    for(ll i=0; i<input.size(); i++){
        char temp = tolower(input[i]);
        if (vowel.find(temp) != vowel.end()) continue;
        // cout << '.'+temp << endl;
        ans += '.';
        ans += temp;
    }
    cout << ans << endl;

    return 0;
}
