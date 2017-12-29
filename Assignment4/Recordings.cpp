//
//  Recordings.cpp
//  Assignment2
//
//  Created by Huzaifa Asif on 2017-10-24.
//  Copyright © 2017 Huzaifa Asif. All rights reserved.
//

#include "Recordings.hpp"
#include "Recording.hpp"
#include "genericClass.hpp"
#include <string>
#include <iostream>
using namespace std;


Recordings::Recordings(){

}

Recordings::~Recordings(){
    
//    for (int i=0; i<recordings_collection.size(); i++){
//        delete[] recordings_collection[i];
//    }
    
    for (auto *ptr: recordings_collection){
        delete ptr;
    }
    
    recordings_collection.clear();
}

void Recordings::getData(string &input, Tracks &tracks){
    int albumID=-1;
    
    size_t title_start_pos = input.find("\"");
    size_t title_end_pos = input.find("\"", title_start_pos + 1);
    size_t diff_title = title_end_pos-title_start_pos+1;
    
    
    //artist
    size_t artist_start_pos = input.find("\"", title_end_pos+1);
    size_t artist_end_pos = input.find("\"", artist_start_pos + 1);
    size_t diff_artist = artist_end_pos-artist_start_pos+1;
    
    
    //producer
    size_t producer_start_pos = input.find("\"", artist_end_pos+1);
    size_t producer_end_pos = input.find("\"", producer_start_pos + 1);
    size_t diff_producer = producer_end_pos-producer_start_pos+1;
    
    //year
    string year_in_string = input.substr(producer_end_pos+2);
    int year;
    //------------
 
    //error detection
    
    if (title_start_pos==string::npos ||title_end_pos==string::npos || artist_start_pos==string::npos || artist_end_pos==string::npos || producer_start_pos==string::npos || producer_end_pos==string::npos ){
        
        genericClass::printError();
        return;
    }
    
    genericClass::parseIntFromString(input, albumID);
    genericClass::parseIntFromString(year_in_string, year);
    
    if (albumID == -1 || year==-1){
        genericClass::printError();
        return;
    }
    
    string title = input.substr(title_start_pos, diff_title);
    string artist = input.substr(artist_start_pos, diff_artist);
    string producer = input.substr(producer_start_pos, diff_producer);
    
    genericClass::toTitleCase(title);
    genericClass::toTitleCase(artist);
    genericClass::toTitleCase(producer);
    
    Recording *recording = new Recording(albumID, title, artist, producer, year);
    
    recordings_collection.push_back(recording);
    
    
    
    //-->tracks.setTrackCollection(recording); //populating track
    cout <<"Adding ";
    cout <<*this<<endl;
   // cout <<tracks<<endl;
}

//void Recordings::populatingTrack(Tracks &tracks, Recording *recording){
//    tracks.setTrackCollection(recording);
//}

size_t Recordings::getRecordingCollectionSize(){
    return recordings_collection.size();
}

void Recordings::recordingsToRespectiveTrack(Tracks *tracks, int count){
    
    for (int i=0; i<recordings_collection.size(); i++){
        for (int j=count; j<tracks->sizeOfTrackCollection(); j++){
            
            if ( recordings_collection[i]->getAlbumID() == tracks->getAlbumID(j) ){
                
                getRecordingInstance(i)->addTrackPtr(tracks->getTrackAddress(j));
                
                cout <<"Track of song ID "<<tracks->getTrackAddress(j)->getSongID()<< " is added to Recording's album "<<recordings_collection[i]->getTitle()<<endl<<endl;
            
            }
        }
    
    }
    
//    for (int i=0; i<getRecordingCollectionSize(); i++){
//        
//        if (i<=getRecordingInstance(i)->getrecordingToTrackCollectionSize()){
//            cout <<"Album ID: "<<getRecordingInstance(i)->getAlbumID()<<endl;
//            getRecordingInstance(i)->printrecordingToTrackCollection(tracks);
//        }
//    }
//    for (int i=0; i<recordings_collection.size(); i++){
//        cout <<"ID: "<<tracks->getAlbumID(i)<<endl;
//        getRecordingInstance(i)->printrecordingToTrackCollection(tracks);
//    }
    
  
//    int j=0;
//
//    for (int i=0; i<recordings_collection.size(); i++){
//        for (int j=count; j<tracks->sizeOfTrackCollection(); j++)
//        while(j<tracks->sizeOfTrackCollection()){
//            
//            if (recordings_collection[i]->getAlbumID() != tracks->getAlbumID(j)){
//                break;
//            }
//            
//            
//            
//            j++;
//        }
//    }
//    for (int i=0; i<tracks->sizeOfTrackCollection(); i++){
//        for (int j=i; j<tracks->sizeOfTrackCollection(); j++){
//            cout <<"Recording->Track: "<<getRecordingInstance(i)->getTrackPointer(j)<<endl;
//        }
//    }
    
}

int Recordings::getRecordingAlbumID(int index){
    return recordings_collection[index]->getAlbumID();
}

Recording *Recordings::getRecordingInstance(int index){
    return recordings_collection[index];
}


void Recordings::removeData(string input){
    int id;
    genericClass::parseIntFromString(input, id);
    
    for (int i=0; i<recordings_collection.size(); i++){
    
        if (id == recordings_collection[i]->getAlbumID()){
            
            cout <<"Deleting "<<recordings_collection[i]->getTitle()<<endl;
            
            recordings_collection.erase(recordings_collection.begin()+i);
            
            break;
        }
    }
}

bool Recordings::isEmpty() const{
    return recordings_collection.empty();
}

void Recordings::printOn(ostream & o) const {
    cout <<"RECORDING: "<<endl;
    for (int i=0; i<recordings_collection.size(); i++){
        o <<(*recordings_collection[i]).toString()<<endl;
    }
    
    cout <<"Recording collection size is "<<recordings_collection.size()<<endl<<endl;
    
}

void Recordings::showRecordingCollection(Recordings *recordings){
    
    if (!recordings_collection.empty()){
        
        cout <<"Showing ";
        cout <<*this;
        
        return;
    }
    cout<<"Recording collection is empty!"<<endl<<endl;
}

ostream & operator<<(ostream & out, const Recordings & recordings){
    recordings.printOn(out);
    
    return out;
}

