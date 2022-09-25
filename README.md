# get_next_line
May it be a file, stdin, or even later a network connection, always need a way to read content line by line. Essential for the future projects.

This function reads data from a file which is pointer by a file descriptor and returns the first line it reads. 
It has a static index which holds the data after the first line returned and keeps returning line from where it was left at the last call.
strings to be returned are heap allocated and must be freed when they are no longer needed.
