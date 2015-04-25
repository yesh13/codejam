#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stack>
#include <iomanip>
#include <list>
#include <algorithm>
#include <cmath>
#include <unordered_set>
#include <unordered_map>
using namespace std;


int main(int argc, char* argv[]){
    long t,a,b,c;
    ifstream ifs;
    if(argc!=2){
        cout<<"file not found"<<endl;
        return 1;
    }
    ifs.open(argv[1]);
    ofstream ofs("result.out");
    ifs>>t;
    for(int i=0;i<t;i++){
        int ans=0;
        ifs>>a;
        ifs.get();
        ifs>>b;
        c=b;
        while(c%2==0){
            c>>=1;
        }
        if(a%c==0)
        {
            ans++;
            a/=c;b/=c;
            while(2*a<b){
                b>>=1;
                ans++;
            }
        }
        if(ans>40)ans=0;

        string txt=ans?to_string(ans):"impossible";

        ofs<<"Case #"<<i+1<<": "<<txt<<endl;
    }
    ifs.close();
    ofs.close();
    return 0;
}
