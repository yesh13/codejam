#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stack>
#include <iomanip>
#include <list>
using namespace std;
#define MAX_INT 2147483647

class Solution {
    public:
        int divide(int dividend, int divisor) {
            int t=-1,num=0,sign=1;
            if(divisor==0) return MAX_INT;
            if(dividend>0){
                dividend=-dividend;
                sign=-sign;
            }
            if(divisor>0){
                divisor=-divisor;
                sign=-sign;
            }
            while(t){
                while(divisor<dividend){
                    if(t==-1){
                        t=0;
                        break;
                    }
                    divisor=divisor>>1;t=t>>1;
                }
                if(t==0)break;
                while(divisor<<1>=dividend){
                    if(0==divisor<<1) break;
                    t=t<<1;divisor=divisor<<1;
                }
                num+=t;
                dividend-=divisor;
            }
            if(sign==1){
                if(-num<0) return MAX_INT;
                else return -num;
            }else{
                return num;
            }
        }
};

int main(int argc, char* argv[]){
    int t,a,b,c;
    ifstream ifs;
    if(argc!=2){
        cout<<"file not found"<<endl;
        return 1;
    }
    ifs.open(argv[1]);
    ofstream ofs("result.out");
    //ifs>>t;
    Solution s;
    while(a!=70){
        cin>>a>>b;
        cout<<s.divide(a,b)<<endl;
        if(b!=0){
        cout<<a/b<<endl;}
    }
/*    for(int i=0;i<t;i++){
        int num=4;
        ofs<<"Case #"<<i+1<<": "<<num<<endl;
    }*/
    ifs.close();
    ofs.close();
    return 0;
}
