//
//  main.cpp
//  day3
//
//  Created by Borna on 03/12/2019.
//  Copyright © 2019 Borna. All rights reserved.
//
#include <iostream>
#include <fstream>
#include <boost/algorithm/string/split.hpp>
#include <boost/algorithm//string/classification.hpp>
#include <vector>
#include <limits>
using namespace std;

struct Point {
    int x,y;
    
    Point(int x, int y) : x(x), y(y){}
    
    Point(const string &elem) : x(0), y(0) {
        int r(stoi(elem.substr(1)));
        switch (elem[0]) {
            case 'U':
                y = r;
                break;
            case 'D':
                y = -r;
                break;
            case 'L' :
                x = -r;
                break;
            case 'R':
                x = r;
                break;
        }
    }
    
    void operator+=(const Point &p)
    {
        x += p.x;
        y += p.y;
    }
};

struct Line {
    Point start, end;
    
    Line(const Point &start, const Point &end) : start(start), end(end){}
    int length() {
        return abs(start.x - end.x) + abs(start.y - end.y);
    }
};

int intersecion(const Line &l1, const Line &l2) {
    
    if(l1.start.x != l1.end.x) {
        if(l2.start.x != l2.end.x) {
            return numeric_limits<int>::max();
        } else {
            if(((l1.start.x > l2.start.x && l1.end.x < l2.start.x) || (l1.start.x < l2.start.x && l1.end.x > l2.start.x))
               &&
               ((l2.start.y > l1.start.y && l2.end.y < l1.start.y) || (l2.start.y < l1.start.y && l2.end.y > l1.start.y))) {
                return abs(l2.start.x) + abs(l1.start.y);
            }
            return numeric_limits<int>::max();
        }
    } else {
        if(l2.start.y != l2.end.y) {
            return numeric_limits<int>::max();
        } else {
            if(((l1.start.y > l2.start.y && l1.end.y < l2.start.y)
                || (l1.start.y < l2.start.y && l1.end.y > l2.start.y))
               && ((l2.start.x > l1.start.x && l2.end.x < l1.start.x)
                   || (l2.start.x < l1.start.x && l2.end.x > l1.start.x)))
            {
                return abs(l1.start.x) + abs(l2.start.y);
            }
            return numeric_limits<int>::max();
        }
    }
    
    return 0;
}

int main(int argc, const char * argv[]) {
    
    string line1, line2;
    ifstream myfile("day3.txt");
    myfile >> line1 >> line2;
    
    while(myfile) {
        vector<string> vector1, vector2;
        boost::split(vector1, line1, boost::is_any_of(","));
        boost::split(vector2, line2, boost::is_any_of(","));
        
        Point current = *new Point(0,0);
        //Point current(0,0);
        vector<Point> point1, point2;
        
        point1.emplace_back(current);
        for(auto &elem : vector1) {
            Point p(elem);
            current += p;
            point1.emplace_back(current);
        }
        
        current.x = 0; current.y = 0;
        point2.emplace_back(current);
        for(auto &elem : vector2){
            Point p(elem);
            current += p;
            point2.emplace_back(current);
        }
        
        vector<Line> path1, path2;
        
        for(size_t i = 1; i < point1.size(); i++) {
            path1.emplace_back(point1[i-1],point1[i]);
        }
        for(size_t i = 1; i < point2.size(); i++){
            path2.emplace_back(point2[i-1], point2[i]);
        }
        
        int minDistance = numeric_limits<int>::max();
        int minSteps = numeric_limits<int>::max();
        
        int steps1 = 0;
        for(auto &line1 : path1){
            int steps2 = 0;
            for(auto &line2 : path2) {
                int distance = intersecion(line1, line2);
                minDistance = min(minDistance, distance);
                
                if(distance != numeric_limits<int>::max()){
                    minSteps = min(minSteps, steps1 + abs(line1.start.y - line2.start.y) + steps2 + abs(line1.start.x - line2.start.x));
                }
                steps2 += line2.length();
            }
            steps1 += line1.length();
        }
        
        
      
        
        
        cout << "distance is " << minDistance << " min num of steps is " << minSteps << endl;
        
        break;
    }
    
    return 0;
}

