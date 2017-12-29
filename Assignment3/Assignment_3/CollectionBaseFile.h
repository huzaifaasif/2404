/* * * * * * * * * * * * * * * * * * * * * * * * * * */
/*                                                   */
/*  Program:  MyTunes Music Player                   */
/*  Author:   Huzaifa Asif - 100921147, Ali Selcuk - 100954050                             

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

#ifndef CollectionBaseFile_h
#define CollectionBaseFile_h
#include <string>

// abstract base class -> from which Song, Recording, Track, Playlist classes derive.

class ObjectCollection{
public:
    int getID(){
        return id;
    }
    
    string getUserID(){
        return userID;
    }
    
  
    virtual string toString() const = 0;
    
protected:
    int id;
    string userID;
    
};

#endif /* CollectionBaseFile_h */
