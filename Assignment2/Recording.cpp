//
//  Recording.cpp
//  Assignment2
//
//  Created by Huzaifa Asif on 2017-10-24.
//  Copyright © 2017 Huzaifa Asif. All rights reserved.
//

#include "Recording.hpp"
#include "Track.hpp"
#include <iostream>

Recording::Recording(int albumID, string title, string artist, string producer, int year){
    this->title=title;
    this->artist=artist;
    this->producer=producer;
    this->year=year;
    this->albumID=albumID;
}

Recording::~Recording(){
    
    for (auto *ptr: recordingToTrackCollection){
        delete ptr;
    }
    
    recordingToTrackCollection.clear();

}

void Recording::printrecordingToTrackCollection(Tracks *tracks){
    
    for (int i=0; i<recordingToTrackCollection.size(); i++){
        
        cout <<"Track address: "<<recordingToTrackCollection[i]<<endl;
    }
    cout <<endl;
}

//getter
int Recording::getAlbumID(){
    return albumID;
}

string Recording::getTitle(){
    return title;
}

void Recording::clearPointer(int index){
    recordingToTrackCollection.erase(recordingToTrackCollection.begin()+index);
}

void Recording::addTrackPtr(Track *track){
    //ptr_track = track;
    
    recordingToTrackCollection.push_back(track);
    cout << "Track pointer collection vector: "<<recordingToTrackCollection.size()<<endl;
}

Track *Recording::getTrackPointer(int index){
    return recordingToTrackCollection[index];
}

size_t Recording::getrecordingToTrackCollectionSize(){
    return recordingToTrackCollection.size();
}

string Recording::toString() const{
    return to_string(albumID) + " " + title + " " + artist + " " + producer + " " +to_string(year);
}
