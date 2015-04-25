#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stack>
#include <iomanip>
#include <list>
#include <algorithm>
#include <cmath>
using namespace std;
    int t,a,b,c;

long long mat[32][8];

long long solve(int i,int tag){
    if(i==-1) return tag>>2&tag>>1&1&tag;
    if(mat[i][tag]) return mat[i][tag];
    int ak=(tag>>2|a>>i)&1;
    int bk=(tag>>1|b>>i)&1;
    int ck=(tag|c>>i)&1;
    for(int l=0;l<=ak;l++){
        for(int m=0;m<=bk;m++){
            if((m&l)<=ck){
                int newTag=((l<(a>>i&1))<<2)+((m<(b>>i&1))<<1)+((m&l)<(c>>i&1));
                mat[i][tag]+=solve(i-1,newTag|tag);
            }
        }
    }
    return mat[i][tag];
    
}



int main(int argc, char* argv[]){
    ifstream ifs;
    if(argc!=2){
        cout<<"file not found"<<endl;
        return 1;
    }
    ifs.open(argv[1]);
    ofstream ofs("result.out");
    ifs>>t;
    for(int i=0;i<t;i++){
        ifs>>a>>b>>c;
        for(int i=0;i<32;i++){
            for(int j=0;j<8;j++){
                mat[i][j]=0;
            }
        }
        long long m=solve(31,0);
        ofs<<"Case #"<<i+1<<": "<<solve(31,0)<<endl;
    }
    ifs.close();
    ofs.close();
    return 0;
}
