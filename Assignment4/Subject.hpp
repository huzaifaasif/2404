//
//  Subject.hpp
//  Assignment4
//
//  Created by Huzaifa Asif on 2017-12-01.
//  Copyright © 2017 Huzaifa Asif. All rights reserved.
//

#ifndef Subject_hpp
#define Subject_hpp

#include <stdio.h>
#include <vector>

#include "Observer.hpp"
using namespace std;
class Playlist;
//class Observer;

class Subject{
    //ArrayList<Observer> observers;
    vector<Playlist*> observers;
    
public:
    void attach(Observer &obs);
    void detach(Observer &obs);
    void notify();
    size_t getObserverSize();
};

#endif /* Subject_hpp */
