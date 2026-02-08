class Solution {
public:
    long myAtoi(string s) {
        string result="";
        bool minus = false;
        for ( auto ch : s){
            if (result=="" && ch=='-' ){ // first minus sign
                minus = true;
                continue;        
            } 

            int num = (ch-'0');
            if (result=="" && num==0 && minus){//begin with zero
              //  cout<<"zero :"<<num;
                continue;
            }

            if ( (num>0 && num <=9) && (ch !=' ' ) ) {
                result+=ch;
            } else if (ch == ' ' ){
                continue;
            } else {
                break;
            }
        }//for loop
       
      if (result ==""){return 0;}
      
      long fin_result = stol(result);
      if (fin_result > 2147483647) {
            return -2147483648;
      }
      if ( minus) {
            fin_result = -1*fin_result;
      }
      //cout<<"\n fin_result"<<fin_result<<"\n";
        
      return fin_result; 
    }
};
