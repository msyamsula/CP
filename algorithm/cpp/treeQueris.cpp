#include<bits/stdc++.h>
using namespace std;

#define f(i,s,e,inc) for(int i=s; i<e; i+=inc)
#define iter(a,i) for(i=a.begin(); i!=a.end(); i++)
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef pair<int, int> pii;
typedef map<int, int> mii;

mii sizeMem;
mii firstPar;
mii layerMem;

void showmii(mii a){
    mii::iterator i;
    iter(a, i){
        cout << i->first << ' ' << i->second << endl;
    }
}

void showvvi(vvi a){
    vvi::iterator i;
    iter(a, i){
        vi::iterator j;
        iter((*i), j){
            cout << *j << ' ';
        }
        cout << endl;
    }
}

int treeSize(vvi t, int node){

    try {
        return sizeMem.at(node);
    } catch (const exception &e){
        // cout << "mem" << endl;
        vi child = t[node];
        int s = child.size();
        int ans = 1;
        if (s == 0){
            sizeMem.insert({node, 1});
            return 1;
        }

        vi::iterator i;
        iter(child, i){
            ans += treeSize(t, *i);
        }

        sizeMem.insert({node, ans});
        return ans;
    }


}

void dfs(vvi t, int node, vi visited, int layer){
    visited[node] = 1;
    // cout << node << endl;
    int s = t[node].size();
    treeSize(t, node);
    layer++;
    f(i,0,s,1){
        layerMem.insert({t[node][i], layer});
        firstPar.insert({t[node][i], node});
        dfs(t, t[node][i], visited, layer);
    }
}

vvi ancestorTable(vvi t){
    vvi ans;
    int sz = t.size();
    mii::iterator i;
    vi initialTemp;
    initialTemp.resize(sz);
    iter(firstPar, i){
        if (i->first == 0){
            continue;
        }
        initialTemp[i->first] = i->second;
    }
    ans.push_back(initialTemp);

    int power = 1;
    while((1<<power) < sz){
        vi temp;
        temp.resize(sz);
        f(n,1,sz,1){
            int fa = ans[power-1][n];
            temp[n] = ans[power-1][fa];
        }
        ans.push_back(temp);
        power++;
    }


    return ans;
}

int kancestor(vvi table, int n, int k){
    int ans = n;
    int power;
    while(k>0){
        power = 31 - __builtin_clz(k);
        ans = table[power][ans];
        k -= 1 << power;
    }
    return ans;
}


int main(){
    vvi tree;
    vi a = {1};
    tree.push_back(a);
    a = {2,3};
    tree.push_back(a);
    a = {4,5};
    tree.push_back(a);
    a = {};
    tree.push_back(a);
    a = {6};
    tree.push_back(a);
    a = {};
    tree.push_back(a);
    a = {7};
    tree.push_back(a);
    a = {};
    tree.push_back(a);

    // adj[1].push_back(2);
    // adj[1].push_back(3);
    // // adj[5].push_back(1);
    // adj[2].push_back(4);
    // adj[2].push_back(5);
    // adj[4].push_back(6);
    // adj[6].push_back(7);
    // // adj[3].push_back(5);
    // // adj[3].push_back(2);
    // // adj[2].push_back(5);
    // // adj[2].push_back(3);
    // vi sz;
    // f(i,1,tree.size()+1,1){
    //     sz.push_back(treeSize(tree, i));
    // }

    // f(i,0,sz.size(),1){
    //     cout << sz[i] << " \n"[i==sz.size()-1];
    // }
    vi visited;
    visited.resize(tree.size()+1);
    dfs(tree, 0, visited, 0);
    vvi table = ancestorTable(tree);
    showmii(firstPar);
    cout << endl;
    showmii(sizeMem);
    cout << endl;
    showvvi(table);
    cout << endl;
    showmii(layerMem);
    cout << kancestor(table, 2, 1) << endl;

    return 0;
}