//
//  genericClass.cpp
//  Assignment2
//
//  Created by Huzaifa Asif on 2017-10-21.
//  Copyright © 2017 Huzaifa Asif. All rights reserved.
//

#include "genericClass.hpp"
#include <string>
#include <iostream>
#include <sstream>
#include "Song.hpp"
#include "Songs.hpp"
#include "Recordings.hpp"
#include <fstream>
using namespace std;

size_t genericClass::quit=0,
genericClass::help_pos=0,
genericClass::add_pos=0,
genericClass::follow_pos=0,
genericClass::delete_pos=0,
genericClass::comment_position=0,

genericClass::show_pos=0,
genericClass::read_pos=0,
genericClass::command=0,
genericClass::log_pos=0;

string genericClass::log_command=" ",
genericClass::start = "start",
genericClass::stop = "stop";

genericClass::genericClass(){}

genericClass::~genericClass(){

}

void genericClass::parseIntFromString(string &str, int &id){
    string temp;
    
    
    for (int i=0; i<str.length(); i++){
        if (isdigit(str[i])){
            for (int j=i; j<str.length(); j++){
                temp += str[j];
            }
            break;
        }
    }
    
    istringstream stream(temp);
    stream >> id;
    
}


//parsing commands
void genericClass::performOperation(string &input){
    
    string operation; //add, delete, show (first word)
    string collection;    //song, recording, playlist, etc
    string keyword;     //s, r
    size_t hyphen = input.find("-");
    operation = input.substr(0, input.find(" ")); //first word
    
    
    keyword = input.substr(hyphen+1, 1);
    
    
    
    if (hyphen==string::npos){
        printError();
        return;
    }
    
    
//    string input = lowercaseInput.substr(hyphen+2);
//    toTitleCase(input);
//    cout <<"NEW IN: "<<input<<endl;
//-----adding-----
    
    if (operation == "add"){

        if (keyword=="s"){  //if it's "s", then create song object+append to the vector
            
            //TRACKS store songs hence they have to exist first
//            if(tracks.isEmpty()){
//                cout <<"Enter tracks first! "<<endl<<endl;
//                return;
//            }
            //adding song
                songs.getData(input);
                song_ptr = &songs;
            
            //storing reference of Songs in Tracks
            
//            if (!tracks.isEmpty()){
//                tracks.tracksToRespectiveSongs(song_ptr, count);
//                count++;
//            }
        
            //if (count <=tracks_ptr->sizeOfTrackCollection() && !tracks.isEmpty()){
            //if (!tracks.isEmpty()){
            
            //}
            
        }
        else if (keyword == "r"){
            recordings.getData(input, tracks);
            
            recording_ptr = &recordings;
            
        }
        else if (keyword == "t"){
            
            //RECORDINGS store Tracks
            if (recordings.isEmpty()){
                cout <<"Enter recordings first! "<<endl<<endl;
                return;
            }
            
            if (songs.isEmpty()){
                cout <<"Enter songs first! "<<endl<<endl;
                return;
            }
            
            //adding tracks
            tracks.getData(input);
            tracks_ptr = &tracks;
            
            //storing reference of Tracks in Recordings
            recordings.recordingsToRespectiveTrack(tracks_ptr, countForTracks);
            countForTracks++;
            
            //storing reference of Songs in Tracks
            tracks.tracksToRespectiveSongs(song_ptr, count);
            count++;
            
            
        }
        
        else if (keyword == "u"){
            
            users.getData(input);
            
        }
        else if(keyword == "p"){
            
            
            playlist.getData(input, userID, playlist_name, trackID);
            playlist_ptr = &users;
            
            //adding playlist to user
            playlist.usersToRespectivePlaylist(playlist_ptr,countForPlaylist);
            countForPlaylist++;
            
            
        }
        //adding tracks to playlist
        else if(keyword == "l"){
            
            playlist.getData(input, userID, playlist_name, trackID);
            
            tracks_ptr = &tracks;
            playlist.playlistToRespectiveTrack(tracks_ptr, countForPlaylistToTrack);
            users.initTest(userID, playlist_name, trackID,  tracks_ptr);
            countForPlaylistToTrack++;
            
        // if the new track has subject's userid
            if (subject!=NULL && subject->getUserID() == playlist.userID()){
                //get user
                //User cind = *users.getUserObject(subject->getUserID());
                //subjectPlaylist = *users.getUserObject(subject->getUserID())->getPlaylistInstance(subject->getPlaylistNameForUser()); //cindy
                
                //get playlist collection of user
                
                
                //notify observers of the change
             //   subject->initTracks(playlist, tracks, subject, countForSubject, true, true);
                
                //countForSubject++;
               // observer->initTracks(playlist, tracks, observer);
          //      subject->notify();
            }
        }
        
    }
    
    //---deleting----
    
    else if (operation == "delete"){
        
        if (keyword == "s"){
            
            if (!songs.isEmpty()){
                tracks_ptr = &tracks;
                songs.removeData(input, tracks_ptr);
                return;
            }
            cout <<"Need to populate the collection prior to deleting!"<<"\n\n";
        }
        
        else if (keyword == "r"){
            
            if (!recordings.isEmpty()){
                recordings.removeData(input);
                return;
            }
            cout <<"Need to populate the collection prior to deleting!"<<"\n\n";
        }
        
        else if (keyword == "t"){
            
            if (!tracks.isEmpty()){
                tracks.removeData(input, recording_ptr);
                return;
            }
            cout <<"Need to populate the collection prior to deleting!"<<"\n\n";
        }
        
        else if (keyword == "u"){
            users.removeData(input);
        }
        
        else if (keyword == "p"){
            playlist.removeData(input, playlist_ptr);
        }
        
        //----->>DELETE TRACK FROM PLAYLIST (CHANGE)
        else if (keyword == "l"){
            playlist.removeData(input, playlist_ptr);
        }
        
    }
    //show command
    
    else if (operation == "show"){
       
        if (keyword == "t"){
            tracks.showTracksCollection(tracks_ptr);
        }
        
        else if (keyword == "s"){
            
            song_ptr = &songs;
            songs.showSongCollection(song_ptr);
        }
        
        else if (keyword == "r"){
            recording_ptr=&recordings;
            recordings.showRecordingCollection(recording_ptr);
        }
        
        else if(keyword == "u"){        //user collection
            playlist_ptr = &users;
            users.showUserCollection(playlist_ptr);
        }
        
        else if (keyword == "p"){
            playlist.showPlaylistwithUsersCollection(playlist_ptr);
            
        }
        
        else if(keyword == "c"){        //user's playlist collection
            playlistPointer = &playlist;
            users.showUsersPlaylistCollection(playlistPointer);
            //countForShowUserPlaylist++;
        }
    }
    //
    //---------*******FOLLOW --------
    //follow -u userid -p playlist_name -f userid2
    //follow -u ajones -p "favourites" -f cindy
    else if (operation == "follow"){
        string observer_userid, subject_userid, playlist_name;
        int index;
        
//        subject = (users.getUserObject(subject_userid)->getPlaylistInstance(playlist_name));
//        
//        observer = (users.getUserObject(observer_userid)->getPlaylistInstance(playlist_name));
        
        //if STOP command is inserted (NEEDS TO BE DONE...!)
        size_t parse_stop = input.find("stop");
        if (parse_stop!=string::npos){
            string stop = input.substr(parse_stop, 4);
            cout <<"Detaching--"<<endl;
            subject->detach(*observer);
            return;
        }
        
        //parsing & making sure all required parameters are provided
        if (playlistPointer->getFollowersData(input, observer_userid,  subject_userid, playlist_name)){
        
            //ensuring users exist
            if (users.doesUserExist(observer_userid, index) && users.doesUserExist(subject_userid, index)){
                                                                                                   
                 subject = (users.getUserObject(subject_userid)->getPlaylistInstance(playlist_name));
                
                 observer = (users.getUserObject(observer_userid)->getPlaylistInstance(playlist_name));
                
                cout <<"Sub address: "<<subject<<endl;
                cout <<"Obs address: "<<observer<<endl;
                
                //if playlist doesn't match with that of the subject
                if (subject == NULL || observer == NULL){
                    cout <<"ERROR! Playlists should be same in order to follow"<<endl<<endl;
                    return;
                }
                
                //subject and observer have same tracks
            //    User subject_user = *users.getUserObject(subject->getUserID());
                
              //  subject->initTracks(playlist, tracks, subject, countForSubject, true, false);
                
             //   observer->initTracks(playlist, tracks, observer, countForObserver, false, false);
                //countForSubject++;
                
                //attaching observer to the subject
                subject->attach(*observer);
                subject->notify();
                
            }
            
            else{
                cout <<"Mentioned user(s) don't exist!"<<endl<<endl;
            }
        }
    }
    
}
//--------LOGGING---------

