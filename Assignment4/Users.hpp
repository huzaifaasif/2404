//
//  Users.hpp
//  Assignment2
//
//  Created by Huzaifa Asif on 2017-10-27.
//  Copyright © 2017 Huzaifa Asif. All rights reserved.
//

#ifndef Users_hpp
#define Users_hpp

#include <stdio.h>
#include <vector>
#include "Users.hpp"
#include "User.hpp"
#include "Playlist.hpp"
#include "Tracks.hpp"
using namespace std;
class Users{
public:
    Users();
    ~Users();
    
    void getData(string &input);
    void printOn(ostream &out) const;
    void removeData(string input);
    
    void showUserCollection(Users *users);
    //void usersToRespectivePlaylist(Playlist *playlist, int count);
    void showUsersPlaylistCollection(class Playlist *playlist);
    
    size_t sizeOfUsersCollection();
    
    //getters
    string getUser_ID(int index);
    class User *getUserInstance(int index);
    User *getUserObject(string user_name);
    void initPlaylist(Playlist *aPlaylist);
    void showPlaylistWithUsersCollection(Users *users);
    
    
    void initTest(string user_id, string playlist, int track, const Tracks *tracks);
    //--NEW
    bool doesUserExist(string userid, int &index);
    
private:
    vector<User*> users_collection;
    
    
};


ostream & operator<<(ostream & out, const Users &users);
#endif /* Users_hpp */
