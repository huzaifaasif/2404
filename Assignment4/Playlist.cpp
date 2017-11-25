//
//  Playlist.cpp
//  Assignment2
//
//  Created by Ali Emre Selcuk on 2017-10-27.
//  Copyright © 2017 Huzaifa Asif. All rights reserved.
//

#include "Playlist.hpp"
#include "genericClass.hpp"
#include <string>
#include <sstream>
#include <iostream>
#include "Users.hpp"

using namespace std;

Playlist::Playlist(){}

Playlist::~Playlist(){
    for (auto *ptr: playlist_collection) {
        delete ptr;
    }
    for (auto *ptr: playlist_collection_with_trackID) {
        delete ptr;
    }
    for (auto *ptr: playlistToTrackCollection) {
        delete ptr;
    }
    playlist_collection.clear();
    playlist_collection_with_trackID.clear();
    playlistToTrackCollection.clear();
    
}

//playlist constructor
Playlist::Playlist(string &user_id, string &playlist_name){
    this->user_id = user_id;
    this->playlist_name = playlist_name;
}

//playlist track constructor
Playlist::Playlist(string &user_id, string &playlist_name, int trackID){
    this->user_id = user_id;
    this->playlist_name = playlist_name;
    this->trackID = trackID;
}

string Playlist::getKeyword(string input){
    
    size_t hyphen = input.find("-");
    string keyword = input.substr(hyphen+1, 1);
    return keyword;
    
}

size_t Playlist::sizeOfPlaylistCollection(){
    return playlist_collection.size();
}



void Playlist::removeData(string input, Users *userToPlaylistPointer){
    
    //----NEW CODE----
    string keyword = getKeyword(input);
    if(keyword=="p"){
        size_t user_id_first = input.find("-p")+3;
        size_t user_id_stop = input.find("\"")-2;
        size_t user_id_diff = user_id_stop - user_id_first+1;
        string user_id = input.substr(user_id_first, user_id_diff);
        
        bool ptrDeleted = false, notFound=true;
        
        for(int i=0; i<userToPlaylistPointer->getUserInstance(i)->sizeOfPlaylistPtrCollection(); i++){
            
            if (ptrDeleted){
                break;
            }
            
            for (int j=0; j<playlist_collection.size(); j++) {
                
                if(user_id == getUserID(i)){
                    cout <<"User to Playlist collection size is "<<userToPlaylistPointer->getUserInstance(i)->sizeOfPlaylistPtrCollection()<<endl;
                    
                    cout <<"Deleting Playlist "<<userToPlaylistPointer->getUserInstance(i)->getPlaylistPointer(j)->getPlaylistNameForUser()<<endl;
                    
                    userToPlaylistPointer->getUserInstance(i)->clearPointer(0);
                    
                    
                    playlist_collection.erase(playlist_collection.begin()+i);
                    
                    cout <<"User to playlist collection size is "<<userToPlaylistPointer->getUserInstance(i)->sizeOfPlaylistPtrCollection()<<endl<<endl;
                    
                    notFound = false;
                }
            }
            if (notFound){
                cout <<user_id<<" doesn't own any playlist. "<<endl;
                break;
            }
            
            if (userToPlaylistPointer->getUserInstance(i)->sizeOfPlaylistPtrCollection()==0){
                ptrDeleted = true;
                break;
            }
            
        }
    }
    
        if(keyword == "l"){
            int id;
            bool notFound=true;
            
            genericClass::parseIntFromString(input,id);
            
            for(int i=0; i<playlist_collection_with_trackID.size();i++){
                if (id == getTrackID(i)) {
                    
                    for (int j = 0; j<playlistToTrackCollection.size(); j++) {
                        
                        playlistToTrackCollection.erase(playlistToTrackCollection.begin()+j);
                    }
                    cout <<"Playlist to track size is "<<playlist_collection_with_trackID.size()<<endl<<endl;
                    playlist_collection_with_trackID.erase(playlist_collection_with_trackID.begin()+i);
                    notFound=false;
                    break;
                }
            }
            
            if (notFound){
                cout <<"Enter the correct track ID!"<<endl<<endl;
            }
        }

}

void Playlist::getData(string &input){
    
    //user id
    size_t user_id_first = input.find("-p")+3;
    size_t user_id_stop = input.find("\"")-2;
    size_t user_id_for_playlist_track= input.find("-l")+3;
    
    size_t user_id_diff = user_id_stop - user_id_first+1;
    size_t user_id_diff_playlist_track = user_id_stop - user_id_for_playlist_track+1;
    
    //playlist
    size_t start = input.find("\"");
    size_t end = input.find("\"", start + 1);
    
    size_t diff = end-start+1;
    
    
    //trackID
    string trackID_in_string = input.substr(end+1);
    int trackID=-1;
    
    
    //error check
    if (start==string::npos || end == string::npos || user_id_first == string::npos || user_id_stop == string::npos){
        genericClass::printError();
        return;
    }
    
    genericClass::parseIntFromString(trackID_in_string, trackID);
    
    //strings
    
    playlist_name = input.substr(start, diff);
    
    
    if(trackID==-1){
        user_id = input.substr(user_id_first, user_id_diff);
        Playlist *playlist = new Playlist(user_id, playlist_name);
        playlist_collection.push_back(playlist);
        
        cout <<"Adding ";
        printOn(*this);
      
        
    }else{
        user_id = input.substr(user_id_for_playlist_track,user_id_diff_playlist_track);
        Playlist *playlist = new Playlist(user_id,playlist_name, trackID);
        playlist_collection_with_trackID.push_back(playlist);
        
        cout <<"Adding ";
        printOnForplaylistTracks(*this);
    }
//    //cout<<playlist<<endl;
//    string keyword = getKeyword(input);
    
    
    
    //cout <<*this<<endl;
 
}

