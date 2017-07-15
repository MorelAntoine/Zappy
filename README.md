# Zappy

This project is a network game. The goal was to progress and learn more in network and ai.

Several teams confront on a tiles map containing resources.

The winning team is the one with 6 players who reached maximum elevation.

(screenshots available in screenshots/ folder)

    Dev period: 11 june 2017 - 02 july 2017

Description
===========

> Resources

    * Food
    * Stones
        * Linemate
        * Deraumere
        * Sibur
        * Mendiane
        * Phiras
        * Thystame
        
    The server generate randomly these resources.

> Rules

    * In the beginning, a team is made up of n players.
      Each player is driven by a client.
      The clients cannot communicate or exchange data outside of the game (no matter what it
      is).

    * In the beginning, the client has 10 life units, which means he can survive for 1260 time
      units, or (1260 / f) seconds.

    * If a player exits by the right of the board, he will come back through the left.
    
    * The food that the clients collect is the only resource they need to survive.
      One unit of food allows them to live for 126 units of time.
      
> Elevation

    Everyone’s goal is to rise up in the hierarchy.
    This ritual must be done according to a particular rite.
    They must gather the following on the same unit of terrain:
    
        * a combination of stones
    
        * a certain number of players with the same level
    
    The elevation begins as soon as a player initiates the incantation.
    It is not necessary for the players to be on the same team; only their level is important.
    Every player in a group doing an incantation attain the higher level.

>

    elevation   nb of players   linemate    deraumere   sibur   mendiane    phiras  thystame

    1->2        1               1           0           0       0           0       0
    2->3        2               1           1           1       0           0       0
    3->4        2               2           0           1       0           2       0
    4->5        4               1           1           2       0           1       0
    5->6        4               1           2           1       3           0       0
    6->7        6               1           2           3       0           1       0
    7->8        6               2           2           2       2           2       1

> Commands

    action                  command         time limit          response
    
    move up one tile        Forward         7/f                 ok
    turn 90° right          Right           7/f                 ok
    turn 90° left           Left            7/f                 ok
    look around             Look            7/f                 [tile1, tile2,. . . ]
    inventory               Inventory       1/f                 [linemate n, sibur n,. . . ]
    broadcast text          Broadcast text  7/f                 ok
    number of team          Connect_nbr     -                   value
    unused slots
    fork a player           Fork            42/f                ok
    eject players           Eject           7/f                 ok/ko
    from this tile
    death of a player       -               -                   dead
    take object             Take object     7/f                 ok/ko
    set object down         Set object      7/f                 ok/ko
    start incantation       Incantation     300/f               Elevation underway
                                                                Current level: k
                                                                /ko

> Look

    For various reasons, the players’ field of vision is limited.
    With each elevation, the vision increases by one unit in front, and one on each side of the
    new line.
    At the first level, the unit is defined as 1.
    In order for a player to recognize his team, the client sends the look command.
    The server will respond with the character string, as follows:
    
        look
        [player, object-on-tile1, ..., object-on-tileP,...]

>

    Here’s an example for a level-1 player having two objects in tile 1:
    
        look
        [player, player deraumere,,]

> Inventory

    This command allows you to see what object the client has and how much time it has left to live.
    The server will send a line similar to the following one:
    
        [food 24, sibur 3, phiras 5, ...,deraumere 0]\n

> Broadcast

    Sound is a wave that spreads out linearly by broadcasting.
    All the players can hear the broadcasts without knowing who is playing them.
    They can only perceive the direction the sound is coming from and its subsequent message.

    The direction is indicated by the number of the tile affected by the sound,
    before arriving in the player’s tile.
    This numbering is done through attributing 1 to the tile that is located in
    front of the player, then through deducting the tiles that trigonomically encircle the player.
    In the event that the broadcast is emitted from the same player receptor
    tile, he will receive the message coming from the 0 tile.

>

    To emit a message, the client must send the following command to the server:
    
        Broadcast text\n
    
    The server will then send the following line to all of its clients:
    
        message K, text\n
    
    where K is the tile where the sound is coming from.

> Client / Server communication

    The dialogue between the client and the server is carried out via tcp sockets.
    The port that is used must be indicated in paramater.
    The client sends its requests, without waiting for them to be done.
    The server sends back a message confirming the correct execution of the requests.
    
>

    The client’s connection to the server happens as follows:
    1. the client opens a socket on the server’s port,
    2. the server and the client communicate the following way:

        <--WELCOME\n
        -->TEAM-NAME\n
        <--CLIENT-NUM\n
        <-- X Y\n

    X and Y indicate the world’s dimensions.
    CLIENT-NUM indicates the number of clients that can still be accepted by the server for the
    TEAM-NAME team.
    If this number is greater than or equal to 1, a new client can connect.

Server
======

> Description

Server made in C (TCP protocol)

> Usage

    ./zappy_server -p port -x width -y height -n name1 name2 ... -c nbClients -f freq
            
        - port is the port number
        - width is the width of the world
        - height is the height of the world
        - nameX is the name of the team X
        - nbClients is the number of authorized clients per item
        - freq is the time for the limit execution of actions

Artificial intelligence
=======================

> Description

Finite-state machine in C++11 with C socket (TCP protocol)

(see machine.png for more details)

> Usage

    ./zappy_ai -p port -n name -h machine
    
        - port is the port number
        - name is the name of the team
        - machine is the name of the machine; localhost by default

Graphical client
================

> Description

Graphical client made in C++17 with LibQt.

> Requirements - LibQt

    sudo apt-get install qt-sdk
        
> Usage

    ./clnt -p port -h machine
    
        - port is the port number
        - machine is the name of the machine

Made By
=======

> Antoine MOREL (Artificial intelligence)

> Baptiste MAIRESSE (Graphical client)

> Dylan DEU (Server)

> Geoffrey DAVRIL (Server)