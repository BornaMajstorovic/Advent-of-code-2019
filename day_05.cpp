//
//  main.cpp
//  day5
//
//  Created by Borna on 05/12/2019.
//  Copyright © 2019 Borna. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <boost/algorithm/string/split.hpp>
#include <boost/algorithm//string/classification.hpp>
using namespace std;

#define POSITION_MODE 0
#define IMMEDIATE_MODE 1

long diagnosticCode(int input){
    long rez = 0;
    string line;
    ifstream myfile("day5.txt");
    myfile >> line;
    
    while(myfile){
        vector<string> splitedString;
        vector<long> data;
        boost::split(splitedString, line, boost::is_any_of(","));
        
        for(auto &elem : splitedString){
            data.emplace_back(stoi(elem));
        }
        
        long opcode;
        long i = 0;
        
        while (true) {
            opcode = data[i];
            
            const int DE = opcode % 100;
            const int C = (opcode / 100) % 10;
            const int B = (opcode / 1000) % 10;
            const int A = (opcode / 10000) % 10;
           
            
            if (DE == 1) {
                
                auto &parametarC = C == POSITION_MODE ? data[data[i + 1]] : data[i + 1];
                auto &parametarB = B == POSITION_MODE ? data[data[i + 2]] : data[i + 2];
                auto &parametarA = A == POSITION_MODE ? data[data[i + 3]] : data[i + 3];
                
                parametarA = parametarB + parametarC;
                i += 4;
                
            } else if (DE == 2){
                
                auto &parametarC = C == POSITION_MODE ? data[data[i + 1]] : data[i + 1];
                auto &parametarB = B == POSITION_MODE ? data[data[i + 2]] : data[i + 2];
                auto &parametarA = A == POSITION_MODE ? data[data[i + 3]] : data[i + 3];
                
                parametarA = parametarB * parametarC;
                i += 4;
                
            } else if (DE == 3){
                
                auto &parametarC = C == POSITION_MODE ? data[data[i + 1]] : data[i + 1];
                parametarC = input;
                i += 2;
                
            } else if (DE == 4) {
                
                auto &parametarC = C == POSITION_MODE ? data[data[i + 1]] : data[i + 1];
                rez = parametarC;
                i += 2;
              
            } else if (DE == 5){
                
                auto &parametarC = C == POSITION_MODE ? data[data[i + 1]] : data[i + 1];
                if (parametarC == 0) {
                    i += 3;
                    continue;
                }
                auto &parametarB = B == POSITION_MODE ? data[data[i + 2]] : data[i + 2];
                i = parametarB;
         
            } else if (DE == 6){
                
                auto &parametarC = C == POSITION_MODE ? data[data[i + 1]] : data[i + 1];
                if (parametarC != 0) {
                    i += 3;
                    continue;
                }
                auto &parametarB = B == POSITION_MODE ? data[data[i + 2]] : data[i + 2];
                i = parametarB;
                
            } else if (DE == 7){
                
                auto &parametarC = C == POSITION_MODE ? data[data[i + 1]] : data[i + 1];
                auto &parametarB = B == POSITION_MODE ? data[data[i + 2]] : data[i + 2];
                auto &parametarA = A == POSITION_MODE ? data[data[i + 3]] : data[i + 3];
                
                if (parametarC < parametarB) {
                    parametarA = 1;
                } else parametarA = 0;
                
                i += 4;

                
            } else if (DE == 8){
                
                auto &parametarC = C == POSITION_MODE ? data[data[i + 1]] : data[i + 1];
                auto &parametarB = B == POSITION_MODE ? data[data[i + 2]] : data[i + 2];
                auto &parametarA = A == POSITION_MODE ? data[data[i + 3]] : data[i + 3];
                               
                if (parametarC == parametarB) {
                    parametarA = 1;
                } else parametarA = 0;
                
                i += 4;
                
            } else if(DE == 99){
                break;
            }
        }
        break;
    }
     return  rez;
}
    
int main(){
    
    long firstTask = diagnosticCode(1);
    long secondTask = diagnosticCode(5);
    
    cout << firstTask <<endl;
    cout << secondTask <<endl;
    return 0;
}

