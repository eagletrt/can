all: copy patch build
all-arm: copy patch build-arm

copy:
	cp can-utils/lib.c . 
	cp can-utils/lib.h .
	cp can-utils/canframelen.c .
	cp can-utils/canframelen.h .
	cp can-utils/terminal.h .
	cp -r can-utils/include .

	cp can-utils/candump.c .
	cp can-utils/cansniffer.c .

patch:
	patch -ruN < patches/candump.patch
	patch -ruN < patches/cansniffer.patch

build:
	mkdir -p build
	cd build && cmake -G "Unix Makefiles" ..
	make -C build
	mv build/eagle_candump build/eagle_candump_x86_64
	mv build/eagle_cansniffer build/eagle_cansniffer_x86_64

build-arm:
	mkdir -p build
	cd build && cmake -G "Unix Makefiles" -D CMAKE_C_COMPILER=arm-linux-gnueabihf-gcc ..
	make -C build
	mv build/eagle_candump build/eagle_candump_arm
	mv build/eagle_cansniffer build/eagle_cansniffer_arm

clean: 
	rm -rf build

.PHONY: build copy patch clean