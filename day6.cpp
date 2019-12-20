//
//  main.cpp
//  day6
//
//  Created by Borna on 06/12/2019.
//  Copyright © 2019 Borna. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <boost/algorithm/string/split.hpp>
#include <boost/algorithm/string/classification.hpp>
#include <math.h>
using namespace std;

map<string, set<string>> orbits; //child - parents
map<string, int> parentsCount; // child - number of parents
map<string, int> santasMap; // string - santa, santasParent, santasParentParent, int 0,1,2....
map<string, int> myMap; //


void insertValue(map<string, set<string>> &mapa, string const &key, string const &value){
    
    map<string, set<string>> :: iterator alreadyExist = mapa.find(key);
    
    if(alreadyExist != mapa.end()){ //if set already exist add another value to him
        alreadyExist->second.insert(value);
    } else { //add value to new set
        set<string> temp;
        temp.insert(value);
        mapa.insert(make_pair(key, temp));
    }
}

long getOrbitParentCount(const string &key, long rez){
    
    map<string, set<string>> :: iterator findKey = ::orbits.find(key);
    
    if(findKey != orbits.end()){
        set<string> parents = orbits[key];
        for (set<string>::iterator it = parents.begin(); it != parents.end(); it++) {
            rez += 1 + getOrbitParentCount(it->c_str(), rez);
        }
    }
  
    return rez;
}

long sumOfDirectAndIndirectOrbits(){
    long sum = 0;
    
    string line;
    vector<std::string> dataByLine;
    
    ifstream myfile;
    
    myfile.open("day6.txt");
    
    if(!myfile)
        cout << "cant open file" <<endl;
    while(!myfile.eof()){
        getline(myfile, line);
        if(!line.empty()){
            dataByLine.emplace_back(line);
        }
        else break;
    }
    
    
    for (vector<string>::iterator it = dataByLine.begin(); it != dataByLine.end(); it++) {
        vector<string> pair;
        boost::split(pair, it->c_str(), boost::is_any_of(")"));
        insertValue(orbits, pair[1], pair[0]);
    }
    
    
    for (map<string, set<string>>::iterator it = orbits.begin(); it != orbits.end(); it++) {
        sum += getOrbitParentCount(it->first, 0);
    }
    
    
    return sum;
}

void  visitPlanets(const string &planet, int numberOfTransfers, bool isItMe){
    if (isItMe) {
        map<string, int>::iterator it = myMap.find(planet);
       
        if (it == myMap.end()) {
            myMap[planet] = numberOfTransfers;
           
            set<string> parents = orbits[planet];
            for (set<string>::iterator it3 = parents.begin(); it3 != parents.end() ; it3++) {
                string planetCurentlyVisited = it3->c_str();
                visitPlanets(planetCurentlyVisited, (numberOfTransfers +1) , true);
            }
        }
        
    } else {
        map<string, int>::iterator it = santasMap.find(planet);
        
        if (it == santasMap.end()) {
            santasMap[planet] = numberOfTransfers;
            set<string> parents = orbits[planet];
            for (set<string>::iterator it3 = parents.begin(); it3 != parents.end() ; it3++) {
                string planetCurentlyVisited = it3->c_str();
                visitPlanets(planetCurentlyVisited, numberOfTransfers +1 , false);
            }
        }
    }
}


long distanceBetweenMeAndSanta(){
    long distance = numeric_limits<int>::max();
    
    const string you = "YOU";
    const string santa = "SAN";
    
    visitPlanets(you, 0, true);
    visitPlanets(santa, 0, false);
    

    for(map<string, int>::iterator it = santasMap.begin(); it != santasMap.end(); it++){
      
        const string planet = it->first;
  
        map<string, int>::iterator isItMyPlanet = myMap.find(planet);
        if(isItMyPlanet != myMap.end()){
            if ((santasMap.at(planet) + myMap.at(planet)) < distance ) {
                distance = santasMap.at(planet) + myMap.at(planet);
            }
        }
    }
    
    return distance;
}


int main(int argc, const char * argv[]) {
    
    
    long first = sumOfDirectAndIndirectOrbits();
    cout << first << endl;
    
    long second = distanceBetweenMeAndSanta();
    cout << second - 2;
    
    return 0;
}



