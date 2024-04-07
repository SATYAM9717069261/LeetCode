#include<bits/stdc++.h>
using namespace std;
void  print(vector<int>& pos_x, vector<int>& pos_y, vector<int>& maxElement){
    int eleSize = pos_x.size();
    int maxELE = maxElement[eleSize-1];
    for(int i=eleSize-1;i>=0;i--){
        if(maxELE != maxElement[i])
            break;
        cout<<pos_y[i]+1<<","<<pos_x[i]+1<<"="<<maxElement[i]<<endl;
    }
}
int main(){
    int count; cin>>count;

    vector<int> pos_x;
    vector<int> pos_y;
    vector<int> maxElement;
    int maxEl = INT_MIN;
    int x=0,y=0;
/** count : y **/
    while(count--){
        string inp; cin>>inp;
        int num=0;
        int pos=1;
        for( char c: inp){
            if(c=='#'){
                if(maxEl < num){
                    maxEl = num;
                    pos_x.push_back(x);
                    pos_y.push_back(y);
                    maxElement.push_back(num);
                }
                x++;
                num=0; pos=1;
            }else{
                num = (num*pos)+ (c - '0');
                pos *= 10;
            }
        }
        //cout<<num;
        //cout<<endl;
        y++;
        x=0;
    }

    print(pos_x,pos_y,maxElement);


    return 0;
}
