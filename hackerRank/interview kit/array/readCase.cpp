#include<bits/stdc++.h>
using namespace std;

int main(){

    ifstream File;
    File.open("testCase.txt");

    int a;
    while(File >> a){
        cout << a << ' ';
    }


    return 0;
}