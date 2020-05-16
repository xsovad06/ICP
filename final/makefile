#
 # Projekt ICP
 # Subor: Makefile
 # Autori: 
 #		Samuel Križan <xkriza06>
 #		Damián Sova <xsovad06>
 #
 NAME=xkriza06-xsovad06

all: run

make:
	cd src/build && make

run: make copy
	cd src/build && ./proj

clean:
	cd src/build && rm -f *.cpp 
	cd src/build && rm -f *.h
	cd src/build && rm -f *.o
	cd src/build && rm -f proj
	cd src/build && rm -f *.txt

pack: clean
	zip -r ${NAME}.zip ./*

copy:
	cp -r examples/* src/build

doxygen:
	doxygen doxconf
