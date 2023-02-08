# So_long

The fifth project at 42 programming school and our first graphical project. 
So_long is a a top-down game using the school graphical library: the MiniLibX witch was developed internally.

## Requirements

[Minilibx](https://github.com/42sp/minilibx-linux) installed (for 42 students using Workspaces the library is already installed)

Minilibx requires differents libraries depending on the OS as explained [here](https://harm-smits.github.io/42docs/libs/minilibx/getting_started.html)

For Linux or Mac OS update Makefile as indicated [here](https://harm-smits.github.io/42docs/libs/minilibx/getting_started.html) in the installation and compilation parts.

## Running

To play, first compile the project with make:

	make
	
Then, run ./so_long followed by the map:
	
	./so_long assets/maps/valid/map2.ber	

Check some samples in the folder:
	
	 /assets/maps.

## Maps

The map must be a .ber file and respect some rules:

 * The map has to be constructed with 3 components: walls, collectibles, and free
space.

 * The map can be composed of only these 5 characters:
	- 0 for an empty space,
	- 1 for a wall,
	- C for a collectible,
	- E for a map exit,
	- P for the player’s starting position.
	
* The map must contain 1 exit, at least 1 collectible, and 1 starting position to
 be valid.

 * The map must be rectangular.

 * The map must be closed/surrounded by walls. If it’s not, the program must return
 an error.

## Playing

Use WASD or arrow keys to move.

After getting all the collectables, you can access the exit.
	
You can close the game by clicking on the cross on the window’s frame, or pressing Esc.

I hope you enjoy it!
