<h1 align="center"> so_long </h1>

<p align="center">:information_source: A small 2D game made using the MiniLibX Graphics Library 

<h2 align="center"> What is so_long </h2>

The fifth project at 42 programming school and our first graphical project. 
So_long is a a top-down game using the school graphical library: the MiniLibX witch was developed internally.
	
<h2 align="center"> Requirements </h2>
* [Minilibx](https://github.com/42sp/minilibx-linux) installed (for 42 students using Workspaces the library is already installed)
* Minilibx requires differents libraries depending on the OS as explained [here](https://harm-smits.github.io/42docs/libs/minilibx/getting_started.html)
* For Linux or Mac OS update Makefile as indicated [here](https://harm-smits.github.io/42docs/libs/minilibx/getting_started.html) in the installation and compilation parts.
 
<h2 align="center"> Running! </h2>
To play, first compile the project with make:

	make
	
Then, run ./so_long followed by the map:
	
	./so_long assets/maps/valid/map2.ber	

<h3 align="center"> Maps </h3>   
The map must respect some rules:

The map must be a .ber file.

And can only contain these characters:
    
| CHAR      |	  OBJECT   |
| --------- | ---------- |
| 1         |   Wall     |
| C	        |   Coin     |
| E	        |   Exit     |
| P         |   Player   |      
| 0         |   Floor    |
    
The map must be rectangular and surrounded by walls '1'.

The map must contain one exit, at least one collectible, and one starting position.

Check some samples in the folder /assets/maps.

<h2 align="center"> The game </h2>

Use WASD or arrow keys to move.
    
| KEY       |   OBJECT    |
| --------- | ----------  |
| W or ⬆️   |   Move up   |
| A	or ⬅️   |   Move left |
| S	or ⬇️   |   Move down |
| D or ➡️   |   Move right|      
| Q or Esc  |  Close      | 
        
After getting all the collectables, you can access the exit.
	
You can close the game by clicking on the cross on the window’s frame, or pressing Esc.

Enjoy!
