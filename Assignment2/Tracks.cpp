//
//  Tracks.cpp
//  Assignment2
//
//  Created by Huzaifa Asif on 2017-10-24.
//  Copyright © 2017 Huzaifa Asif. All rights reserved.
//

#include "Tracks.hpp"
#include "Recording.hpp"
#include <string>
#include <iostream>
#include <sstream>
#include "genericClass.hpp"
#include "Track.hpp"

using namespace std;

Tracks::Tracks(){
    
}

void Tracks::setTrackCollection(Recording *recording){
    //tracks_collection.push_back(recording);
}

Tracks::~Tracks(){
//    for (int i=0; i<tracks_collection.size();i++){
//        delete[] tracks_collection[i];
//    }

    for (auto *ptr: tracks_collection){
        delete ptr;
    }
    
    tracks_collection.clear();
}

void Tracks::getData(string &input){
    
    
    string values;
    size_t pos;
    vector<int> vect;
    int i, track_id, albumID, songID, track_number;
    
    pos = input.find("-t")+2;
    values = input.substr(pos);
    
    stringstream ss(values);
    
    while (ss >> i)
    {
        vect.push_back(i);
        
        if (ss.peek() == ' '){
            
            ss.ignore();
        }
        
    }
    
    if (vect.size()!=4){
        genericClass::printError();
        return;
    }
   
    track_id = vect.at(0);
    albumID = vect.at(1);
    songID = vect.at(2);
    track_number = vect.at(3);
    
    Track *track = new Track(track_id, albumID, songID, track_number);
    tracks_collection.push_back(track);
    cout <<"Adding ";
    cout <<*this<<endl;

}

//getter
Track *Tracks::getTrackAddress(int index){
    return tracks_collection[index];  //dereference the pointer=track instance
}

int Tracks::getAlbumID(int index){
    return tracks_collection[index]->getAlbumID();
}


size_t Tracks::sizeOfTrackCollection(){
    return tracks_collection.size();
}

int Tracks::getSongID(int index){
    return tracks_collection[index]->getSongID();
}



//void Tracks::tracksToRespectiveAlbum(Recordings *recordings){
//    
//    if (tracks_collection.size()>0){
//    
//        for (int i=0; i<tracks_collection.size(); i++){
//            for (int j=0; j<tracks_collection.size(); j++){
//                
//                if ( recordings->getRecordingAlbumID(i) == tracks_collection[j]->getAlbumID() ){
//                    
//                    
//                    getTrackAddress(j)->setRecordingPtr(recordings->getRecordingInstance(i));
//                    
//                    
//                    
//                    cout <<getTrackAddress(j)->getRecordingPointer()<<endl;
//                    
//                }
//            }
//        }
//    }
//    
//}

void Tracks::removeData(string input, Recordings *recording_ptr){
    int id;
    bool ptrDeleted=false;
    
    genericClass::parseIntFromString(input, id);
    
    for (int i=0; i<recording_ptr->getRecordingCollectionSize(); i++){
        
        if (ptrDeleted){
            break;
        }
        
        //deleting by SONG ID
        
        size_t recordingToTrackCollectionSize = recording_ptr->getRecordingInstance(i)->getrecordingToTrackCollectionSize();
        
        for (int j=0; j<recordingToTrackCollectionSize; j++){
            
            class Track *trackPtr = recording_ptr->getRecordingInstance(i)->getTrackPointer(j);
            
            if (id == trackPtr->getSongID()){
                
                Track trck = *tracks_collection[i];
                
                cout <<"Recording to Tracks collection size is "<<recording_ptr->getRecordingInstance(i)->getrecordingToTrackCollectionSize()<<endl;
                
                cout <<"Deleting Track ";
                
                cout <<trck;
            
                tracks_collection.erase(tracks_collection.begin()+i); //deleting the track object - pointer may or may not be valid
                
                
                recording_ptr->getRecordingInstance(i)->clearPointer(j);    //clearing R1->T1 to be safe (as an example)
                
                cout <<"Recording to Tracks collection size now becomes "<<recording_ptr->getRecordingInstance(i)->getrecordingToTrackCollectionSize()<<endl<<endl;
                
                ptrDeleted=true;
                break;
            }
            
        }
    }
    
//    for (int i=0; i<tracks_collection.size(); i++){
//        
//        if (id == tracks_collection[i]->getSongID()){
//            
//            cout <<"Deleting Track of ID "<<tracks_collection[i]->getSongID()<<endl;
//            tracks_collection.erase(tracks_collection.begin()+i);
//            recording_ptr[i].getRecordingInstance(i)->clearPointer(i);
//        
//            break;
//            
//        }
//    }
}

Track Tracks::getTrackInstance(int index){
    return *tracks_collection[index];
}

void Tracks::tracksToRespectiveSongs(Songs *songs, int count){
    
    
    for (int i=count; i<this->sizeOfTrackCollection(); i++){
        
        if (tracks_collection[i]->getSongID() == songs->getSongInstance(i)->getID()){
            
           // tracks_collection[i]->setSongPtr(songs->getSongInstance(i));
            tracks_collection[i]->setTrackToSongCollection(songs->getSongInstance(i));
            
            cout <<"Song "<<songs->getSongInstance(i)->getTitle()<<" is added to Track with track ID "<<tracks_collection[i]->getTrackID()<<endl<<endl;
           // break;
            
        }
    }
}

bool Tracks::isEmpty() const{
    
    return tracks_collection.empty();
}
size_t Tracks::getTrackCollectionSize(){
    return tracks_collection.size();
}

int Tracks::getTrackID(int index){
    return tracks_collection[index]->getTrackID();
}

void Tracks::showTracksCollection(Tracks *tracks) const{
    
    if (!tracks_collection.empty()){
        
        cout <<"Showing ";
        cout <<*this;
        
        return;
    }
    cout <<"Track collection is empty!"<<endl<<endl;
}

void Tracks::printOn(ostream &o)const{
    cout<<"TRACK: "<<endl;
    
    for (int i=0; i<tracks_collection.size(); i++){
        //o <<(*tracks_collection[i]).toString()<<endl;
        o<<tracks_collection[i]->toString()<<endl;
        
    }
    cout <<"Track collection size is "<<tracks_collection.size()<<endl;
}


ostream & operator<<(ostream & out, const Tracks & tracks){
    tracks.printOn(out);
    
    return out;
}

ostream & operator<<(ostream & out, const Track & track){
    out <<track.toString()<<endl<<endl;
    
    return out;
}

