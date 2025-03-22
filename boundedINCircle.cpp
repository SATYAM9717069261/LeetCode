#include<bits/stdc++.h>
using namespace std;
//GGLLGG
class Solution {
    public: bool isRobotBounded(string instructions) {
            pair<int,int> cord = {0,0}; 
            int face = 0; // {0:North, 1:West, 2:South, 3:East}
            int angle = 0; // deg
            string inst = instructions + instructions + instructions + instructions;
            for(char i : inst){
                if(i == 'G'){
                    if( face == 0)
                        cord.second++;
                    if( face == 1)
                        cord.first--;
                    if( face == 2)
                        cord.second--;
                    if( face == 3)
                        cord.first++;
                }
                if( i == 'L'){
                    angle = (angle + 270)%360;
                    face = angle/90;
                }
                if( i == 'R'){
                    angle = (angle + 90)%360;
                    face = angle/90;
                }
            }
            if(cord.first == 0 && cord.second == 0)
                return false;
            return  true;
        }
};

int main(){
    string inp; cin>>inp;
    Solution sol;
    sol.isRobotBounded(inp);
}

