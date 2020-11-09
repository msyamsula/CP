#include<bits/stdc++.h>
using namespace std;

#define iter(a,i) for (i=a.begin(); i!=a.end(); i++)

int main(){

    int init, p1, p2, p3;
    while(scanf("%i %i %i %i", &init, &p1, &p2, &p3) != EOF){
        if (p1 == 0 && p2 == 0 && p3 == 0){
            break;
        }

        int firstMove = ((init-p1)>0) ? init - p1 : init - p1 + 40;
        int secondMove = ((p2-p1)>0) ? p2 - p1 : p2 - p1 + 40;
        int thirdMove = ((p2-p3)>0) ? p2 - p3 : p2 - p3 + 40;

        int result = (firstMove+secondMove+thirdMove)*9 + 1080;
        cout << result << endl;
    }

    return 0;
}