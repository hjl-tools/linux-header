KERNEL-DIR=/export/gnu/import/git/kernel.org/linux-stable
KERNEL-INC-FLAGS=-I$(KERNEL-DIR)/usr/include
KERNEL-FLAGS=-DKERNEL_HDR
GLIBC-DIR=/export/build/gnu/glibc-x32/release/x86_64-linux
GLIBC-INC-FLAGS=-I$(GLIBC-DIR)/usr/include
GLIBC-FLAGS=-D_GNU_SOURCE
CFLAGS=-I$(GLIBC-DIR)/usr/include $(KERNEL-INC-FLAGS)

all: kernel.x32 glibc.x32 kernel.32 glibc.32 kernel.64 glibc.64
	./kernel.x32 > kernel.x32.out
	./glibc.x32 > glibc.x32.out
	./kernel.32 > kernel.32.out
	./glibc.32 > glibc.32.out
	./kernel.64 > kernel.64.out
	./glibc.64 > glibc.64.out
	diff -up kernel.64.out glibc.64.out
	diff -up kernel.32.out glibc.32.out
	diff -up kernel.x32.out glibc.x32.out

glibc.%: types.c
	$(CC) -m$$(echo $@ | sed -e "s/glibc.//") \
		$(GLIBC-FLAGS) $(CFLAGS) -o $@ $<

kernel.%: types.c
	$(CC) -m$$(echo $@ | sed -e "s/kernel.//") \
		$(KERNEL-FLAGS) $(CFLAGS) -o $@ $<

clean:
	rm -f kernel.* glibc.*
