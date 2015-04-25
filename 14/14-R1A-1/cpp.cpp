#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

typedef unsigned long INT;

int solve(vector<INT> device,vector<INT> outlet, int l){
    int count;
    int n=device.size();
    list<int> even;
    for(int i=l-1;i>=0;i--){
        int c1=0,c2=0;
       for(int j=0;j<n;j++){
           c1+=device[j]>>i&1
       } 
       for(int j=0;j<n;j++){
           c2+=outlet[j]>>i&1
       } 
       if(c1*2!=n){
           if(c1==c2){
               continue;
           }else if(c1+c2==n){
               count++;
               for(int j=0;j<n;j++){
                   bool a=!(outlet[j]>>i&1)
                       outlet[j]=(outlet[j]|1<<i)&a<<i
               } 
               continue;
           }else{
               return -1;
           }
       }else if(c1*2==n&&c1==c2){

       }else{
           return -1;
       }
    }
}


int main(int argc, char* argv[]){
    int l,d,n;
    ifstream ifs;
    if(argc!=2){
        cout<<"file not found"<<endl;
        return 1;
    }
    ifs.open(argv[1]);
    ofstream ofs("result.out");
    vector<INT> device;
    vector<INT> outlet;
    ifs>>l;
    for(int i=0;i<l;i++){
        ifs>>d>>n;
        for(int j=0;i<d;i++){
            INT s;
            ifs>>s;
            outlet.push_back(s);
        }
        for(int j=0;i<d;i++){
            INT s;
            ifs>>s;
            device.push_back(s);
        }
        int m=solve(device,outlet,n);

        ofs<<"Case #"<<i+1<<": "<<m<<endl;
    }
    ifs.close();
    ofs.close();
    return 0;
}
