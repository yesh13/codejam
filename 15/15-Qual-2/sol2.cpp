#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <iomanip>
#include <list>
using namespace std;


int main(int argc, char* argv[]){
    int t,a,b,c;
    ifstream ifs;
    if(argc!=2){
        cout<<"file not found"<<endl;
        return 1;
    }
    ifs.open(argv[1]);
    ofstream ofs("result.out");
    ifs>>t;
    for(int i=0;i<t;i++){
        priority_queue<int> qu;
        ifs>>a;
        for(int j=0;j<a;j++){
            ifs>>b;
            qu.push(b);
        }
        int m=0;
        int max=qu.top();
        qu.pop();
        while(max>(1<<m++)){
        }
        ofs<<"Case #"<<i+1<<": "<<m<<endl;
    }
    ifs.close();
    ofs.close();
    return 0;
}
