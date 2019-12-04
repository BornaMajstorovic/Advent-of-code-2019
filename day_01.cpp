//
//  main.cpp
//  day1
//
//  Created by Borna on 27/11/2019.
//  Copyright © 2019 Borna. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
using namespace std;

int a(){
    int i = 0 ;
    int arr[1000];
    int sum = 0;

    string line;
    ifstream myfile ;
    myfile.open("day1.txt");
    
    if(!myfile)
        cout << "cant open file" << endl;
    while(!myfile.eof()){
        getline(myfile, line);
        if(!line.empty()){
        arr[i] = stoi(line);
        i++;
        }
        else break;
    }
    
    for(int j = 0; j < i; j++) {
        int number = arr[j];
        number = number/3 - 2;
        sum+=number;
    }
    myfile.close();
    return sum;
}

int b() {
    int i = 0 ;
    int arr[1000];
    int sum = 0;

    string line;
    ifstream myfile ;
    myfile.open("day1.txt");
    
    if(!myfile)
        cout << "cant open file" << endl;
    while(!myfile.eof()){
        getline(myfile, line);
        if(!line.empty()){
        arr[i] = stoi(line);
        i++;
        }
        else break;
    }
    
    for(int j = 0; j < i; j++) {
        int number = arr[j];
        number = number/3 - 2;
        sum+=number;
        while(number/3 > 1) {
            number = number/3 -2;
            sum += number;
        }
    }
    myfile.close();
    
    return sum;
    
}


int main(int argc, const char * argv[]) {
   
    int sum = a();
    int sum2 = b();
    
    cout << sum << endl;
    cout << sum2 << endl;
    return 0;
}
