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
        child.assign(10, nullptr);
        isEnd = 0;
    }
};

class Trie{
    Node root, *ptr;
    public:
    Trie(){
        ptr = &root;
    }

    bool insert(string a){
        ptr = &root;
        int n = a.size();
        for(int i=0; i<n; i++){
            int idx = a[i]-'0';
            if (ptr->child[idx] == 0){
                ptr->child[idx] = new Node;
            }
            if (ptr->child[idx]->isEnd == 1) return 0;
            // cout << "tes" << endl;
            ptr = ptr->child[idx];
        }
        ptr->isEnd = 1;
        return 1;
    }
};

vs numbers;

void solve(){
    int n; cin>>n;
    numbers.resize(0);
    for(int i=0; i<n; i++){
        string temp; cin>>temp;
        numbers.push_back(temp);
    }

    sort(numbers.begin(), numbers.end());

    Trie T;
    for(int i=0; i<n; i++){
        string temp = numbers[i];
        if (!T.insert(temp)){
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
}

int main(){
    int tc; cin>>tc;
    for(int i=0; i<tc; i++){
        // cout << "Case #" << i+1 << ": ";
        solve();
    }

    return 0;
}