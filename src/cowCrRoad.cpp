/*
author:白-槿
*/

#include <iostream>
#include <cstring>
#include <algorithm>
#include <unordered_map>
#define x first
#define y second
using namespace std;
const int maxn = 1e5+10;
int ans=0;
typedef pair<int, int> PII;
bool cmp(PII a,PII b){
    return a.x<b.x;
}
  unordered_map<int,int>mp_up,mp_down;
int main(){
    int n;
    cin>>n;
    PII up[maxn],down[maxn];
    for (int i = 0; i < n; i ++ ){
         int a,b;
         cin>>a>>b;
         PII t;
         mp_up[a]=b;
         mp_down[b]=a;
         up[i]={a,i};
         down[i]={b,i};
         
    }
    sort(up,up+n,cmp),  sort(down,down+n,cmp);;
    int ans=0;
    int max_up =-0x3f3f3f3f;int max_down =-0x3f3f3f3f;
    for (int i = 0; i < n; i ++ ){
        if(up[i].y!=down[i].y){
            max_down=max(max_down,mp_up[up[i].x]);
            max_up=max(max_up,mp_down[down[i].x]);
            
        }
        if(up[i].y==down[i].y&&(down[i].x>max_down&&up[i].x>max_up)){
            ans++;
            
        }
    }
    cout << ans <<endl;
    
}