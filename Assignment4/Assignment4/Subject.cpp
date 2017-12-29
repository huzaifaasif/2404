//
//  Subject.cpp
//  Assignment4
//
//  Created by Huzaifa Asif on 2017-12-01.
//  Copyright © 2017 Huzaifa Asif. All rights reserved.
//

#include "Subject.hpp"
#include "Observer.hpp"
#include <iostream>
#include "Playlist.hpp"
using namespace std;


void Subject::attach(Observer &obs){
   
    
    //casting Observer/Subject to Playlist
    Playlist &observer = (Playlist&)obs;
    Playlist &subject = (Playlist&)*this;
    
    observers.push_back(&observer);
    cout <<observer.userID()<<" now follows "<<observer.playlistName()<<" playlist of "<<subject.userID()<<endl;
  
    cout <<subject.userID()<<" now has "<<observers.size()<<" follower(s)"<<endl<<endl;
    //observers.add(obs);
    
}

size_t Subject::getObserverSize(){
    return observers.size();
}

void Subject::detach(Observer &obs){
    
    Playlist &observer = (Playlist&)obs;
    Playlist &subject = (Playlist&)*this;

    for(int i=0; i<observers.size(); i++){
        if (observers[i]->playlistName() == observer.playlistName()){
            observers.erase(observers.begin()+i);
        }
    }
    cout <<observer.userID()<<" unfollowed playlist "<<observer.playlistName()<< " of "<<subject.userID()<<endl;
}

void Subject::notify(){
    Playlist &ptr = (Playlist&)*this;   //subject
   // size_t lastInstance;
    
    for (int i=0; i<observers.size(); i++){
        //lastInstance = ptr.sizeOfPlaylistToTrack()-1;
        //observers[i]->update(ptr.getPlaylistToTrackInstance(lastInstance));
        observers[i]->update(ptr);
    }
}
