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

size_t User::sizeOfPlaylistPtrCollection(){
    return playlistPtrCollection.size();
}
void User::addPlaylistPtr(Playlist *playlist){
    playlistPtrCollection.push_back(playlist);
    cout <<"User "<<getUser_ID()<<" now owns playlist "<<playlist->getPlaylistNameForUser()<<endl;
    
    cout << "User to Playlist pointer collection vector: "<<playlistPtrCollection.size()<<endl<<endl;
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
