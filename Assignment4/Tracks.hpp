//
//  Tracks.hpp
//  Assignment2
//
//  Created by Huzaifa Asif on 2017-10-24.
//  Copyright © 2017 Huzaifa Asif. All rights reserved.
//

#ifndef Tracks_hpp
#define Tracks_hpp

#include "Recording.hpp"
#include "Track.hpp"
#include <stdio.h>
#include <vector>
#include "Recordings.hpp"
#include "Song.hpp"

class Tracks{
public:
    Tracks();
    ~Tracks();
    
    void setTrackCollection(Recording *recording);
    void getData(string &input);

    class Track *getTrackAddress(int index);
    class Track getTrackInstance(int index);
    
    size_t sizeOfTrackCollection();
    
    //getters
    int getAlbumID(int index);
    int getSongID(int index);
    int getTrackID(int index);
    size_t getTrackCollectionSize();
    
    bool isEmpty() const;
    
    //setter
    void setSongPtr(Song *songPtr);
   // void tracksToRespectiveAlbum(class Recordings *recordings);
    
    void tracksToRespectiveSongs(class Songs *song_ptr, int count);
    
    void showTracksCollection(Tracks *tracks) const;
    
    void removeData(string input, class Recordings *rec_ptr);
    void printOn(ostream &o) const;
    
    
private:
   // vector<Recording*> tracks_collection;
    vector<Track*> tracks_collection;
    
};
ostream & operator<<(ostream & out, const Tracks & tracks);
ostream & operator<<(ostream & out, const Track & track);
#endif /* Tracks_hpp */
