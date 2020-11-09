#include<bits/stdc++.h>
using namespace std;

#define f(i,s,e,inc) for(int i=s; i<e; i+=inc)
#define iter(a,i) for(i=a.begin(); i!=a.end(); i++)
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef pair<int, int> pii;
typedef map<int, int> mii;
typedef map<string, vector<string> > msvs;

// void showvvi(vvi a){
//     vvi::iterator i;
//     iter(a, i){
//         vi::iterator j;
//         iter((*i), j){
//             cout << *j << ' ';
//         }
//         cout << endl;
//     }
// }

// vvi addTree(vvi t, string s){
//     // int idx = 0;
//     int n = 0;
//     string::iterator ci;
//     iter(s, ci){
//         // cout << *ci << endl;
//         char c = *ci;
//         int j = (int)c-97;
//         // cout << j << endl;
//         if (t[n][j] == 0){
//             t[n][26]++;
//             t[n][j] = t.size();
//             // cout << t[n][j] << endl;
//             vi temp;
//             temp.resize(27);
//             t.push_back(temp);
//         }
        
//         n = t[n][j];
//         // idx++;
//     }

//     return t;
// }

// int main(){
//     vvi tree;
//     tree.resize(1);
//     tree[0].resize(27);

//     tree = addTree(tree, "halo");
//     tree = addTree(tree, "hala");
//     tree = addTree(tree, "haza");
//     showvvi(tree);

//     return 0;
// }

void showmsvs(msvs a){
    msvs::iterator i;
    iter(a, i){
        vector<string>::iterator j;
        cout << i->first << ' ';
        iter(i->second, j){
            cout << *j << ' ';
        }
        cout << endl;
    }
}

void addTree(msvs &tree, string s){
    string::iterator si;
    string n = "";
    iter(s, si){
        int j = (int)(*si) - 97;
        if (tree[n][j] == ""){
            // tree[n][26];
            tree[n][j] = (*si);
            vector<string> temp;
            temp.resize(27);
            tree[n+(*si)] = temp;
        }
        
        n = n+(*si);
    }
}

int main (){
    msvs tree;
    vector<string> init;
    init.resize(27);
    tree[""] = init;

    addTree(tree, "halo");
    addTree(tree, "hala");

    showmsvs(tree);
    return 0;
}