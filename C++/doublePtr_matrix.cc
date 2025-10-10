
    #include <iostream>

    using namespace std;
    
    int main() {
       int **mat= new int* [3]; //take double pointer 
       for(int i=0;i<3;i++){
           mat[i]= new int[3]; // Line 7 & 9 imp
       }
        int index=0;
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                mat[i][j]=index++;
            }
        }
        //print matrix
        for(int i=0;i<3;i++){
            cout<<"\n";
            for(int j=0;j<3;j++){
                cout<<" "<<mat[i][j];
            }
        }
        
        return 0;
    }
