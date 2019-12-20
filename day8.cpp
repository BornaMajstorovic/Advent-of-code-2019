//
//  main.cpp
//  day8
//
//  Created by Borna on 08/12/2019.
//  Copyright © 2019 Borna. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;


int main(int argc, const char * argv[]) {
    int width = 25;
    int height = 6;
    int img[height][width];
    int rez = 0;
    int min_0 = numeric_limits<int>::max();
    char input[25000];
    
    string line;
    ifstream myfile;
    myfile.open("day8.txt");
    myfile >> input;
    
    int i = 0;
    
    while (i < strlen(input)) {
        int digits[3] = {0};
        for (int j = 0; j < width*height; j++) {
            ++digits[input[i+j] - '0'];
        }
        
        if (digits[0] < min_0) {
            min_0 = digits[0];
            rez = digits[1] * digits[2];
        }

        i += width * height;

    }
    
    cout << rez << endl; //first done
    
    // 0 black 1 white 2 transperent
    for (int i = 0; i < height; i++) {
          for (int j = 0; j < width; j++) {
              img[i][j] = 2;
          }
    }
    
    int layer = 0;
    while (layer < strlen(input)) {
        for (int i = 0; i < height;i++) {
            for (int j = 0; j < width; j++) {
                if (img[i][j] == 2) {
                    img[i][j] = input[layer + i * width + j] - '0';
                }
            }
        }
        layer += width * height;
    
    }
      
    for (int i = 0; i < height; ++ i) {
           for (int j = 0; j < width; ++ j) {
               if (img[i][j])
                   cout << "1";
               else
                   cout << ".";
           }
           cout << "\n";
       }
   
 
       return 0;
}



