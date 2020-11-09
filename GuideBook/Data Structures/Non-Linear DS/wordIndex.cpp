#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
#define f(i,s,e,inc) for(int i=s; i<e; i+=inc)
#define iter(a, i) for(i=a.begin(); i!=a.end(); i++)
typedef map<string, int> msi;



msi preP(){
    string alp = "abcdefghijklmnopqrstuvwxyz";
    int pos = 1;
    msi ans;
    string key;
    int sz = alp.size();
    f(i,0,sz,1){
        key = alp[i];
        ans.insert({key, pos});
        pos++;
    }

    f(i,0,sz-1,1){
        f(j,i+1,sz,1){
            key = alp[i];
            key += alp[j];
            ans.insert({key, pos});
            pos++;
        }
    }

    f(i,0,sz-2,1){
        f(j,i+1,sz-1,1){
            f(k,j+1,sz,1){
                key = alp[i];
                key += alp[j];
                key += alp[k];
                ans.insert({key, pos});
                pos++;
            }
        }
    }

    f(i,0,sz-3,1){
        f(j,i+1,sz-2,1){
            f(k,j+1,sz-1,1){
                f(l,k+1,sz,1){
                    key = alp[i];
                    key += alp[j];
                    key += alp[k];
                    key += alp[l];
                    ans.insert({key, pos});
                    pos++;    
                }
            }
        }
    }

    f(i,0,sz-4,1){
        f(j,i+1,sz-3,1){
            f(k,j+1,sz-2,1){
                f(l,k+1,sz-1,1){
                    f(m,l+1,sz,1){
                        key = alp[i];
                        key += alp[j];
                        key += alp[k];
                        key += alp[l];
                        key += alp[m];
                        ans.insert({key, pos});
                        pos++;    
                    }
                }
            }
        }
    }

    return ans;
}

int main(){
    string word;
    msi dict = preP();
    while(cin>>word){
        try{
            cout << dict.at(word) << endl;
        } catch (const exception &e){
            cout << 0 << endl;
        }
    }


    return 0;
}