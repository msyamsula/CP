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
    int passby;
    Node(){
        child.assign(26, nullptr);
        isEnd = 0;
        passby = 0;
    };
};

class Trie{
    public:
    Node root, *ptr;
    Trie(){
        ptr=&root;
    }

    void insert(string a){
        ptr = &root;
        // ptr->passby++;
        int n = a.size();
        for(int i=0; i<n; i++){
            int idx = a[i]-'A';
            if (ptr->child[idx] == 0){
                ptr->child[idx] = new Node;
            }
            ptr = ptr->child[idx];
            ptr->passby++;
        }
        ptr->isEnd = 0;
    }
};

int countPair(Node *ptr){
    // if (remaining < 2) return;
    int pair = 0;
    for(int i=0; i<26; i++){
        if (ptr->child[i] != 0 && ptr->child[i]->passby >= 2){
            pair += countPair(ptr->child[i]);
        }
    }

    int spair = (ptr->passby-pair*2)/2;
    spair = max(0, spair);
    spair = min(1, spair);

    return pair + spair;

}


void solve(){
    int n; cin>>n;
    Trie T;
    for(int i=0; i<n; i++){
        string temp; cin>>temp;
        string rev;
        for(int j=0; j<temp.size(); j++){
            rev += temp[temp.size()-1-j];
        }
        // cout << rev << endl;
        T.insert(rev);
    }

    int tot = 0;
    int remaining = n;
    int depth = 0;
    cout << countPair(&T.root)*2 << endl;
    // cout << tot*2 << endl;
}

int main(){
    int tc; cin>>tc;
    for(int i=0; i<tc; i++){
        cout << "Case #" << i+1 << ": ";
        solve();
    }

    return 0;
}