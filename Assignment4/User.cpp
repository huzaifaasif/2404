//
//  User.cpp
//  Assignment2
//
//  Created by Huzaifa Asif on 2017-10-27.
//  Copyright © 2017 Huzaifa Asif. All rights reserved.
//

#include "User.hpp"

#include <iostream>

User::User(string userid,string name){
    this->userid = userid;
    this->name = name;
}

User::~User(){
    for (auto *ptr: playlistPtrCollection) {
        delete ptr;
    }
    playlistPtrCollection.clear();
}

string User::toString() const{
    return userid + " " + name + " " ;
}

string User::getUser_ID(){
    return userid;
}
//void User::setPlaylistPtr(Playlist *playlistPtr){
//    ptr_playlist = playlistPtr;
//}


void Playlist::initTracks(Playlist &aPlaylist, Tracks &tracks, Playlist *subject, int &count, bool isSubject, bool isAdd){
    int i;
    
//    if (addingTracks){
//        
//        subject->playlistToTrackCollection = aPlaylist.playlistToTrackCollection;
//        return;
//    }
    
    for (i=count; i<aPlaylist.sizeOfPlaylistWithTrackID(); i++){
        //compare user id
        //compare playlist name
        //compare track id
        for (int j=0; j<tracks.sizeOfTrackCollection(); j++){
            
            if (tracks.getTrackID(j) == aPlaylist.getPlaylistWithTrackID(i)->getTrackID()){
                if (subject->getUserID() == aPlaylist.getPlaylistWithTrackID(i)->getUserID()){
                    if (subject->getPlaylistNameForUser() == aPlaylist.getPlaylistWithTrackID(i)->getPlaylistNameForUser()){
                     
                        if (!isAdd){
                            subject->setPlaylistToTrack(aPlaylist.getPlaylistToTrackInstance(j));
                        }
                        else{
                            subject->setPlaylistToTrack(aPlaylist.getLastElement());
                            return;
                        }
                        
                        if (isSubject){
                            count++;
                        }
                    }
                }
            }
            
        }
        
   }
    if (isSubject){
        count--;
    }
    //ount=count-1;
    
   
//

//        
//        if (subject->getUserID() == aPlaylist.getPlaylistWithTrackID(i)->getUserID()){
//            if (subject->getPlaylistNameForUser() == aPlaylist.getPlaylistWithTrackID(i)->getPlaylistNameForUser()){
//                
//                
//                for (int j=0; j<tracks.sizeOfTrackCollection(); j++){
//                    
//                        //comparing track id of SUBJECT with that in "tracks_collection"
//                        if (tracks.getTrackID(j) == aPlaylist.getPlaylistWithTrackID(m)->getTrackID()){
//                            
//                            subject->setPlaylistToTrack(aPlaylist.getPlaylistToTrackInstance(j));
//                        }
//                }
//                m++;
//            }
//                    
//        }
    

        //printOnForplaylistTracks(*this);


    
    cout <<subject->user_id<<"'s "<< subject->playlistName()<<" playlist has " <<subject->sizeOfPlaylistToTrack()<<" tracks"<<endl;
    
//    for (int i=0; i<aPlaylist.sizeOfPlaylistToTrack(); i++){
//        for (int j=0; j<tracks.sizeOfTrackCollection(); j++){
//            if (aPlaylist.getPlaylistToTrackInstance(i)->getTrackID() == tracks.getTrackID(j)){
//                
//                subject->setPlaylistToTrack(aPlaylist.getPlaylistToTrackInstance(i));
//            }
//        }
//    }
   
    
}

Playlist *User::getPlaylistInstance(string playlist_name){
    for (int i=0; i<playlistPtrCollection.size(); i++){
        
        string name =playlistPtrCollection[i]->playlistName();
        if (playlist_name == playlistPtrCollection[i]->playlistName()){
            return playlistPtrCollection[i];
        }
    }
    return nullptr;
}

size_t User::sizeOfPlaylistPtrCollection(){
    return playlistPtrCollection.size();
}


void User::addPlaylistPtr(Playlist *playlist){
    
    playlistPtrCollection.push_back(playlist);
    cout <<"User "<<getUser_ID()<<" now owns playlist "<<playlist->getPlaylistNameForUser()<<endl;
    
    cout <<getUser_ID()<< " has "<<playlistPtrCollection.size()<<" playlist(s)"<<endl<<endl;
  //  cout << "User to Playlist pointer collection vector: "<<playlistPtrCollection.size()<<endl<<endl;
}

Playlist *User::getPlaylistPointer(int index){
    return playlistPtrCollection[index];
}

void User::clearPointer(int i){
    
    playlistPtrCollection.erase(playlistPtrCollection.begin()+i);
}

ostream & operator<<(ostream & out, const User & aUser){
    out << aUser.toString();
    return out;
}
