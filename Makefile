CC=mpicc
FLAGS=-O3
EXECS= int_ring int_ring_2mb

all: ${EXECS}

int_ring: int_ring.c
	${CC} ${FLAGS} $^ -o int_ring
int_ring_2mb : int_ring_2mb.c
	${CC} ${FLAGS} $^ -o int_ring_2mb

clean:
	rm -f ${EXECS}
