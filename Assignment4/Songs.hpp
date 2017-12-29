//
//  Songs.hpp
//  Assignment2
//
//  Created by Huzaifa Asif on 2017-10-19.
//  Copyright © 2017 Huzaifa Asif. All rights reserved.
//

#ifndef Songs_hpp
#define Songs_hpp

#include <stdio.h>
#include <vector>
#include "Song.hpp"
#include "Songs.hpp"
#include "Track.hpp"
#include "Tracks.hpp"

//storing collection of Song objects
class Songs{
public:
    Songs();
    ~Songs();
    
    Song *findByID(int anID);   //unnecessary FOR NOW
    void add(Song * aSong);
    void remove(Song & aSong);
    
    //getter
    void getData(string &input);
    size_t getSongCollectionSize();
    Song *getSongInstance(int index);
    
    
    //bool
    bool isEmpty() const;
    
    //show
    void showSongCollection(Songs *song);
    
    void tracksToRespectiveSongs(Tracks *tracks, int count);
    
    void printOn(ostream & out) const;
    //remove data
    void removeData(string input, Tracks *track_ptr);
    
    vector<Song*>::iterator findPosition(Song & aSong);
    
private:
    bool displayingStatus;
    int count=0;
    vector<Song*> collection;   //pointer to Song object
    
    //;
};

ostream & operator<<(ostream & out, const Songs & Songs);
#endif /* Songs_hpp */
