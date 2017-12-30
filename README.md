# Music App - Command line interface 
- Allows users to create playlist, add and remove songs, recordings, tracks.
- Specific relationship was establised between recordings, songs, tracks, as shown in the UML diagram.
- The commands should allow establishing all the relationships that exist in the data model. For example: associating songs with recordings, or playlists with users, or songs with user playlists.
- Observer design pattern was used to meet user's requirements and improve its scalability.

![UML Diagram](https://github.com/huzaifaasif/2404/blob/master/UML.png)
## Compiling Instructions using terminal
1. `g++ -g -Wall *.cpp`
2. `./a.out`

To execute the provided script file (`scriptfile.txt`), type `.read`

## Commands
This app allows users to `add`, `delete` and `show` the mentioned features in the table below. In addition to those, the program also supports logging of the commands using `.log` command.

|Features|Commands|
|---|---|
|User|`-u` |
|Recording|`-r`|
|Track|`-t`|
|User's Playlist|`-p`|

For example, adding a user follows the syntax: `add -u user_id "name"`

To see the rest of the available commands supported by the program, type `.help`


