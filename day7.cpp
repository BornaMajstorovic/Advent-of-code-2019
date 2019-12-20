//
//  main.cpp
//  day7
//
//  Created by Borna on 07/12/2019.
//  Copyright © 2019 Borna. All rights reserved.
//

#include <iostream>
#include <boost/algorithm/string/split.hpp>
#include <boost/algorithm//string/classification.hpp>
#include <fstream>

#define POSITION_MODE 0
#define IMMEDIATE_MODE 1
using namespace std;


class Amplifires{
public:
    int phaseSetting, input;
    
    Amplifires(int phase): phaseSetting(phase){}
    
    long run(int phase, long input, bool firstCircle){
        
        string line;
        vector<long> data;
        vector<string> splittedString;
     
        
        fstream puzzleInput("day7.txt");
        puzzleInput >> line;
        boost::split(splittedString, line, boost::is_any_of(","));
        for (auto &value: splittedString) {
            data.emplace_back(stoi(value));
        }
      
        
        long opcode = 0, i = 0, output = 0;
        bool firstTime = false;
        
        while (true) {
            opcode = data[i];
            
            const long DE = opcode % 100;
            const long C = (opcode / 100) % 10;
            const long B = (opcode / 1000) % 10;
            const long A = (opcode / 10000) % 10;
            
            auto &parametarC = C == POSITION_MODE ? data[data[i + 1]] : data[i + 1];
            auto &parametarB = B == POSITION_MODE ? data[data[i + 2]] : data[i + 2];
            auto &parametarA = A == POSITION_MODE ? data[data[i + 3]] : data[i + 3];
            
            if (DE == 1) {
                parametarA = parametarB + parametarC;
                i += 4;
                
            } else if (DE == 2){
                parametarA = parametarB * parametarC;
                i += 4;
                
            } else if (DE == 3){
                if (firstCircle == true) {
                     if (firstTime == false) {
                            parametarC = phase;
                            firstTime = true;
                    } else
                            parametarC = input;
                }
                else
                    parametarC = input;
                
                i += 2;
                
            } else if (DE == 4) {
                output = parametarC;
                i += 2;
                break;
                
                
            } else if (DE == 5){
                if (parametarC == 0) {
                    i += 3;
                    continue;
                }
                i = parametarB;
                
            } else if (DE == 6){
                if (parametarC != 0) {
                    i += 3;
                    continue;
                }
                i = parametarB;
                
            } else if (DE == 7){
                if (parametarC < parametarB) {
                    parametarA = 1;
                } else parametarA = 0;
                
                i += 4;
                
                
            } else if (DE == 8){
                if (parametarC == parametarB) {
                    parametarA = 1;
                } else parametarA = 0;
                
                i += 4;
                
            } else if(DE == 99){
                break;
            }
            
        }
        return  output;
    }
    
};

long runAmplifiers(int *phase){
    Amplifires  ampA = Amplifires(phase[0]),
                ampB = Amplifires(phase[1]),
                ampC = Amplifires(phase[2]),
                ampD = Amplifires(phase[3]),
                ampE = Amplifires(phase[4]);
    long output;
    
    output = ampA.run(ampA.phaseSetting, 0, true);
    output = ampB.run(ampB.phaseSetting, output,true);
    output = ampC.run(ampC.phaseSetting, output, true);
    output = ampD.run(ampD.phaseSetting, output, true);
    output = ampE.run(ampE.phaseSetting, output, true);
    long outputEnd = output;

    
    while (true) {
        output = ampA.run(ampA.phaseSetting, output, false);
        output = ampB.run(ampB.phaseSetting, output, false);
        output = ampC.run(ampC.phaseSetting, output, false);
        output = ampD.run(ampD.phaseSetting, output, false);
        output = ampE.run(ampE.phaseSetting, output, false);
        if (outputEnd == output) {
            break;
        } else outputEnd = output;
        
    }
   
   
    
    return output;
}