string Playlist::getUserID(int index){
    return playlist_collection[index]->user_id;
}

string Playlist::getPlaylistName(int index){
    return playlist_collection[index]->playlist_name;
}

string Playlist::getPlaylistNameForUser(){
    return playlist_name;
}

int Playlist::getTrackID(int index){
    return playlist_collection_with_trackID[index]->trackID;
}

void Playlist::addTrackPointer(Track *track){
    playlistToTrackCollection.push_back(track);
    
    cout <<"Playlist "<<getPlaylistNameForUser()<<" now has a track with track ID "<<track->getTrackID()<<endl;
    cout << "playlist to track pointer collection vector: "<<playlistToTrackCollection.size()<<endl<<endl;
}

void Playlist::usersToRespectivePlaylist(Users *users, int count){
    
    for(int i=0; i < users->sizeOfUsersCollection();i++){
        for (int j=count; j<playlist_collection.size(); j++) {
            if(this->getUserID(j) == users->getUser_ID(i)){
                users->getUserInstance(i)->addPlaylistPtr(playlist_collection[j]);
                //cout<<"User->Playlist: "<< users->getUserInstance(i)->getPlaylistPointer(j)<<endl;
                break;
            }
        }
        
    }
}

void Playlist::playlistToRespectiveTrack(class Tracks *tracks, int countForPlaylistToTrack){
    
    for(int i=0; i<tracks->sizeOfTrackCollection();i++){
        for(int j=countForPlaylistToTrack; j<playlist_collection_with_trackID.size(); j++){
            
            if(this->getTrackID(j) == tracks->getTrackID(i)){
                
                this->addTrackPointer(tracks->getTrackAddress(i));
                
            }
        }
    }
}





string Playlist::toString() const{
    return user_id +" "+ playlist_name;
}

string Playlist::toStringForPlaylistTrack() const{
    return user_id +" "+ playlist_name + " "+ to_string(trackID);
}


void Playlist::showPlaylistCollection(Playlist *playlist){
    if(!playlist_collection.empty()){
        for(int i=0; i<playlist_collection.size();i++){
            cout<<"User name: "<<getUserID(i)<<"Playlist name: "<<getPlaylistName(i)<<endl;
        }
        return;
        
    }
    cout<<"Playlist collection is empty!"<<endl;
}

void Playlist::showPlaylistTrackCollection(Playlist *playlist){
    if(!playlist_collection_with_trackID.empty()){
        for(int i=0; i<playlist_collection_with_trackID.size();i++){
            cout<<"Playlist Track with trackID: "<<getTrackID(i)<<endl;
        }
        return;
    }
    
}

void Playlist::showPlaylistwithUsersCollection(Users *users){
    if(!playlist_collection.empty()){
        for(int i=0; i<playlist_collection.size();i++){
            cout<<"User name "<<users->getUserInstance(i)->getUser_ID()<<" owns the playlist named: "<<getPlaylistName(i)<<endl;
        }
        
        cout <<"Playlist collection size is "<<playlist_collection.size()<<endl<<endl;
        return;
        
    }
}


//void Playlist::printOnForPlaylist(ostream &o)const{
//    cout<<"Playlist: "<<endl;
//
//        for (int i=0; i<tracks_collection.size(); i++){
//            //o <<(*tracks_collection[i]).toString()<<endl;
//            o<<tracks_collection[i]->toString()<<endl;
//        }
//    }
//}


void Playlist::printOnForplaylistTracks(Playlist &aPlaylist) const {
    
    cout <<"PLAYLIST TRACK: "<<endl;
    
    for (int i=0; i<playlist_collection_with_trackID.size(); i++){
        cout << playlist_collection_with_trackID[i]->toStringForPlaylistTrack()<<endl;
    }
    
    cout <<" Playlist Track collection is "<<playlist_collection_with_trackID.size()<<endl<<endl;

}

void Playlist::printOn(Playlist &aPlaylist) const{
    cout <<"PLAYLIST: "<<endl;
    
    for (int i=0; i<playlist_collection.size(); i++){
        cout << playlist_collection[i]->toString()<<endl;
    }
    
    cout <<"Playlist collection size is "<<playlist_collection.size()<<endl<<endl;

}
ostream & operator<<(ostream & out, const Playlist & aPlaylist){

   // if (aPlaylist.)
    //aPlaylist.printOn(out);


    return out;
}
