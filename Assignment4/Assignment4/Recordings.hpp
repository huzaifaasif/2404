//
//  Recordings.hpp
//  Assignment2
//
//  Created by Huzaifa Asif on 2017-10-24.
//  Copyright © 2017 Huzaifa Asif. All rights reserved.
//

#ifndef Recordings_hpp
#define Recordings_hpp

#include <stdio.h>
#include "Recording.hpp"
#include "Tracks.hpp"
#include <vector>
#include <string>

using namespace std;

class Recordings{
public:
    Recordings();
    ~Recordings();
    
    void getData(string &input, class Tracks &tracks);
    void populatingTrack(Tracks &tracks, class Recording &recording);
    
    void recordingsToRespectiveTrack(Tracks *track_ptr, int count);
    
    //getters
    int getRecordingCollection(int index);
    size_t getRecordingCollectionSize();
    int getRecordingAlbumID(int i);
    Recording *getRecordingInstance(int i);
    
    //setter
    void setRecordingPtr(Recording *recording);
    
    //delete
    void removeData(string input);
  
    void printOn(ostream &o) const;
    
    bool isEmpty() const;
    
    void showRecordingCollection(Recordings *recordings);

    
private:
    vector<Recording*> recordings_collection;
    //vector<class Track*>trck;
};

ostream & operator<<(ostream & out, const Recordings &recordings);

#endif /* Recordings_hpp */
