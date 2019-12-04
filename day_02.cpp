//
//  main.cpp
//  day2
//
//  Created by Borna on 02/12/2019.
//  Copyright © 2019 Borna. All rights reserved.
//

#include <iostream>
#include <fstream>

using namespace std;

void a(){
      int arr[150];
      int i = 0;
      
      string line;
      ifstream myfile;
      myfile.open("day2.txt");

      if(!myfile) cout << "cant open file" << endl;
      while(!myfile.eof()){
            getline(myfile, line);
            if(!line.empty()){
                arr[i] = stoi(line);
                i++;
            }
            else break;
        }

      arr[1] = 12;
      arr[2] = 2;
      int opcode, firstPosition, secondPosition, thirdPostion;
      int j = 0;
      while(true) {
          opcode = arr[j];
          firstPosition = arr[j+1];
          secondPosition = arr[j+2];
          thirdPostion = arr[j+3];
          
          if(opcode == 1) {
              arr[thirdPostion] = arr[firstPosition] + arr[secondPosition];
          } else if (opcode == 2) {
              arr[thirdPostion] = arr[firstPosition]*arr[secondPosition];
          } else {
              break;
          }
          j+=4;
      }
      
      cout << arr[0]<<endl ;
      
}

void b(){

    int arr[150];
    int i = 0;
    
    string line;
    ifstream myfile;
    myfile.open("day2.txt");

    if(!myfile) cout << "cant open file" << endl;
    while(!myfile.eof()){
          getline(myfile, line);
          if(!line.empty()){
              arr[i] = stoi(line);
              i++;
          }
          else break;
      }
    

    
    for(int x1 = 0; x1 < 100; x1++){
        for(int x2 = 0; x2 < 100; x2++){
            
            int arr2[150];
            for(int k = 0; k < i; k++ ){
                arr2[k] = arr[k];
            }
            
            arr2[1] = x1;
            arr2[2] = x2;
            int opcode, firstPosition, secondPosition, thirdPostion;
            int j = 0;
            while(true) {
                opcode = arr2[j];
                firstPosition = arr2[j+1];
                secondPosition = arr2[j+2];
                thirdPostion = arr2[j+3];
    
                if(opcode == 1) {
                    arr2[thirdPostion] = arr2[firstPosition] + arr2[secondPosition];
                } else if (opcode == 2) {
                    arr2[thirdPostion] = arr2[firstPosition]*arr2[secondPosition];
                } else {
                    break;
                }
                j+=4;
                }
            if(arr2[0] == 19690720) {
                cout << x1*100 + x2 <<endl;
            }
        }
    }

   
}

int main(int argc, const char * argv[]) {
    
    a();
    b();
    
   
    return 0;
}
