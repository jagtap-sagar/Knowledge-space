/******************************************************************************
 input : My Name is Khan
 output : Khan is Name My

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
             //above line result is not empty means it contaion some letter
            //to sepatered between two word used space 
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

========================================================
  
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    // Write C++ code here
    string str ="My Name is Khan";
    string result ="";
     string word ="";
    for (int i = str.length()-1; i>=0;--i){
        if (str[i] !=' '){
            word = str[i] + word;
        }else {
            cout<<"\n"<<word;
            result=result.empty()?word:result+' '+word;
            word ="";
        }
    }
     result += ' '+word;  // last word
     cout<<"\n"<<result;
    return 0;
}
