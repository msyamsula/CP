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

struct Node{
    vector<Node *> child;
    bool isEnd;
    Node(){
        child.assign(26, 0);
        isEnd = 0;
    }
};

set<string> strings;

class SuffixTrie{
    Node root, *ptr;
    public:
    SuffixTrie(){
        ptr = &root;
    }

    void insertSingle(string a){
        int n = a.size();
        ptr = &root;
        for(int i=0; i<n; i++){
            int idx = a[i]-'A';
            if (ptr->child[idx] == 0){
                ptr->child[idx] = new Node;
            }
            ptr = ptr->child[idx];
        }
        if (strings.find(a) != strings.end()) ptr->isEnd = 1;
    }

    void insertWord(string a){
        int n = a.size();
        vs temp;
        for(int i=0; i<n; i++){
            temp.push_back(a.substr(i,a.size()-i));
        }

        for(string add : temp){
            insertSingle(add);
        }
    }

    bool search(string a){
        ptr = &root;
        int n = a.size();
        for(int i=0; i<n; i++){
            int idx = a[i] - 'A';
            if (ptr->child[idx] == 0) return 0;
            ptr = ptr->child[idx];
        }

        return 1;
    }
};

// void solve(){

// }

int main(){
    // int tc; cin>>tc;
    // for(int i=0; i<tc; i++){
    //     cout << "Case #" << i+1 << ": ";
    //     solve();
    // }

    strings.insert("CAR");
    strings.insert("CAT");
    strings.insert("RAT");
    SuffixTrie T;
    T.insertWord("CAR");
    T.insertWord("CAT");
    T.insertWord("RAT");
    T.insertWord("SYAMSUL");
    cout << T.search("CAR") << endl;

    return 0;
}