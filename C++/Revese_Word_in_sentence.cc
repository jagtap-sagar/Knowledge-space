
#include <iostream>
#include <string>

using namespace std;
/// i/p => "My name is Sagar"
///o/p => "yM eman si ragaS"

int main()
{
    cout<<"Hello World";
    string str = "My name is Sagar";
    cout<<"\n str="<<str;
    string word = "";
    int index =0;
    for (int i= str.length()-1; i>=0; --i) {
        
        if (str[i] !=' ') {
            //word[index++] = str[i];
            word += str[i];
            //cout << "\nword[index]"<<word[index-1];
        }
        else {
           // word[index] ='\0';
            cout<< "word="<<temp;
            str.replace(i+1, temp.length(), temp);
            index=0;
            temp.clear();
        }
             
    }
    //last World
    str.replace(0, temp.length(), temp);
    
    cout<<"\n str="<<str;
    return 0;
}

//==================================================
#include <iostream>
#include <string>
#include<sstream>
#include<vector>
#include<algorithm>

using namespace std;
/// i/p => "My name is Sagar"
///o/p => "yM eman si ragaS"
void reverseString(string& str){
    /*int len = str.length();
    string result="", temp="";
    for(int i =len-1 ; i >=0; --i){
        
        if ( str[i] != ' '){
            temp+=str[i];
        }else {
            result = temp +' '+result;
            temp.clear();
        }
    }
    result = temp +' '+result;
    cout<<"\nResult :"<<result;
    */
    stringstream ss(str);
    string temp;
    vector<string> v;
    
    while (ss>>temp){ // >> done tokenizer
       v.push_back(temp);
    }
    cout<<"\n print vector:";
    for(auto i :v){
        cout<<" "<<i;
    }
    //now reverse each word from array
    string result;
     for(auto word :v){
        std::reverse(word.begin(),word.end());
        result = word + " "+result;
    }
    
    cout<<"\n Result:"<<result;
    
}

int main()
{
    cout<<"Hello World";
    string str = "My Name is Sagar";
    cout<<"\n str="<<str;
    reverseString(str);
}
===========================================================================
/* more optimized way */

#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    // Write C++ code here
    string str ="My Name is Khan";
    string result ="";
     string temp ="";
    for (int i = str.length()-1; i>=0;--i){
        if (str[i] !=' '){
            temp += str[i];
        }else {
            result = result.empty()?temp: result+ ' '+temp;
            temp.clear();
       }
    }
    result += ' '+temp; 
    cout<<"\n"<<result;
    return 0;
}
