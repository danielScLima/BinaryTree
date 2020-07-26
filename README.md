Binary Tree
====================

This repository has a project with the implementation of a Binary Tree.

It is written in C++.

The code of the Binary Tree is independent of platform.

Is has two possible main files:

* [Codes](#markdown-header)
	* [A main that triggers unit test;](#markdown-header-emphasis)

	* [A Qt project to manage the Binary Tree (With Gui).](#markdown-header-strikethrough)
	
The library used to make the Unit Test is the Catch v2.12.3. The code is already in this repository.

The Qt project generates images of the Binary Tree, using the lib Graphviz.
Install this lib in your computer for you to be able to create such images.

The code was written containing the Doxygen documentation.

- - -

You have several options to build the project: 
====================

* [Build tools](#markdown-header)
	* [Makefile (using the file named MakefileGeneral);](#markdown-header-emphasis)
	* [CMake.](#markdown-header-emphasis)
	* [Qt Project (With QMake).](#markdown-header-emphasis)

The project has no leaks (Fully tested with Valgrind).

All the unit tests are ok.

- - -

The functionalities available are: 
====================

* [Functionalities](#markdown-header)
	* [Insert;](#markdown-header-emphasis)
	* [Search;](#markdown-header-emphasis)	
	* [Remove;](#markdown-header-emphasis)
	* [In-order traversal;](#markdown-header-emphasis)
	* [Pos-order traversal;](#markdown-header-emphasis)
	* [Pre-order traversal;](#markdown-header-emphasis)
	* [In-level traversal;](#markdown-header-emphasis)
	
- - -

Sample images: 
====================

## Type 1 of view:

![Alt text](images/sample.png)

## Type 2 of view:
![Alt text](images/sample2.png)

## It is an unbalanced tree

![Alt text](images/sampleunbalanced.png)

Qt gui project: 
====================
The qt gui application gui is shown below:

![Alt text](images/guisample.png)


Pre-order: 
====================

![Alt text](images/preorder.png)

In-order: 
====================

![Alt text](images/inorder.png)

Pos-order: 
====================

![Alt text](images/posorder.png)

In-level: 
====================

![Alt text](images/inlevel.png)