int main(int argc, const char * argv[]) {
    long output = 0;
    long highestSingal = numeric_limits<int>::min();
    int permutations[] = {5,6,7,8,9};
   
    do {
        output = runAmplifiers(permutations);
       
        highestSingal = max(highestSingal, output);
        
        
    } while(next_permutation(permutations, permutations + 5));
    
    cout << highestSingal << endl;
    

    return 0;
}


//part1
/*
 //
 //  main.cpp
 //  day7
 //
 //  Created by Borna on 07/12/2019.
 //  Copyright © 2019 Borna. All rights reserved.
 //

 #include <iostream>
 #include <boost/algorithm/string/split.hpp>
 #include <boost/algorithm//string/classification.hpp>
 #include <fstream>

 #define POSITION_MODE 0
 #define IMMEDIATE_MODE 1
 using namespace std;

 class Amplifires{
 public:
     int phaseSetting, input;
     
     Amplifires(int phase): phaseSetting(phase){}
     
     int run(int phase, int input){
         
         string line;
         vector<int> data;
         vector<string> splittedString;
         
         fstream puzzleInput("day7.txt");
         puzzleInput >> line;
         boost::split(splittedString, line, boost::is_any_of(","));
         for (auto &value: splittedString) {
             data.emplace_back(stoi(value));
         }
         
         
         int opcode = 0, i = 0, output = 0;
         bool firstTime = false;
         
         while (true) {
             opcode = data[i];
             
             const int DE = opcode % 100;
             const int C = (opcode / 100) % 10;
             const int B = (opcode / 1000) % 10;
             const int A = (opcode / 10000) % 10;
             
             auto &parametarC = C == POSITION_MODE ? data[data[i + 1]] : data[i + 1];
             auto &parametarB = B == POSITION_MODE ? data[data[i + 2]] : data[i + 2];
             auto &parametarA = A == POSITION_MODE ? data[data[i + 3]] : data[i + 3];
             
             if (DE == 1) {
                 parametarA = parametarB + parametarC;
                 i += 4;
                 
             } else if (DE == 2){
                 parametarA = parametarB * parametarC;
                 i += 4;
                 
             } else if (DE == 3){
                 if (firstTime == false) {
                     parametarC = phase;
                     firstTime = true;
                 } else
                     parametarC = input;
                 
                 i += 2;
                 
             } else if (DE == 4) {
                 output = parametarC;
                 i += 2;
                 
             } else if (DE == 5){
                 if (parametarC == 0) {
                     i += 3;
                     continue;
                 }
                 i = parametarB;
                 
             } else if (DE == 6){
                 if (parametarC != 0) {
                     i += 3;
                     continue;
                 }
                 i = parametarB;
                 
             } else if (DE == 7){
                 if (parametarC < parametarB) {
                     parametarA = 1;
                 } else parametarA = 0;
                 
                 i += 4;
                 
                 
             } else if (DE == 8){
                 if (parametarC == parametarB) {
                     parametarA = 1;
                 } else parametarA = 0;
                 
                 i += 4;
                 
             } else if(DE == 99){
                 break;
             }
             
         }
         return  output;
     }
     
 };

 int runAmplifiers(int *phase){
     Amplifires  ampA = Amplifires(phase[0]),
                 ampB = Amplifires(phase[1]),
                 ampC = Amplifires(phase[2]),
                 ampD = Amplifires(phase[3]),
                 ampE = Amplifires(phase[4]);
     int output;
     
     output = ampA.run(ampA.phaseSetting, 0);
     output = ampB.run(ampB.phaseSetting, output);
     output = ampC.run(ampC.phaseSetting, output);
     output = ampD.run(ampD.phaseSetting, output);
     output = ampE.run(ampE.phaseSetting, output);
     
     return output;
 }

 int main(int argc, const char * argv[]) {
     int output = 0;
     int highestSingal = numeric_limits<int>::min();
     int permutations[] = {0,1,2,3,4};
    
     do {
         output = runAmplifiers(permutations);
        
         highestSingal = max(highestSingal, output);
         
         
     } while(next_permutation(permutations, permutations + 5));
     
     cout << highestSingal << endl;
     

     return 0;
 }

 */
