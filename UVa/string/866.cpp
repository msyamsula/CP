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

map<char, int> button;
map<int, vi> book;
set<int> extension;

void solve(){

}

void addBook(string first){
    string second; cin>>second;
    int ext; cin>>ext;
    extension.insert(ext);
    // cout << second << ' ' << ext << endl;
    int dial = button[first[0]]*10 + button[second[0]];
    book[dial].push_back(ext);
}

void showExt(int dial){
    // cout << dial << endl;
    if (extension.find(dial) != extension.end()){
        cout << dial << endl;
        return;
    }

    if (book[dial].size() == 0){
        cout << 0 << endl;
        return;
    }
    
    for(int i=0; i<book[dial].size(); i++){
        cout << book[dial][i] << " \n"[i==book[dial].size()-1];
    }
}

int main(){
    string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    for(int i=0; i<alphabet.size(); i++){
        if (i<21) button[alphabet[i]] = (i/3)+2;
        else button[alphabet[i]] = 9;
    }
    string first;
    while(cin>>first){
        // cout << first;
        int dial = -1;
        try{
            dial = stoi(first);
            // cout << dial << endl;
        } catch (const exception &e){
            addBook(first);
        }
        // cout << dial << endl;
        if (dial != -1) showExt(dial);
    }

    // cout << "book" << endl;
    // for(pair<int, vi> temp : book){
    //     cout << temp.first << endl;
    //     for(int a : temp.second){
    //         cout << a << ' ';
    //     }
    //     cout << endl;
    // }
    // int tc; cin>>tc;
    // for(int i=0; i<tc; i++){
    //     cout << "Case #" << i+1 << ": ";
    //     solve();
    // }

    return 0;
}