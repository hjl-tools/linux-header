KERNEL-DIR=/export/gnu/import/git/linux-2.6
KERNEL-INC-FLAGS=-I$(KERNEL-DIR)/usr/include
KERNEL-FLAGS=-DKERNEL_HDR
GLIBC-DIR=/export/build/gnu/glibc-x32/release/x86_64-linux
GLIBC-INC-FLAGS=-I$(GLIBC-DIR)/usr/include
GLIBC-FLAGS=-D_GNU_SOURCE
CFLAGS=-mx32 -I$(GLIBC-DIR)/usr/include $(KERNEL-INC-FLAGS)

all: kernel glibc
	./kernel > kernel.out
	./glibc > glibc.out
	diff -up kernel.out glibc.out

glibc: types.c
	$(CC) $(GLIBC-FLAGS) $(CFLAGS) -o $@ $<

kernel: types.c
	$(CC) $(KERNEL-FLAGS) $(CFLAGS) -o $@ $<

clean:
	rm -f kernel glibc *.out
