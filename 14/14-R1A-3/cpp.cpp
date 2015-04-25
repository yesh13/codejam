#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

typedef unsigned long INT;


void process(double mat[1000][1000],int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            mat[i][j]=(i==j);
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            for(int k=0;k<n;k++){
                if(k!=i){
                    mat[j][k]=mat[j][k]/n*(n-1)+mat[j][i]/n;   
                }
            }
        }
        for(int j=0;j<n;j++){
            mat[j][i]=1.0/n;
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            mat[i][j]*=n;
        }
    }
/*    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }*/
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
    n=1000;
    double mat[1000][1000];
    process(mat,n);
    ifs>>l;
    for(int i=0;i<l;i++){
        ifs>>n;
        double mul=1;
        for(int j=0;j<n;j++){
            ifs>>d;
            mul*=mat[d][j];
        } 
        string text="GOOD";
        if(mul>1){text="BAD";}
        ofs<<"Case #"<<i+1<<": "<<text<<endl;
    }
    ifs.close();
    ofs.close();
    return 0;
}
