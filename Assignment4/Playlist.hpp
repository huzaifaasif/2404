//
//  Playlist.hpp
//  Assignment2
//
//  Created by Huzaifa Asif on 2017-10-27.
//  Copyright © 2017 Huzaifa Asif. All rights reserved.
//

#ifndef Playlist_hpp
#define Playlist_hpp

#include <iostream>
#include <stdio.h>
#include <string>
#include <ostream>
#include "Users.hpp"
#include "User.hpp"
#include "Track.hpp"
#include "Subject.hpp"
#include "Observer.hpp"
#include <tuple>

using namespace std;


class Playlist: public Subject, public Observer{
public:
    
    
    Playlist();
    ~Playlist(); //destructor
    Playlist(string &user_id, string &playlist_name); //constructor
    Playlist(string &user_id, string &playlist_name, int trackID);
    
    //-----update
    virtual void update(Subject &subject);
    void startFollowing(Playlist &subject, Playlist &observer);
    
    //printing
    string toString() const;  //print the playlist
    string toStringForPlaylistTrack() const;
    
    void printOn(Playlist &aPlaylist) const;
    void printOnForplaylistTracks(Playlist &aPlaylist) const;
    
    //setter
    void setTrackID(int i, int track_id);
    void setPlaylistToTrack(Track *track);
    void initTracks(Playlist &aPlaylist, Tracks &tracks, Playlist *subject, int &count, bool addingTrack, bool isAdd);
    
    
    Track *getLastElement();
        
    //getters
    bool getFollowersData(string &input, string &observer_userid, string &subject_userid, string &playlist_name);
    Track *getPlaylistToTrackInstance(int index);
    Track *getPlaylistCollectionWithTrackInstance(int index);
    size_t sizeOfPlaylistToTrack();
    size_t sizeOfPlaylistWithTrackID();
    void setPlaylistToTrackWithTrackID(Playlist *aPlaylist);
    Playlist *getPlaylistWithTrackID(int index);
    
    void getData(string &input, string &user, string &playlist, int &track);
    
    string getUserID(int index);
    int getTrackID(int index);
    int getTrackID();
    string getKeyword(string input);
    string getPlaylistName(int index);
    string playlistName();
    string userID();
    
    //bool userMatches(Users *users, int count);
    
   // Playlist *getPlaylistObject(string playlist_name);
    
    //string getPlaylistNameTst();
    string getPlaylistNameForUser();
    size_t sizeOfPlaylistCollection();
    
    //add playlist to user
    void usersToRespectivePlaylist(class Users *users,  int count);
    //add tracks to playlist
    void playlistToRespectiveTrack(class Tracks *tracks, int countForPlaylistToTrack);
    
    void addTrackPointer(Track *track);
    
    //DELETE
    void removeData(string input, Users *userToPlaylistPointer);
   // void deleteTrack(string input, Track *playlistToTrackPtr);
    
    //void removeData(string input);
    void showPlaylistCollection(Playlist *playlist);
    void showPlaylistTrackCollection(Playlist *playlist);
    void showPlaylistwithUsersCollection(Users *users);
    
    void attachPlaylist(string input);
    //---NEW: Checks if playlist exists
    bool doesPlaylistExist(string playlist_name);
    string getUserID();
    
private:
    string user_id, playlist_name;
    int trackID;
    vector<Playlist*> playlist_collection;
    vector<Playlist*> playlist_collection_with_trackID;
    vector<Track*> playlistToTrackCollection;
};

ostream & operator<<(ostream &out, const Playlist &aPlaylis);

#endif /* Playlist_hpp */
