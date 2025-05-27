/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <string>
using namespace std;
string reverseWords(string s) {
    string result="", word="";
    
    //below more optimized 
    for (char c : s) {
        if (c == ' ') {
            cout<<"\n Result"<<result<<" word="<<word;
            result = word + (result.empty() ? "" : " ") + result;
            word = "";
        } else {
            word += c;
        }
    }
    result = word + (result.empty() ? "" : " ") + result;
    
   /*  //Below is also correct 
   for(int i=0;i<s.length();++i){
        if (s[i] ==' '){
            cout<<"word="<<word;
        result = word+(result.empty()?"":" ")+result;
        //word="";
        word.clear();
        }else {
            cout<<"2word="<<word;
            word +=s[i];
        }
        
    }*/
     result = word+(result.empty()?"":" ")+result;
     cout<<"\n";
     return result;
}
int main() {
    string s = "I am good";
    cout <<"\nresult="<< reverseWords(s) << endl; // Output: good am I
    return 0;
}
