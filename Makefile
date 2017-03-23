CC=mpicc
FLAGS=-O3
EXECS=sr sr2 pingpong pingpong_array pingpong_nonblocking

all: ${EXECS}

sr: sr.c
	${CC} ${FLAGS} $^ -o sr

sr2: sr2.c
	${CC} ${FLAGS} $^ -o sr2

pingpong: pingpong.c
	${CC} ${FLAGS} $^ -o pingpong

pingpong_array: pingpong_array.c
	${CC} ${FLAGS} $^ -o pingpong_array


clean:
	rm -f ${EXECS}
