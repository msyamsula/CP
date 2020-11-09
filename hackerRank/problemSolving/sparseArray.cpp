#include <bits/stdc++.h>

using namespace std;
typedef map<string, int> msi;
#define f(i,s,e,inc) for(int i=s; i<e; i+=inc)


int main(){
    int n,q;
    msi str;
    scanf("%i", &n);
    string key;
    f(i,0,n,1){
        // scanf("%s", &key[0]);
        cin >> key;
        cout << key << endl;
        try{
           str[key] += 1; 
        } catch(const exception &e) {
            str.insert({key,1});
        }
    }

    scanf("%i", &q);
    int count[q];
    f(i,0,q,1){
        // scanf("%s", &key[0]);
        cin >> key;
        try{
            count[i] = str[key];
        } catch ( const exception &e){
            count[i] = 0;
        }
    }

    f(i,0,q,1){
        printf("%i\n", count[i]);
    }

    return 0;
}