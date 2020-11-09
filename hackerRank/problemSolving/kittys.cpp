#include<bits/stdc++.h>
// #include "fmt/format.h"j
using namespace std;
using namespace fastformat;

typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef map<string, int> msi;
#define f(i,s,e,inc) for(int i=s; i<e; i+=inc)
#define iter(a, i) for(i=a.begin(); i!=a.end(); i++)

msi distanceMem;

void showmsi(msi a){
    msi::iterator i;
    iter(a, i){
        cout << i->first << ' ' << i->second << endl;
    }
}

void dfs(vvi tree, int node, vi visited){
    // vi visited;
    // visited.resize(100);
    visited[node] = 1;
    vi::iterator i;
    cout << node << endl;
    // string key = to_string(node)+"-"; //+to_string(*i);
    iter(tree[node], i){
        if (visited[*i] == 1){
            continue;
        }
        // cout << node << ' ' << *i << endl;
        // key += to_string(*i);
        string key;
        fmt(key, "{}-{}", node, *i);
        distanceMem[{key, 1}];
        dfs(tree, *i, visited);
    }
}

int traverse(vvi tree, int start, int end, vi visited){
    visited[start] = 1;
    if (start == end){
        return 0;
    }


    vi::iterator i;
    int min = 1<<30;
    int temp;
    iter(tree[start], i){
        if (visited[*i] == 1){
            continue;
        }
        temp = 1 + traverse(tree, *i, end, visited);
        if (temp < min){
            min = temp;
        }
    }

    return min;
}

int main(){
    vvi tree;
    // vi fill;
    // fill = {2,3,4};
    tree.push_back({1});
    tree.push_back({2,3,4});
    tree.push_back({1});
    tree.push_back({1,5,6,7});
    tree.push_back({1});
    tree.push_back({3});
    tree.push_back({3});
    tree.push_back({3});

    vi visited;
    visited.resize(7);
    int start = 1;
    dfs(tree, start, visited);
    showmsi(distanceMem);

    // cout << traverse(tree, 2, 1, visited) << endl;



    return 0;
}