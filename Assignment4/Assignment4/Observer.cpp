//
//  Observer.cpp
//  Assignment4
//
//  Created by Huzaifa Asif on 2017-12-01.
//  Copyright © 2017 Huzaifa Asif. All rights reserved.
//

#include "Observer.hpp"
#include <iostream>
#include "Track.hpp"
#include "Subject.hpp"
using namespace std;

void Observer::update(Subject *subject){
    cout <<"REGISTERED!"<<endl;
}
