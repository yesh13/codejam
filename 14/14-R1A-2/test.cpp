#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stack>
using namespace std;

class Solution {
    public:
        void swap(int nums[],int a,int b){
                int c=nums[a];nums[a]=nums[b];nums[b]=c;
        }
        void rot(int nums[],int n){
                for(int i=n-1;i>=1;i--){
                            swap(nums,i,i-1);
                                }
        }
            void rotate(int nums[], int n, int k) {
                        for(int i=0;i<k;i++){
                                        rot(nums,n);
                                                }
                            }
};
int main(){
    int ar[]={1,2,3,4,5,6,7};
    Solution s;
    s.rotate(ar,7,17);
    for(int i=0;i<7;i++){
        cout<<ar[i]<<" ";
    }
    cout<<endl;
    s.rotate(ar,1,17);
    for(int i=0;i<7;i++){
        cout<<ar[i]<<" ";
    }
    cout<<endl;
    return 0;
}
