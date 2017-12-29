//
//  main.cpp
//  Assignment2
//
//  Created by Huzaifa Asif on 2017-10-17.
//  Copyright © 2017 Huzaifa Asif. All rights reserved.
//

#include <iostream>
#include "Song.hpp"
#include "Songs.hpp"
#include "genericClass.hpp"
#include <string>
#include <algorithm>

using namespace std;

int main() {
    
    string input;
    int logCount=0;
    //--> add -s "Ross" "Jim" 101
    
    //inside add method
    
    genericClass general_instance;

    string helpFile = "helpfile.txt";
    string scriptFile = "scriptfile.txt";
    string scriptFile_two="scriptFile2.txt";
    string shush = "hahaha.txt";
    size_t log_pos;
    
    for (;;){
        
        getline(cin, input);
        transform(input.begin(), input.end(), input.begin(), ::tolower);
       
        //if unrecognizable commands are entered, print error
        
        if(!genericClass::errorCheck(input, log_pos)){
            genericClass::printError();
            
        }
        
        else{
            //quit, help, read
            //bool comment = genericClass(
            if (input == ".quit"){
                return 0;
            }
            else if (input == ".help"){
                general_instance.readFile(helpFile);
            }
            else if (input == ".read"){
                general_instance.readFile(scriptFile);
            }
            else if(input == ".read2"){
                general_instance.readFile(scriptFile_two);
            }
            else if (input == ".read3"){
                general_instance.readFile(shush);
            }
            else if (log_pos!=string::npos){    //logging
                
                general_instance.logCommands(input, logCount);
                logCount++;
            }
            else if (genericClass::comments(input)){
                
            }
           
            //performing any operation
            else{
                //genericClass::performOperation(input);
                general_instance.performOperation(input);
            }
    
        }
    
    }

    
    
    
}
