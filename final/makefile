# Projekt:	ICP
# File: 	Makefile
# Autors: 
#		Samuel Križan	<xkriza06>
#		Damián Sova	<xsovad06>

NAME=xkriza06-xsovad06

compile: update
	cd src/build && make -f qMakefile

run: compile
	cd src/build && ./ICP

update: ICP.pro copy
	cd src/build && qmake ICP.pro -o qMakefile

doxygen:
	doxygen src/proj/Doxyfile

clean:
	cd src/build && rm -f *.cpp 
	cd src/build && rm -f *.h
	cd src/build && rm -f *.o
	cd src/build && rm -f proj
	cd src/build && rm -f *.txt
	cd src/build && rm -f *.ui
	cd src/build && rm -f Doxyfile ICP qMakefile
	rm -rf doc/

pack: clean
	zip -r ${NAME}.zip ./*

copy:
	cp -r src/proj/* src/build
