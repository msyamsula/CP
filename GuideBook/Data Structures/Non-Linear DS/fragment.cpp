#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef map<int, vector<int> > mivi;
#define f(i,s,e,inc) for(int i=s; i<e; i+=inc)
#define iter(a, i) for(i=a.begin(); i!=a.end(); i++)

void solve(){
    // string ;
    // cin >> newLine;
    ifstream file;
    file.open("tes.txt");
    // char input[100];
    int input;
    int sum = 0;
    while(scanf("%i", &input) != EOF){
        // if (input[0] == 'a'){
        //     cout << "this is break"<<endl;
        // } else {
        // }
        sum += input;
        cout << sum << endl;
        // if (input == "\n"){
        //     cout << "this is break" << endl;
        // } else {
        //     cout << input << endl;
        // }
    }
    // char nl[1];
    // scanf("%s", nl);
    // if (strstr(nl, "\n") != nullptr){
    //     return;
    // }
    // cin >> input;
    // cout << input << endl;

}


int main(){
    int TC;
    cin >> TC;
    f(tc, 0, TC, 1){
        solve();
    }

    return 0;
}