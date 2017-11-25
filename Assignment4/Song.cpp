//
//  Song.cpp
//  Assignment2
//
//  Created by Huzaifa Asif on 2017-10-17.
//  Copyright © 2017 Huzaifa Asif. All rights reserved.
//

#include "Song.hpp"
#include "Songs.hpp"
#include <string>
#include "genericClass.hpp"

using namespace std;


Song::Song(const string &aTitle, const string &aComposer, const int anId){
    title = aTitle;
    composer = aComposer;
    id = anId;
}

Song::~Song(){
    
}



string Song::toString()const {
    return to_string(id) + " " + title + " " + composer;
}

//maybe...
string Song::getTitle(){
    return title;
}

int Song::getID(){
    return id;
}



//overloading operator
ostream & operator<<(ostream & out, const Song & aSong){
    out << aSong.toString();
    
    return out;
}


