/* * * * * * * * * * * * * * * * * * * * * * * * * * */
/*                                                   */
/*  Program:  MyTunes Music Player                   */
/*  Author:   Huzaifa Asif - 100921147, Ali Selcuk - 100954050                             */

/*  All rights reserved.  Distribution and           */
/*  reposting, in part or in whole, requires         */
/*  written consent of the author.                   */
/*                                                   */
/*  COMP 2404 students may reuse this content for    */
/*  their course assignments without seeking consent */
/* * * * * * * * * * * * * * * * * * * * * * * * * * */

/* * * * * * * * * * * * * * * * * * * * * * * * * * * */
/*                                                     */
/*  DISCLAIMER                                         */
/*  This is "Early Course" code and does not use       */
/*  many c++ features that might be appropriate        */
/*  For example:                                       */
/*  -No inheritance is used yet                        */
/*  -Many items are passed by value resulting in copies*/
/*  -Many items are not const protected that should be */
/*  -There is no dynamic memory allocation yet         */
/*  -No base-member initialization yet                 */
/*                                                     */
/* * * * * * * * * * * * * * * * * * * * * * * * * * * */

//templates for Collections (songs, recordings, etc..)
#ifndef mytunes_collection_h
#define mytunes_collection_h
#include <cstring>
#include <string>
#include <typeinfo>
#include <vector>
#include <iostream>
using namespace std;

template <typename T>
class MyTunesCollection{
public:
    MyTunesCollection(){}
    
    ~MyTunesCollection(){
        for(int i=0; i<collection.size(); i++){
            delete collection[i]; //delete Recordings in this container
        }
    }
    
    vector<T*>getCollection(){
        return collection;
    }
    
    void add(T &aT){
        collection.push_back(&aT);
    }
    
    size_t getCollectionSize(){
        return collection.size();
    }
    
    
    void remove(T &aT){
        typename vector<T*>::iterator index = findPosition(aT);
        
        if(index != collection.end()) {
            T * t = *index;
            collection.erase(index);
            delete t;
        }
    }
    
    //generic search
    T* genericSearch(string anID){
        
        //if the parameter contains integer in a string
        if (isdigit(anID[0])){
            int id = stoi(anID);
            
            for (typename vector<T*>::iterator itr = collection.begin() ; itr != collection.end(); ++itr){
                if((*itr)->getID() == id){
                    return *itr;
                }
            }
        }
        //if the parameter contains userID string
        for (typename vector<T*>::iterator itr = collection.begin() ; itr != collection.end(); ++itr){
            if(((*itr)->getUserID()).compare(anID) == 0){
                    return *itr;
            }
        }
        
        return NULL;
    }
    
    
    typename vector<T*>::iterator findPosition(T &aT){
        for (typename vector<T*>::iterator it = collection.begin() ; it != collection.end(); ++it){
            if(*it == &aT){
                
                return it;
            }
        }
        return collection.end();
    
    }
    
    void showOn(UI & view) {
        
        cout <<"Showing ";
        view.printOutput(view.getClassName());
        cout <<*this<<endl;
    }
    
    //are we even using these functions??
    void showOn(UI & view, const string & memberID) {
        view.printOutput("User:");
        T * t = genericSearch(memberID);
        if(t != NULL)
            t->toString();
            view.printOutput(t->toString());
        
    }
    
//    void showOn(UI & view, int memberID)  {
//        view.printOutput("Song:");
//        T * t = genericSearch(memberID,"");
//        if( t != NULL)
//            view.printOutput(t->toString());
//    }
    
    
    void printOn(ostream &o) {
        for (int i=0; i<collection.size(); i++){
            string uh = collection[i]->toString();
            o << collection[i]->toString()<<endl;
        }
    }
    
private:
    vector<T*> collection;
};


template <typename T>
ostream &operator<<(ostream &o, MyTunesCollection<T> &t){
    t.printOn(o);
    return o;
}



#endif /* mytunes_collection_h */
