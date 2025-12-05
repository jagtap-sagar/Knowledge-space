"abhdgfywabfa"
 
a::F::0::L::11

b::F::1::L::9

h::F::2::L::2

d::F::3::L::3

g::F::4::L::4

f::F::5::L::10

y::F::6::L::6

w::F::7::L::7
 

 map<char, int> 
 */
 void PrintAlpa(string s) {
     map<char,int> m;
     
     for (int i=0;i < s.length();i++ ) {
         //m[i] = s[i];
         auto f = m.find(s[i]);
         if (f != m.end()) { //found 
             m[s[i]] = i; //update its value as key remain same.
         } else { //not found
            m.insert(pair<char,int>(s[i],i));
         }
        
     }
     // show string
     int index =0;
     for ( auto p : m) {  
         cout<<"\n"<<p.first <<"::F::"<<index++<<"::L::"<<p.second;
     }
 }
int main()
{
    string str = "abhdgfywabfa";
    PrintAlpa(str);
    return 0;
}
