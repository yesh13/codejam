#include <cstdio>
#include <fstream>
#include <iostream>
using namespace std;
int main(){

    int a[10000];
    a[9999]=1;
    int c,d;
    ifstream ifs("large.txt");
    string s;
    ifs>>c>>d;
    std::getline(ifs,s);
    std::getline(ifs,s);
    cout<<s.length()<<endl;
    ifs.close();
    return 0;
}
