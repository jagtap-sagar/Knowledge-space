
#include <iostream>
#include <algorithm>
using namespace std;

int DecimalToBinary(int num) {
    string binary;
    for (;num >0 ;num /=2) {
      /*  if (num %2 ==0)
            binary += '0';
        else  //num%2 ==1 
            binary += '1';
            */
        binary += ((num%2))?'1':'0';    
    }
    
    cout<<"=="<<binary<<"\n";
    std::reverse(binary.begin(), binary.end());
    return stoi(binary);
}

int main()
{
    int input =5;
    std::cout<<"DecimalToBinary"<<DecimalToBinary(input);

    return 0;
}
