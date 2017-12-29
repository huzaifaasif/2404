//
//  genericClass.hpp
//  Assignment2
//
//  Created by Huzaifa Asif on 2017-10-21.
//  Copyright © 2017 Huzaifa Asif. All rights reserved.
//

#ifndef genericClass_hpp
#define genericClass_hpp

#include <stdio.h>
#include <string>
#include "Songs.hpp"
#include "Recordings.hpp"
#include "Track.hpp"
#include "Tracks.hpp"
#include "Users.hpp"
#include "Playlist.hpp"

using namespace std;

class genericClass{
public:
    
    //parse command strings methods
     void performOperation(string &input);
     static void parseIntFromString(string &input, int &id);
     void readFile(string fileName);
    
    //error related methods
    static bool errorCheck(string &input, size_t &log_pos);
    static void printError();
    
    static string toTitleCase(string &str);
    static void moveToEnd(string &str, string value);
    
    void logCommands(string input, int count);
    bool logErrorCheck(string input, size_t log_pos);
    
    static bool comments(string input);
    bool commentCheck(string input);
    
private:
    static size_t add_pos, delete_pos, help_pos, show_pos, read_pos, command, log_pos, quit;
    
    //songs
    Songs songs; //instantiating Songs object
    Recordings recordings;
    Recordings * recording_ptr;
    
    Tracks * tracks_ptr;
    Songs * song_ptr;

    Users users;
    
    Track track;
    Tracks tracks;
    
    Playlist playlist;
    
    Users * playlist_ptr;
    Playlist * playlistPointer;
    
    
    
    int countForTracks=0;
    int count=0;
    
    int countForPlaylist=0;
    int countForPlaylistToTrack=0;
    
    //logging
    static string log_command, start, stop;

    static size_t comment_position;
    
       
};


#endif /* genericClass_hpp */
