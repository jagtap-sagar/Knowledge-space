/******************************************************************************
 input : My Name is Khan
 output : Khan is Name My

*******************************************************************************/

#include <iostream>
#include <string>
using namespace std;

void ReverseWord(string& sentence){
    string word = "",result =" ";
    int size = sentence.length();
  
    //for (int i = size -1;  i>=0; i--){ // This for loop for " yM emaN si nahK" , each word reverse in sentences, rest of the thing is same. 
    for (int i = 0;  i<(size); i++){
        char ch=sentence[i];
        //cout<<" ch :"<<ch<<" "<<"len"<<len;
        //cout<<"\nsentence :"<<sentence[len];
        if (ch != ' '){
            word = ch+word;
         
            //cout<<" Word :"<<word;
        }else{
            //used ternary operator; ' '+word;
            result +=(result=="")?word : ' '+word ; 
           //result +=(result==""?word:' '+word);
           /*if (result==""){
               result=word;
           }else {
               result+=' '+word;
           }*/
    
            word ="";
        }
        
    }
    result +=' ' +word ;
    cout<<"\n result="<<result<<"\n";
    sentence ="";
    sentence=result;
}

int main()
{
    string name = "My Name is Khan";
    cout<< " Without :"<<name<<"\n";
    //reverser -> Khan is Name My
    ReverseWord(name);
    cout<< " ReverseWord :"<<name<<"\n";
    std::cout<<"Hello World";
    
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
            //result=result.empty()? word : result+' '+word;
         // result += (result=="" ? "":" ")+word ; // more understand 
          result += result.empty()? word : ' '+word;
            word ="";
        }
    }
     result += ' '+word;  // last word
     cout<<"\n"<<result;
    return 0;
}
