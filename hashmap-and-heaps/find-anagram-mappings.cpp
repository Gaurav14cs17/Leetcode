# problem : https://leetcode.com/problems/find-anagram-mappings/

#include"bits/stdc++.h"
using namespace std;

struct Node{
    vector<int>v;
    int idx ;
};


int main(void ){

vector<int>v1;
vector<int>v2;
unordered_map<int , Node >mp;
int n ;
scanf("%d",&n);

for( int x, i = 0    ; i<n ; ++i ){
    scanf("%d",&x);
    v1.push_back(x);
}

for( int x, i = 0    ; i<n ; ++i ){
    scanf("%d",&x);
    v2.push_back(x);
}

for( int i = 0  ; i<n ; ++i ){
    if(mp.count(v2[i])==0){
        Node temp ;
        temp.v.push_back(i);
        temp.idx = 0;
        mp[v2[i]] = temp;
    }else{
      mp[v2[i]].v.push_back(i);
    }
}

vector<int>ans;
/*
for(auto it : mp ){
    cout<<it.first<<"->";
    for(auto x : it.second.v ){
        cout<<x<<" ";
    }
    printf("\n");
}

*/
for(auto it : v1 ){
    /*
    Node temp  = mp[it];
    ans.push_back(temp.v[temp.idx]);
    */
    ans.push_back(mp[it].v[mp[it].idx]);
    mp[it].idx += 1;

}


for(auto it : ans ){
    cout<<it<<" ";
}

return 0;
}
