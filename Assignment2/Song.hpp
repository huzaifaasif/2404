//
//  Song.hpp
//  Assignment2
//
//  Created by Huzaifa Asif on 2017-10-17.
//  Copyright © 2017 Huzaifa Asif. All rights reserved.
//

#ifndef Song_hpp
#define Song_hpp

//#include <stdio.h>
#include <string>
#include <ostream>

using namespace std;

class Song{
    
public:
    Song();
    Song(const string &aTitle, const string &aComposer, const int anId);
    ~Song();
    
    string toString() const;
    
    //printing
    void printOn(ostream & ostr) const;

    
    //getters
    string getTitle();
    string getComposer();
    Song *getSongInstance();
    int getID();
    
private:
    string title, composer;
    int id;
    
    
    
};

ostream & operator<<(ostream &out, const Song &aSong);


#endif /* Song_hpp */
