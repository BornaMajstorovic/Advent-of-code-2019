//
//  main.cpp
//  day4
//
//  Created by Borna on 03/12/2019.
//  Copyright © 2019 Borna. All rights reserved.
//

#include <iostream>
using namespace std;



bool part1(int number){
    bool sameDigits = false;
    int digits[6];
    
    int j = 0;
    while (number != 0 ) {
        digits[j] = number % 10;
        number = number / 10;
        j++;
    }
     
    for(int i = 0; i < 6; i++) {
        if(i < 5){
            if(digits[i] < digits[i+1]) return false;
        }
        if(digits[i] == digits[i+1]) sameDigits = true;
    }
    if (sameDigits == false) {
        return false;
    }
    return  true;
    
}


bool part2(int number){
    
    bool sameDigits = false;
    int digits[6];
    int digitsCounter[10] = {0};
    
    int j = 0;
    while (number != 0 ) {
        digits[j] = number % 10;
        number = number / 10;
        j++;
    }
   
    for(int i = 0; i < 6; i++) {
        if(i < 5){
            if(digits[i] < digits[i+1]) return false;
        }
        if(digits[i] == digits[i+1]) sameDigits = true;
    }
    if (sameDigits == false) {
        return false;
    }

    for(int i = 0; i <= 9; i++){
        for (int j = 0; j < 6; j++) {
            if (i == digits[j]) digitsCounter[i]++;
        }
    }
    for (int i = 0; i <= 9; i++) {
        if (digitsCounter[i] == 2) {
            return true;
        }
    }
    return false;
}


int main(int argc, const char * argv[]) {
    
    int from = 134792;
    int to = 675810;
    
    int i = 0, j = 0;
    
    for(int num = from; num <= to; num++){
        if(part1(num) == true) i++;
    }
  
    for(int num = from; num <= to; num++){
        if(part2(num) == true) j++;
    }
    cout << i << "  " << j << endl;
    
    return 0;
}
