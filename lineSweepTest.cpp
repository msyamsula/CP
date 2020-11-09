#include<bits/stdc++.h>
using namespace std;

typedef tuple<int, int, int> iii;
typedef vector<iii> viii;
typedef vector<int> vi;

void solve(int tc){
    int n, q;
    cin>>n>>q;
    viii query;
    for (int i=0; i<q; i++){
        int a,b,tot;
        cin>>a>>b;
        tot = b-a+1;
        query.push_back({tot,a,b});
    }
    vi occupied(n+1,0);
    sort(query.begin(), query.end());
    int min_book = 1<<30;
    for (int i=0; i<q; i++){
        int book_now = 0;
        for(int j=1; j<n+1; j++){
            if ( get<1>(query[i])<=j && j<=get<2>(query[i]) && occupied[j]==0 ){
                book_now++;
                occupied[j] = 1;
            }
        }
        // cout << book_now << endl;
        min_book = min(book_now, min_book);
    }
    cout << "Case #" << tc << ": " << min_book << endl;
}

int main(){
    int tc; cin>>tc;
    for (int i=0; i<tc; i++){
        solve(i+1);
    }
    
    return 0;
}