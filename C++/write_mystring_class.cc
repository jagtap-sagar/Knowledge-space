// write your own string class with basic operation

class mystring {
  char *str;
  
  public:
  //parametrise 
  mystring(const char *val) {
      if (val==NULL) {
          str = new char[1];
          str[0]='\0';
          //strcpy(str,NULL);
      }
      else
      {
        str = new char[strlen(val)+1];
        strcpy(str,val);
        str[strlen(str)]= '\0';
      }
      
  }
  mystring(const mystring & ref) {
      if( (ref.str )!= NULL) {
          this->str = new char[strlen(ref.str)+1];
          strcpy(str,ref.str);
        str[strlen(ref.str)]= '\0';
      }
  }
  
    
};

int main()
{
    mystring obj("Hello");
    mystring obj2 (obj);
    std::cout<<"Hello World";
///======================
unordered_map<int,int> m;
m[1]=1;
m[100]= 2;
m[23]=10;

unordered_map<int,int> ::iterator it;

for (it=m.begin(); it != m.end(); ++it) {
    std::cout<<"\n"<< it->first<<" "<<it->second;
}
    return 0;
}
