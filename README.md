# Wolf3D

This is a project which asks to reproduce in C the 3D raycasting game mechanics of Wolfenstein 3D.

To Compile - type "make" at the root of the git repository. 

Execution: Compile, and an executable will be created.
Type "./" followed by the executable as a first argument, followed by a valid map as a second argument. 


Valid Map: 
For a map to be valid, it must abide by the following rules:

1) The map document must have at least 4 lines of at least 4 numbers, and a maximum of 100 lines of 100 numbers. 
2) Each line must have the same amount of numbers. (ultimately the map will be a square/ractangle)
3) Each number must be seperated by one space
4) The first and last line, along with the first and last number of each line cannot be 0. These will be the outer walls. 
5) The second character of the second line must be a 0. This will be the starting position.
6) The numbers must vary from 0 to 7. Each number from 1 to 6 will be a different texture. 0s will be available spaces your character can move through. 
7) Each line must be followed by one newline character. (this is optional for the last line)
8) Don't place any characters in the file, appart from newlines, spaces, and numbers from 0 - 7. If you do, the map may or may not be valid. 

Some valid maps are provided in the 'maps' directory.
An invalid map may or may not work with the program. If it doesn't work, the program will ask you to come back and read this more carefully ;)

Textures: 
The following textures will be set to the relevant position if the corresponding number is set in the map: 

1 : Grey Stones
2 : Purple Stones
3 : Wood Planks
4 : Colored Stones
5 : Mossy Stones
6 : Red Bricks

Don't edit the files in the 'textures' directory


The following keyboard keys interact with the program: 

Up arrow & 'W' : Move Forwards
Down Arrow & 'S' : Move Backwards
Left Arrow & 'A' : Turn Left
Right Arrow & 'D' : Turn Right
'1' : Textures will be relevant to textures in map
'2' : Textures will be defined by the direction a wall is facing (NESW)
'M' : Turns on and off minimap
'delete' : restarts map, resets your position, direction, ect.
'esc' : Exits the Program
