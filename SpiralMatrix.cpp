#include<bits/stdc++.h>
using namespace std;
class Solution{
    public: void sol(int size){
                int arr[size][size];
                int left = 0, right = size-1;
                int top = 0, bottom = size-1;
                int num = 1;
                while(left <= right && top <= bottom){
                    for(int i= left; i<= right; i++){
                        arr[top][i] = num;
                        num++;
                    }
                    top++;

                    for(int i = top; i<= bottom; i++){
                        arr[i][right] = num;
                        num++;
                    }
                    right--;


                    if(top <= bottom ){                                                                                                      
                        for(int i=right;i>=left;i--){
                            arr[bottom][i] = num;
                            num++;
                        }
                        bottom--;
                    }
                    if(left <= right){
                        for(int i=bottom;i>=top;i--){
                            arr[i][left] = num;
                            num++;
                        }
                        left++;
                    }
               }


                for(int i= 0;i<size;i++){
                    for(int j=0;j<size;j++)
                        cout<<arr[i][j]<<" ";
                    cout<<endl;
                }
            }
};

int main(){
    int num; cin>>num;
    Solution sol;
    sol.sol(num);
    return 0;
}
