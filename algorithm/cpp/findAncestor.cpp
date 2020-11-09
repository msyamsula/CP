#include<bits/stdc++.h>
using namespace std;

#define f(i,s,e,inc) for(int i=s; i<e; i+=inc)
#define iter(a,i) for(i=a.begin(); i!=a.end(); i++)
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef pair<int, int> pii;
typedef map<int, int> mii;


void show(vi a){
    vi::iterator i;
    iter(a,i){
        // cout << i->first << ' ' << i->second << endl;
        cout << *i << endl;
    }
}

void showVvi(vvi a){
    int is = a.size();
    f(i,0,is,1){
        int js = a[i].size();
        f(j,0,js,1){
            cout << a[i][j] << " \n"[j==js-1];
        }
    }
}

int kAncestor(vvi ht, int n, int k){
    int i = k;
    int result;
    while (i>0){
        int pt = (31-__builtin_clz(i));
        result = ht[pt][n];
        i -= (1<<pt);
    }
    return result;
}

vvi ancestorHashTable(vi f_ancestor, int s){
    vvi result;
    result.push_back(f_ancestor);
    int power = 1;
    while ((1<<power) <= s){
        vi temp;
        temp.resize(s+1);
        f(i,1,s+1,1){
            int pre_anc = result[power-1][i];
            temp[i] = result[power-1][pre_anc];
        }
        result.push_back(temp);
        power++;
    }

    return result;
}

vi ancestor(vi tree[100], int s){
    vi ans;
    ans.resize(s+1);
    f(i,1,s+1,1){
        int ns = tree[i].size();
        cout << ns << endl;
        f(j,0,ns,1){
            int node = tree[i][j];
            ans[node] = i;
        }
    }

    return ans;
}

// mii ancestor(vi tree[100], int s){
//     mii result;
//     f(i,1,s+1,1){
//         int ns = tree[i].size();
//         f(j,0,ns,1){
//             int key = tree[i][j];
//             result.insert({key, i});
//         }
//     }

//     return result;

// }

int main(){

    vi adj[100];

    adj[1].push_back(2);
    adj[1].push_back(3);
    // adj[5].push_back(1);
    adj[2].push_back(4);
    adj[2].push_back(5);
    adj[4].push_back(6);
    adj[6].push_back(7);
    // adj[3].push_back(5);
    // adj[3].push_back(2);
    // adj[2].push_back(5);
    // adj[2].push_back(3);

    vi f_anc = ancestor(adj, 7);
    // show(f_anc);
    vvi hash_table = ancestorHashTable(f_anc, 7);
    showVvi(hash_table);

    cout << kAncestor(hash_table, 1, 4) << endl;


    return 0;
}