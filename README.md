# Wolf3D

Compilation - type "make" at the root of the git repository. An executable named wolf3d will be created.

Execution : Type "./wolf3d" followed by the path to a valid map as the second argument. Some valid maps are available in the maps folder at the root of the directory.

The following keyboard keys interact with the program: 

Up arrow & 'W' : Move Forwards
Down Arrow & 'S' : Move Backwards
Left Arrow & 'A' : Turn Left
Right Arrow & 'D' : Turn Right
'1' : Textures will be relevant to textures in map
'2' : Textures will act as a compass (NESW)
'M' : Turns minimap on and off
'delete' : restarts map, resets your position, direction, ect.
'esc' : Exits the Program

You may create maps. For a map to be valid, it must abide by the following rules:
1) The map document must have at least 4 lines of at least 4 numbers, and a maximum of 100 lines of 100 numbers. 
2) Each line must have the same amount of numbers. (Ultimately the map will resemble a quadrilateral)
3) Each number must be seperated by one space
4) The first and last line, along with the first and last number of each line cannot be 0. These will be the outer walls. 
5) The second character of the second line must be a 0. This will be the starting position.
6) The numbers must vary from 0 to 7. Each number from 1 to 6 will be a different texture. 0s will be available spaces your character can move through. 
7) Each line must be followed by one newline character. (this is optional for the last line)
8) Don't place any characters in the file, appart from newlines, spaces, and numbers from 0 - 7. If you do, the map may or may not be valid. 

An invalid map may or may not work with the program.

The following textures will be set to the relevant position if the corresponding number is set in the map: 

1 : Grey Stones
2 : Purple Stones
3 : Wood Planks
4 : Colored Stones
5 : Mossy Stones
6 : Red Bricks

Don't edit the files in the 'textures' directory
