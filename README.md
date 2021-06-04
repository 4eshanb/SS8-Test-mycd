# mycd

This program simulates a "cd" Unix command that changes a current
directory in an abstract file system. The simulated command takes two path
strings from the command line and prints either a new path or an error message.
The program checks that the second argument is a valid path without
relying on any OS system call or shell command such as chdir() for verification.
It then constructs a new path, and prints it out. 

One version of the program is written in C++ and another version is written in 
python.

The first path is a current directory. The second path is a new directory.

Assumptions:
1) The directory structure is read in from a file called directories.txt
2) A directory name can only contain alphanumeric characters. 
3) A single dot (".") indicates a current directory, and
the two consecutive dots ("..") indicate a step to a previous directory, up
from the current one. 
4) A single forward slash "/" indicates a root directory.
Multiple consecutive slashes are treated as equivalent to a single one.

To run the C++ version:
  g++ mycd.cpp hashtable.cpp -o mycd
  ./mycd

To run the python version:
  python3 mycd.py

Tests (result printed below each test):

mycd / abc\
/abc

mycd /abc/def z\
/abc/def/z

mycd /abc/def ..\
/abc

mycd /abc/def /abc\
/abc

mycd /abc/def /abc/ghi\
/abc/ghi

mycd /abc/def ../..\
/

mycd /abc/def ../../..\
/

mycd /abc/def .\
/abc/def

mycd /abc/def ..klm\
..klm: No such file or directory

mycd /abc/def //////\
/

mycd /abc/def ......\
......: No such file or directory

mycd /abc/def ../ghi///../def/z/.\
/abc/def/z

ls /abc/def ..\
please use mycd command

mycd jhkgj /abc\
first argument not valid\
here are the directories:\
/\
/abc\
/mno\
/abc/def\
/abc/ghi\
/abc/jkl\
/mno/pqr\
/mno/stu\
/mno/wxy\
/abc/def/z\




