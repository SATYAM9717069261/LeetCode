#include<bits/stdc++.h>
using namespace std;
int main(){
    int test;cin>>test;
    while(test--){
       int nums; cin>>nums;
       string rec; cin>>rec;
       bool head = true; // true -> search for head
       bool found = true;
       for(char i : rec){
           if((head == true && (i == '.' || i=='H') ) || (head == false && (i == '.' || i == 'T'))){
               if(i == 'H' || i == 'T')
                    head = !head;
               continue;
           }else{
               found = false;
               break;
           }
       }
       if(found == true && head == true){
           cout<<"valid"<<endl;
       }else{
            cout<<"Invalid"<<endl;
       }
    }
    return 0;
}
