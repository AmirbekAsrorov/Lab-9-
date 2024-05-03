#include <iostream>

using namespace std;

int main() {
     int a[6][6]={
     {0,12,0,0,0,25},{12,0,13,15,0,0},{0,13,0,0,5,2},{0,15,0,0,5,13},{0,0,5,5,0,0},{25,0,2,13,0,0}
     };
int n;
cin>>n;
    int sum=0;
    for(auto k: a[n]) {
        sum+=k;
    }
    cout<<sum<<"\n";
    return 0;
}