bool genericClass::logErrorCheck(string input, size_t log_pos){
    
    if (input.length()>5){ //if there's some command after .log
        log_pos = log_pos + 5; //.log = 4
        log_command = input.substr(log_pos, input.substr(log_pos).find(" "));
        cout <<"Command: "<<log_command<<endl;
        
        
        if (log_command==start || log_command == stop){
            return true;
        }
    }
    return false;
}


void genericClass::logCommands(string input, int count){
 
    string log_file = "logFile"+ to_string(count) + ".txt";
    string log_file_input;
    
    
    if (!logErrorCheck(input,0)){
        
        printError();    //print error if its not recognizable log command
        
        return;
    }
    
    if (log_command == "start"){
        ofstream file_out(log_file, ofstream::out);
        
        if (!file_out){
            cout <<"File doesn't open!"<<endl;
            return;
        }
        
        cout <<"Logging session starts: "<<log_file<<endl<<endl;
        
        while (getline(cin, log_file_input)){
            

            if (log_file_input == ".log stop"){
                cout <<"Stopping logging! "<<endl<<endl;
                file_out.close();
                break;
            }
            
            file_out<<log_file_input<<endl;
            performOperation(log_file_input);
            cout <<endl;
        }
        count++;
        log_file="";
    }
    
    

    
    
    
}

