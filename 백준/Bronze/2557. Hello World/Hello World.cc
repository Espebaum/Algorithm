#include <iostream>
#include <string>
#define co(x)   cout<<(x)<<'\n'
using namespace std;

/*
* black box upper
*/
void solve(){
    string a = "Hello World!";
    co(a);
}

/*
* black box under
*/
int main(){
    solve();
    return 0;
}