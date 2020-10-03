# CS 4375 - Operating Systems

## Lab 5: Synchronization

**Author: Matthew S Montoya**</br>
**Author: Matthew Iglesias**</br>
**Due: May 3, 2020**

### Objective

The objective for this lab is to model the following scenario as a producer-consumer: A NASA spacecraft antenna controller needs the signal from two antennas at the same time.

### Directory Structure

The directory structure used herein to manage documents and files is as follows:

At the top level, files describing the project meant for users to read: ```README.md```. The only other files that would be expected here is a ```.gitignore``` file, listing files and/or folders which Git should ignore and a ```.git``` file, containing git metadata. There are two subdirectories of this structure: ```/doc``` and ```/src```

The ```/doc``` directory shall contain all information material for documenting the project.

All source code and answers related to this project is located in the ```/src``` subdirectory.

### How To Compile & Run

1. Using a Linux VM, navigate to the ```/src``` subdirectory via the terminal
2. Enter the following command to compile the program
  ```make```</br>or</br>```sudo make```
3. Enter the following command to execute the program</br>
  ```./lab5.o```

### Dependancies

1. A Linux-based virtual machine OR
2. A Linux-based machine (Note: This should be reserved for advanced users)

### Warnings

* Although the dependencies call for the use of a virual machine, you may use a local Linux OS to compile & execute this code. This should be reserved for advanced users