//---------END LOGGING---------

//tracks.tracksToRespectiveAlbum(recording_ptr);
//
//count++;
void genericClass::readFile(string fileName){
    
    string input;
    
    
    
    ifstream file_input(fileName, ifstream::in);
    
    //cout <<"FILE NAME: "<<fileName<<endl;
    
    if (!file_input){
        cout <<"File couldn't open - Enter the correct file name!!"<<endl;
    }
   
    
    
    while (getline(file_input, input)){
        
       // if (!commentCheck(input)){
            
            if (fileName == "helpfile.txt" || commentCheck(input)){
                cout << input<<endl;
            }
            else{
                performOperation(input);
            }
        
       // }
      
        
    }
    
    cout <<endl;
}

bool genericClass::commentCheck(string input){
    comment_position = input.find("//");
    
    if (comment_position != string::npos){
        return true;
    }
    return false;
}


bool genericClass::errorCheck(string &input, size_t &log_pos){
    
    
    // size_t add_pos, remove_pos, show_pos;
    quit = input.find(".quit");
    help_pos = input.find(".help");
    add_pos = input.find("add");
    follow_pos = input.find("follow");
    comment_position = input.find("//");
    
    delete_pos = input.find("delete");
    show_pos = input.find("show");
    read_pos = input.find(".read");

    log_pos = input.find(".log");
    
    if (add_pos!=string::npos || show_pos!=string::npos || delete_pos!=string::npos || read_pos!=string::npos || help_pos!=string::npos || quit!=string::npos || log_pos!=string::npos || comment_position!=string::npos || follow_pos!=string::npos){
            return true;
    }
    
    return false;
    
}

string genericClass::toTitleCase(string &str){
    bool capWord = false;
    string s;
    size_t pos;
    
    for (char &c: str){
        if (isspace(c)){
            capWord = false;
        }
        
        if (capWord == false && isalpha(c)){
            c=toupper(c);
            capWord=true;
        }
        
        s.append(1,c);

    }
    
    pos = s.find("The ");
    
    if (pos==0){     //if "The" is found in the string, move it to the end
        moveToEnd(s, "The ");
        str = s;
    }
    
    return s;

}
void genericClass::moveToEnd(string &str, string value){
    size_t pos = str.find(value); // finds position in string
    //cout <<"STRING: "<<str<<endl;
    
    str.erase(pos,value.length()); //erases specified portion of the string
    str.append(" "+value); //appends erased string
}

bool genericClass::comments(string input){
 //   command = input.find("//");
    
    if (comment_position != 0){
        //printError();
        return false;
    }
    
    return true;
    
    
}

void genericClass::printError(){
    cout << "Enter correct commands or type in .help!"<<endl<<endl;
}
