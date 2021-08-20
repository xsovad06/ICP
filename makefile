# Projekt:	ICP
# File: 	Makefile
# Autors: 
#		Samuel Križan	<xkriza06>
#		Damián Sova	<xsovad06>

NAME=xkriza06-xsovad06

compile: update
	cd build && make -f qMakefile

run: compile
	cd build && ./ICP

update: copy
	cd build && qmake ICP.pro -o qMakefile

doxygen:
	doxygen proj/Doxyfile

clean:
	cd build && rm -f *
	rm -rf doc/

pack: clean
	zip -r ${NAME}.zip ./*

copy: copy-examples
	cp -r proj/* build

copy-examples:
	cp -r examples/* build
