//
//  Observer.hpp
//  Assignment4
//
//  Created by Huzaifa Asif on 2017-12-01.
//  Copyright © 2017 Huzaifa Asif. All rights reserved.
//

#ifndef Observer_hpp
#define Observer_hpp
#include "Track.hpp"
#include <stdio.h>
//#include "Subject.hpp"
class Subject;
class Observer{
public:
    virtual void update(Subject *subject);
    
    int operator==(const Observer & obs) const {
        return this == & obs;
    }
};
#endif /* Observer_hpp */
