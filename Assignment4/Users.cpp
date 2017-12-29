//
//  Users.cpp
//  Assignment2
//
//  Created by Huzaifa Asif on 2017-10-27.
//  Copyright © 2017 Huzaifa Asif. All rights reserved.
//

#include "Users.hpp"
#include "genericClass.hpp"
#include <vector>
#include <iostream>

using namespace std;


Users::Users(){
    
}

Users::~Users(){
    
    for (int i=0; i<users_collection.size(); i++){
        delete users_collection[i];
    }
    
    users_collection.clear();
}

bool Users::doesUserExist(string userid, int &index){
    for (int i=0; i<users_collection.size(); i++){
        if (userid == users_collection[i]->getUser_ID()){
            index = i;
            return true;
        }
    }
    return false;
}

void Users::getData(string &input){
    
    //add -u user_id name
    //add -u gjones "Glenn Jones"
    
    //name
    size_t start = input.find("\"");
    size_t end = input.find("\"", start + 1);
    size_t diff = end-start+1;
    
    
    //user_id
    size_t user_id_start = input.find("u")+2;
    size_t user_id_stop = input.find("\"")-2;
    size_t user_id_diff = user_id_stop - user_id_start+1;
    
    
    if (start == string::npos || end == string::npos){
        genericClass::printError();
        return;
    }
    string name = input.substr(start,diff);
    string user_id = input.substr(user_id_start,user_id_diff);
    
    User *user = new User(user_id, name);
    users_collection.push_back(user);
    
    cout <<"Adding ";
    cout<<*this<<endl;
    
}
size_t Users::sizeOfUsersCollection(){
    return users_collection.size();
}

//void Users::usersToRespectivePlaylist(Playlist *playlist, int count){
//    for(int i=0; i < users_collection.size(); i++){
//
//    }
//}



string Users::getUser_ID(int index){
    return users_collection[index]->getUser_ID();
}
//adding tracks to users
void Users::initTest(string user_id, string playlist, int track, const Tracks *tracks){
    
    for (int i=0; i<users_collection.size(); i++){
        for (int j=0; j<tracks->sizeOfTrackCollection(); j++){
            Track *track_instance = tracks->getTrackAddress(j);
            if (track_instance->getTrackID() == track){
                if (getUser_ID(i) == user_id){
                    getUserInstance(i)->getPlaylistInstance(playlist)->setPlaylistToTrack(track_instance);
                    cout <<user_id <<"'s playlist "<<playlist<<" now has track "<<track<<endl<<endl;
                }
            }
        }
    }
    
//    for (int i=0; i<tracks->sizeOfTrackCollection(); i++){
 //       Track *track_instance = tracks->getTrackAddress(i);
  //      if (track_instance->getTrackID() == track){
   //         if (getUser_ID(i) == user_id){
    //            getUserInstance(i)->getPlaylistInstance(playlist)->setPlaylistToTrack(track_instance);
//                cout <<user_id <<"'s playlist "<<playlist<<" now has track "<<track<<endl<<endl;
  //          }
      //  }
    //}
}

//by index
User *Users::getUserInstance(int index){
    return users_collection[index];
}
// by string
User *Users::getUserObject(string user_name){
    for (int i=0; i<users_collection.size(); i++){
        //if (user_name == users_collection[i]->getUser_ID()){
        if (user_name == (users_collection[i]->getUser_ID())){
            return users_collection[i];
        }
    }
    return nullptr;
}



void Users::removeData(string input){
    
    int j;
    bool notFound=true;
    size_t user_id_start = input.find("u")+2;
    size_t user_id_stop = input.find("\"")-2;
    size_t user_id_diff = user_id_stop - user_id_start+1;
    string userid = input.substr(user_id_start,user_id_diff);
    
    for (int i=0; i<users_collection.size(); i++) {
        if(userid == users_collection[i]->getUser_ID()){
            
            // Playlist *playlist_ptr = playlistPointer->get
            cout<<"User with userid "<<userid<<" owns "<<users_collection[i]->sizeOfPlaylistPtrCollection()<<" playlist(s) "<<endl;
            cout<<"Deleting "<<users_collection[i]->getUser_ID()<<endl;
            
            if (userid == users_collection[i]->getUser_ID()){
                j = i;
                
                while (users_collection[i]->sizeOfPlaylistPtrCollection()>0){
    
                    users_collection[i]->clearPointer(0);
                    
                }
            }
            notFound = false;
             cout<<"Users to playlist collection size is now "<<users_collection[i]->sizeOfPlaylistPtrCollection()<<endl;
            users_collection.erase(users_collection.begin()+i);
    
           
            break;
        }
        
    }

    if (notFound){
        cout <<"This username doesn't exist."<<endl<<endl;
    }
  }

void Users::printOn(ostream & o) const {
    cout <<"USER: "<<endl;
    for (int i=0; i<users_collection.size(); i++){
        o <<(*users_collection[i]).toString()<<endl;
    }
    
    cout <<"User collection size is "<<users_collection.size()<<endl;
    
}

void Users::showUserCollection(Users *users){
    
    cout <<"\n\nShowing USERS: "<<endl;
    if(!users_collection.empty()){
        for(int i=0; i<users_collection.size();i++){
            cout<<users->getUserInstance(i)->getUser_ID()<<endl;
        }
        
        cout <<"Users collection size is "<<users_collection.size()<<endl<<endl;
        return;
        
    }
    cout<<"User Collection is empty!"<<endl;
}

void Users::showUsersPlaylistCollection(Playlist *playlist){
    
    cout <<"Showing USER'S PLAYLISTS: "<<endl;
    if(playlist->sizeOfPlaylistCollection()!=0){
        for (int i=0; i<users_collection.size(); i++) {
            for (int j=0; j<getUserInstance(i)->sizeOfPlaylistPtrCollection(); j++) {
                cout<<"User with userID "<<getUserInstance(i)->getUser_ID()<<" owns the playlists: "<<getUserInstance(i)->getPlaylistPointer(j)->getPlaylistNameForUser()<<endl;
            }
        }
        return;
    }
    cout<<"User does not have any playlist!"<<endl;
}


ostream & operator<<(ostream & out, const Users & users){
    users.printOn(out);
    
    return out;
}
