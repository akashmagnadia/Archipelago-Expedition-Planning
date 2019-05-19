# Archipelago-Expedition-Planning

command - description  

q - quit the program immediately. 

? - display a list of the commands the user can enter for the program.

#- ignore this line of input.  Treat the line of input as a comment.

t <int1> <int2> - display a message stating whether a person can gofrom island<int1>to island<int2>withone or more ferry rides.

r <int> - remove all values from the archipelagoexpeditionand resize the array to contain the number of islandsas indicated by the given integer value. The value of the integer must be greater than zero.The islandswill be numbered from 1 to the given integer value.Be sure to deallocate all unused memory as part of this command.

i <int1> <int2> - insert the edge to indicate a ferry ride from island<int1>to island<int2>. 

d <int1> <int2> - delete the edge that indicates a ferry ride from island<int1>to island<int2>. 

l - list all the items contained in the archipelagoexpedition. First display all of the islands(if any) that can be reached from theisland#1withone ferry ride(that have an edge in thearchipelago),followed by all the islands(if any) thatcan be reached from island#2with one ferry ride, etc. 

f <filename> - open the file indicated by the <filename>(assume it is in the current directory) and read commands from this file.   When the end of the file is reached, continue reading commands from previous input source.  This must be handled using recursion.  Beware ofa possible case of an infinite recursive loop, the fcommand is may not call a file that is currently in use.
