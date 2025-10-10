 #include <iostream>
    #include<unordered_map>
    #include <vector>
    #include <algorithm>

    using namespace std;
    
    int main() {
        vector<int> v={1,2,3,3,4};
        unordered_map<int,int>m;
        
        for(auto i: v){
            m[i]=0;
        }
        //print map
        for(auto value:m){
            cout<<" "<<value.first;
        }
    //sort map using lambda
   /* std::sort(m.begin(),m.end(), 
    [](const std::pair<int,int>& a, 
       const std::pair<int,int>& b){
       return a.first>b.first; 
    });*/
    
    //declare new vector like map
    vector<pair <int,int> >sortvector(m.begin(),m.end());
    
    sort(sortvector.begin(), sortvector.end(),
    [](pair<int,int>&a,
    pair<int,int>&b){
        return a.first< b.first;
    });
    cout<<"\n";
    for(auto [k,v]:sortvector){
            cout<<" "<<k<<" : "<<v;
        }
      return 0;
    }
