#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the reverseArray function below.
vector<int> reverseArray(vector<int> a) {
    for(int i=a.size()-1; i>=0; i--){
        cout << a[i] << " \n"[i==a.size()-1];
    }

}

int main(){

    return 0;
}