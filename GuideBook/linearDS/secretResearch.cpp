#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

void solve(){
    string word; cin>>word;
    char prev;
    if (word == "1" || word == "4" || word == "78"){
        cout << '+' << endl;
        prev = '+';
    } else if (word[word.size()-2] == '3' && word[word.size()-1] == '5'){
        cout << '-' << endl;
        prev = '-';
    } else if (word[0] == '9' && word[word.size()-1] == '4'){
        cout << '*' << endl;
        prev = '*';
    } else if (word[0] == '1' && word[1] == '9' && word[2] == '0'){
        cout << '?' << endl;
        prev = '?';
    } else {
        cout << prev << endl;
    }

}

int main(){
    int tc; cin>>tc;
    for (int i=0; i<tc; i++){
        solve();
    }

    return 0;
}