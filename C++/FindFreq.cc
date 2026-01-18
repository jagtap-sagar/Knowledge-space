/*
This code work for lower alphabets.
ex. i/p =>Hello 
    o/p=> 2  // here ll occurs 2 time
    "HeLLo"; => here H make tolower H bacome h, LL beacome ll. 
    
*/
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int HightFreq(string& str){
    cout<<"\n"<<str;;
    int arr[26]={0};
    //int arr[256] = {0}; 
    int fraq=0;
    //for(unsigned char  i:str){
    for(auto i:str){
        //for(int i=0;i<str.length();i++){
        cout<<"\n"<<i<<" ";
        arr[tolower(i)-'a']++;//arr[str[i]-'a']++;
    }
    
    cout<<"\n";
    for (int i=0;i<26;i++){
        if (fraq < arr[i]){
            fraq = arr[i];
        }
    }

    cout<<"\n"<<fraq;//std::max(arr);
    return fraq;   
}

int main()
{
    std::cout<<"Hello World";
    string s="GeeksforGeeks";//"HeLLo";
    HightFreq(s);
    return 0;
}
