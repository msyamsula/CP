#include<bits/stdc++.h>
using namespace std;

#define f(i,s,e,inc) for(int i=s; i<e; i+=inc)
typedef vector<int> vi;
typedef vector<vector<int> > vvi;

// void dfs(vi adj[100], int s){
//     vector<bool> visited(s);
//     f(i,1,s,1){
//         visited[i] = false;
//     }

//     vi movement;
//     int curPos = 3;
//     movement.push_back(curPos);
//     int nVisited = 1;
//     visited[curPos] = true;
//     cout << curPos << endl;
//     while (nVisited < s-1){
//         bool find = false;
//         for (auto u : adj[curPos]){
//             if (visited[u]==false){
//                 visited[u] = true;
//                 // cout << visited[u] << endl;
//                 nVisited ++;
//                 curPos = u;
//                 movement.push_back(curPos);
//                 find = true;
//                 break;
//             }
//         }

//         if (!find){
//             movement.pop_back();
//         }

//         if (movement.size() == 0){
//             break;
//         }
//         curPos = movement[movement.size()-1];
//         cout << curPos << ' ' << find << ' ' << movement.size() << ' ' << nVisited << endl;
//         // f(i,0,movement.size(),1){
//         //     cout << visited[i] << " \n"[i==s-1];
//         // }
//     }

// }

void dfs(vi adj[100], int pos, int visited[100]){
    // bool visited[s+1];
    // int pos = start;
    visited[pos] = 1;
    cout << pos << endl;

    vi::iterator i;
    bool allVisited = 0;
    for(i=adj[pos].begin(); i!=adj[pos].end(); i++){
        int next = *i;
        if (visited[next]){
            continue;
        } else {
            visited[next] = 1;
            // cout << next << endl;
            dfs(adj, next, visited);
        }
    }
}

class Node {
    public:
        int data;
        vector<Node *> ptrs;
        int edgesCount;
        Node(int data=0){
            this->data = data;
            this->edgesCount = 0;
        };

        void connect(Node n){
            this->edgesCount +=1;
            this->ptrs.resize(this->edgesCount);
            this->ptrs[this->edgesCount-1] = &n;
        };
};

int main(){

    int max=100;
    int s = 6;
    vi adj[max];
    int visited[100];

    // adj[1].push_back(5);
    // adj[1].push_back(4);
    // adj[5].push_back(1);
    // adj[5].push_back(3);
    // adj[5].push_back(2);
    // adj[3].push_back(5);
    // adj[3].push_back(2);
    // adj[4].push_back(1);
    // adj[2].push_back(5);
    // adj[2].push_back(3);


    // Node graph[max];

    // s=5;
    // f(i,1,s+1,1){
    //     graph[i] = Node(i+1);
    // }

    // graph[1].connect(graph[5]);
    // graph[1].connect(graph[4]);
    // graph[1].connect(graph[5]);



    adj[1].resize(2);
    adj[1] = {3,4};
    adj[2].resize(1);
    adj[2] = {5};
    adj[3].resize(2);
    adj[3] = {1,4};
    adj[4].resize(2);
    adj[4] = {1,3};
    adj[5].push_back(2);
    dfs(adj,2,visited);




    // dfs(adj, s);



    return 0;
}