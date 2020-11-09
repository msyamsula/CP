#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef vector<pair<int, int> > vpii; 
#define f(i,s,e,inc) for(int i=s; i<e; i+=inc)
#define iter(a,i) for(i=a.begin(); i!=a.end(); i++)

void show(vi a){
    vi::iterator i;
    for (i=a.begin(); i!=a.end(); i++){
        cout << *i << " ";
    }
    cout << endl;
}

int shortestPath(vpii graph[100], int s, int e, vi visited){
    visited[s] = 1;
    if (s==e){
        return 0;
    }
    vpii::iterator i;
    int min = 1<<30;
    int choice;
    int dist = min;
    int node = s;
    iter(graph[s], i){
        if (visited[i->first] == 0){
            dist = i->second;
            node = i->first;
            dist += shortestPath(graph, node, e, visited);
        }

        if(dist < min){
            min = dist;
            choice = node;
        }
    }

    return min;
}

int main(){

    vpii graph[100];
    graph[1].push_back({2,5});
    graph[1].push_back({3,3});
    graph[1].push_back({4,7});

    graph[2].push_back({1,5});
    graph[2].push_back({4,3});
    graph[2].push_back({6,2});
    
    graph[3].push_back({1,3});
    graph[3].push_back({4,1});

    graph[4].push_back({1,7});
    graph[4].push_back({2,3});
    graph[4].push_back({3,1});
    graph[4].push_back({6,2});
    
    graph[6].push_back({2,2});
    graph[6].push_back({4,2});

    vi visited;
    visited.resize(100);
    // show(visited);

    cout << shortestPath(graph, 1, 4, visited) << endl;







    return 0;
}