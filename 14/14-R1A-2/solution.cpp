#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stack>
using namespace std;
struct Position{
    int r,c;
    Position(int _x,int _y){
        r=_x;c=_y;
    }
};

int process(int edge[1000][1000],int cut[1000][1000],int count[1000][1000],int n){
    bool conti=false;
    stack<Position> countS;
    for(int i=0;i<n;i++){
        countS.push(Position(i,i));
    }
    while(!countS.empty()){
        Position p=countS.top();
        int num=0;int child[1000];
        for(int i=0;i<n;i++){
            if(edge[p.r][i]==1&&i!=p.c){
               child[num++]=i; 
            }
        }
        switch(num){
            case 0:count[p.r][p.c]=1;countS.pop();break;
            default:
                   bool complete=true;
                   for(int k=0;k<num;k++){
                      if(count[child[k]][p.r]==-1){
                        complete=false;
                      } 
                   }
                   if(complete){
                       countS.pop();
                       int sum=0;
                       for(int k=0;k<num;k++){
                           sum+=count[child[k]][p.r];
                       }
                       count[p.r][p.c]=sum+1;
                   }else{
                       for(int k=0;k<num;k++){
                           countS.push(Position(child[k],p.r));
                       }
                   }
        }
    }
    stack<Position> cutS;
    for(int i=0;i<n;i++){
        cutS.push(Position(i,i));
    }
    while(!cutS.empty()){
        Position p=cutS.top();
        int num=0;int child[1000];
        for(int i=0;i<n;i++){
            if(edge[p.r][i]==1&&i!=p.c){
               child[num++]=i; 
            }
        }
        switch(num){
            case 0:cut[p.r][p.c]=0;cutS.pop();break;
            case 1:cut[p.r][p.c]=count[child[0]][p.r];cutS.pop();break;
            default:
                   bool complete=true;
                   for(int k=0;k<num;k++){
                      if(cut[child[k]][p.r]==-1){
                        complete=false;
                      } 
                   }
                   if(complete){
                       cutS.pop();
                       int sum=0;
                       for(int k=0;k<num;k++){
                           sum+=count[child[k]][p.r];
                       }
                       int max1=count[child[0]][p.r]-cut[child[0]][p.r];
                       int max2=count[child[1]][p.r]-cut[child[1]][p.r];
                       if(max1<max2){
                        int c=max1;
                        max1=max2;max2=c;
                       }
                       for(int k=2;k<num;k++){
                           int t=count[child[k]][p.r]-cut[child[k]][p.r];
                           if(t>max1){
                            max2=max1;max1=t;
                           }else if(t>max2){
                            max2=t;
                           }
                       }
                       sum-=max1;
                       sum-=max2;
                       cut[p.r][p.c]=sum;
                   }else{
                       for(int k=0;k<num;k++){
                           cutS.push(Position(child[k],p.r));
                       }
                   }
        }
    }
/*    for(int i=0;i<n;i++){

    for(int j=0;j<n;j++){
        cout<<count[i][j]<<" ";
    }
    cout<<endl;
    }
    cout<<endl;
    for(int i=0;i<n;i++){

    for(int j=0;j<n;j++){
        cout<<cut[i][j]<<" ";
    }
    cout<<endl;
    }*/
    int min=1000;
    for(int i=0;i<n;i++){
        min=min>cut[i][i]?cut[i][i]:min;
    }
    return min;
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
    int (*edge)[1000]=new int[1000][1000];
    int (*cut)[1000]=new int[1000][1000];
    int (*count)[1000]=new int[1000][1000];
    ifs>>l;
    for(int iter=0;iter<l;iter++){
        ifs>>n;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                edge[i][j]=0;
                cut[i][j]=-1;
                count[i][j]=-1;
            }
        }
        for(int j=0;j<n-1;j++){
            int a,b;
            ifs>>a>>b;
            edge[a-1][b-1]=1;
            edge[b-1][a-1]=1;
        }
        int num=process(edge,cut,count,n);
    ofs<<"Case #"<<iter+1<<": "<<num<<endl;
    }

    ifs.close();
    ofs.close();    return 0;
}
