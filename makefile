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

update: copy
	cd src/build && qmake ICP.pro -o qMakefile

doxygen:
	doxygen src/proj/Doxyfile

clean:
	cd src/build && rm -f *
	rm -rf doc/

pack: clean
	zip -r ${NAME}.zip ./*

copy: copy-examples
	cp -r src/proj/* src/build

copy-examples:
	cp -r examples/* src/build
