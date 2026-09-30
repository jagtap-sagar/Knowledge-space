/******************************************************************************
 1. input : My Name is Khan
 output : Khan is Name My
 
 2. input : My Name is Khan
 output :yM emaN si nahK

*******************************************************************************/

#include <iostream>
#include <string>
using namespace std;

//1. Below code for "Khan is Name My" 
void ReverseWord(string& sentence){ 
    string word = "",result =" ";
    int size = sentence.length();
     for(auto& ch : str) {
        if (ch != ' '){
            word +=ch;
        }else{ // space occurs
            result = (result=="") ? word : word+ ' '+result ;
            word ="";
        }// ch occurs
    }//for
    result = word+ ' '+result ;
    cout<<"Result :"<<result;
    sentence ="";
    sentence=result;
}

//2. Each word reverse yM emaN si nahK .
//only  for start from last character, rest of code is same.
void ReverseWord(string& str) {
    string result ="", word =""; 
    for (int i = str.length()-1; i>=0; --i){
        if (str[i] !=  ' '){
            word += str[i];
        } else {// space occurs 
          result =(result.empty()) ? word : word +' ' +result;   
          word ="";
        }
    }//for
    result = word +' ' +result;   
    cout<<"Result :"<<result;
   
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
  
