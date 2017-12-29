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
    string getUser_ID(int index);
    
    class User *getUserInstance(int index);
    
private:
    vector<User*> users_collection;
    
    
};


ostream & operator<<(ostream & out, const Users &users);
#endif /* Users_hpp */
