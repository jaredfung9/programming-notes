# Makefile
Included is a generic Makefile used to initialize a basic project directory for C/C++
## USAGE
create a project directory and copy the Makefile into it
* make init: initialize the subdirectories and create a main file at src/main.c
* make: will compile the necessary object files and output an executable under build/bin
* make run: compile executable as needed then run the executable
* make clean: clean all obj and bin files
* Put source files in the src/ directory
* Put header files in the include/ directory
** Don't blindly follow this project structure. Modify or write a structure that best fits your project needs! **
## CUSTOMIZATION
* OUT is the name of the compiled binary program
* OBJS list all the object files used to compile the final executable.
* Each entry in OBJS must conform to the following form: $(OBJ)/SOURCE_FILENAME.o
* OBJ points to the directory to place object files
* BIN points to the directory to place the final executable

# PROJECT STRUCTURES
As a general rule of thumb, split your project into phases.
## PHASE 1: SPECIFICATION & DESIGN
Understand the requirements of your project. If this is a personal project, first sketch out *what* your project wants to do. I prefer including the *why* I want to complete this project as well (for Resume? Hobby? Skill-Dev?)
Next, draft a rough **design doc**. Think modularly. How will each module interact? Depending on the module's complexity, you may want to document the API.  
You need *some* amount of planning, but don't get bogged down documenting everything. Like all good writing, your documentation depends on your audience. Your future self or teammates will thank you.
## PHASE 2: PROJECT SET-UP
Using your design doc, set-up:
0. Project Directory
1. Automated Build System
2. Automated Testing System
## PHASE 3: MODULAR DEVELOPMENT
* Develop in modules
* Continually add tests when you come across issues verifying each module
* Document what you need to test. This is a good starting point for documenting your general API
* Document your **reasons** for implementing code a certain way. Focus on the **why** not the *how*.

## PHASE 4: TESTING
* Think of edge cases, if you've been diligent in phase 3 you should have a solid starting suite to base off of
* Integration tests


