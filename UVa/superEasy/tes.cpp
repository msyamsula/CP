#include<bits/stdc++.h>

using namespace std;
#define f(i,s,e,inc) for (int i=s; i<e; i+=inc)


int main(){

    struct tm time;
    time.tm_mday = 12;
    time.tm_mon = 7;
    time.tm_year = 2019-1900;

    cout << time.tm_wday << endl;

    time_t t = mktime(&time);

    cout << ctime(&t) << endl;

    return 0;
}