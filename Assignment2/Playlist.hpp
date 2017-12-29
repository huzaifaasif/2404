//
//  Playlist.hpp
//  Assignment2
//
//  Created by Huzaifa Asif on 2017-10-27.
//  Copyright © 2017 Huzaifa Asif. All rights reserved.
//

#ifndef Playlist_hpp
#define Playlist_hpp

#include <stdio.h>
#include <string>
#include <ostream>
#include "Users.hpp"
#include "Track.hpp"

using namespace std;


class Playlist{
public:
    Playlist();
    ~Playlist(); //destructor
    Playlist(string &user_id, string &playlist_name); //constructor
    Playlist(string &user_id, string &playlist_name, int trackID);
    
    //printings
    string toString() const;  //print the playlist
    string toStringForPlaylistTrack() const;
    
    void printOn(Playlist &aPlaylist) const;
    void printOnForplaylistTracks(Playlist &aPlaylist) const;
    
    //getter
    void getData(string &input);
    string getUserID(int index);
    int getTrackID(int index);
    string getKeyword(string input);
    string getPlaylistName(int index);
    //string getPlaylistNameTst();
    string getPlaylistNameForUser();
    size_t sizeOfPlaylistCollection();
    
    
    void usersToRespectivePlaylist(class Users *users,  int count);
    void playlistToRespectiveTrack(class Tracks *tracks, int countForPlaylistToTrack);
    
    void addTrackPointer(Track *track);
    
    void removeData(string input, Users *userToPlaylistPointer);
    //void removeData(string input);
    void showPlaylistCollection(Playlist *playlist);
    void showPlaylistTrackCollection(Playlist *playlist);
    void showPlaylistwithUsersCollection(Users *users);
    
private:
    string user_id, playlist_name;
    int trackID;
    vector<Playlist*> playlist_collection;
    vector<Playlist*> playlist_collection_with_trackID;
    vector<Track*> playlistToTrackCollection;
};

ostream & operator<<(ostream &out, const Playlist &aPlaylis);

#endif /* Playlist_hpp */
