//
//  Track.hpp
//  Assignment2
//
//  Created by Huzaifa Asif on 2017-10-24.
//  Copyright © 2017 Huzaifa Asif. All rights reserved.
//

#ifndef Track_hpp
#define Track_hpp

//contains mp3 files of Song objects
//add -t track_id albumID songID track_number

#include <stdio.h>
#include <string>
#include "Recording.hpp"
#include <vector>

using namespace std;

class Track{
public:
    Track();
    ~Track();
    Track(int track_id, int albumID, int songID, int track_number);
    
    void clearPointer(int index);
    string toString() const;
    
    //getters
    int getAlbumID();
    int getSongID();
    class Recording *getRecordingPointer();
    class Song *getSongPointer();
    int getTrackID();
    Song *getTracksToSongCollectionPtr(int index);
    
  
    //setter
    void setRecordingPtr(class Recording *recordingPtr);
    
    void setSongPtr(class Song *songPtr);
    void setTrackToSongCollection(Song *song);
    size_t getTrackToSongCollectionSize() const;

    
private:
    int track_id, albumID, songID, track_number;
    
    class Song *ptr_song;
    class Recording *ptr_rec;
    
    vector<Song*> tracksToSongCollection;

};

#endif /* Track_hpp */
