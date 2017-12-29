//
//  User.hpp
//  Assignment2
//
//  Created by Huzaifa Asif on 2017-10-27.
//  Copyright © 2017 Huzaifa Asif. All rights reserved.
//

#ifndef User_hpp
#define User_hpp

#include <stdio.h>
#include <string>
#include <ostream>
#include "Playlist.hpp"

using namespace std;

class User{
public:
    User(string userid, string name);
    ~User();
    
    string toString() const;
    void printOn(ostream &ostr) const;
    
    string getUser_ID();
    size_t sizeOfPlaylistPtrCollection();
    
    //User *getUserInstance();
    
    
    //void setPlaylistPtr(class Playlist *playlistPtr);
    
    void addPlaylistPtr(class Playlist *Playlist);
    
    class Playlist *getPlaylistPointer(int index);
    Playlist *getPlaylistInstance(string playlist_name);
    
    //init playlist_with_track_id
    void initPlaylist(Playlist *aPlaylist);
    
    void clearPointer(int i);
    void showObserverCollection(string user_name);
private:
    string userid, name;
    int track_id;
    
    
    //class Playlist *ptr_playlist;
    vector<Playlist*> playlistPtrCollection;
    
};

ostream & operator<<(ostream &out, const User &aUser);
#endif /* User_hpp */
