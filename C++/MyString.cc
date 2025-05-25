/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
//#include<string>
//#include <string.h>


using namespace std;

//struct MyString{
class MyString{
  char *data;
  int capacity;
  int length;
 public:  // in case struct REMOVE THIS LINE.
  unsigned int len(){
      unsigned int len=0;
      while(data[len++] !='\0');
      return len-1;
  }
  
 void strcpy(char *src,const char *dest) {
      //int n= sizeof(dest);
      int i=0;
      int index=0;
      
     for(;dest[i]!='\0';i++){
          src[index++]=dest[i];
      }
      src[index]='\0';
      cout<<" len="<<index;
       int len = 0;
  }
  
  MyString(const char *str){
      data = new char(sizeof(str));
      //memcpy(data,str,sizeof(*str));
      strcpy(data,str);
       capacity =len()+1;
       length = len();
  }
    
};

int main()
{
    std::cout<<"Hello World";
    
    MyString s("Sagar");
   // cout<<"\n "<<s.data<<" len="<<s.length<<" cap="<<s.capacity;

    const char *str="Sagar";
    
    //cout<<"sizeof(str)="<<sizeof(str)<<"sizeof(*str)="<<sizeof(*str)<<"strlen="<<strlen(str);
    
    cout<<"\nlen(str)="<<s.len();
    
    string st("Sagar");
    cout<<" \nlen="<<st.length()<<" Cap="<<st.capacity();
    return 0;
}
