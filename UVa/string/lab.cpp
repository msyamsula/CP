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

const int ALPHABET_SIZE = 26;

struct TrieNode{
    vector<TrieNode *> children;
    bool isEnd;
    TrieNode(){
        this->isEnd = 0;
        this->children.assign(ALPHABET_SIZE, nullptr);
    };
};

class Trie{
    TrieNode root, *ptr;
    public:
    void insert(string a){
        ptr = &root;
        int n = a.size();
        for (int i=0; i<n; i++){
            int idx = a[i]-'a';
            if (ptr->children[idx] == 0){
                TrieNode *newNode = new TrieNode;
                ptr->children[idx] = newNode;
            }
            ptr = ptr->children[idx];
        }
        ptr->isEnd = 1;
    }

    bool search(string a){
        int n = a.size();
        ptr = &root;
        for(int i=0; i<n; i++){
            int idx =  a[i]-'a';
            if (ptr->children[idx] == 0) return 0;
            ptr = ptr->children[idx];
        }

        if (ptr->isEnd) return 1;
        return 0;
    }
};

void solve(){

}

int main(){
    Trie T;
    vs words = {
        "the",
        "a",
        "there",
        "answer",
        "any",
        "by", 
        "bye",
        "their"
    };

    for (string word : words){
        T.insert(word);
    }

    cout << T.search("th") << endl;

    return 0;
}