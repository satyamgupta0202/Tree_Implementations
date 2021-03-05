# include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
int main(){

    int a[10]= {1,3,2,4,3,5,6,2,4,2};
    vector<int>v;
    unordered_map<int,bool>m;
    for(int i=0;i<10;i++){
        if(m.count(a[i])>0){
            continue;
        }
        v.push_back(a[i]);
        m[a[i]]=true;
    }
/**
    auto it = m.begin();
    while(it!=m.end()){
        cout<<it->first<<" ";
        it++;
    }
**/

   for(int i=0;i<v.size();i++){
       cout<<v[i]<<" ";
   }
    return 0;
}