/* Communication ping-pong:
 * Exchange between messages between mpirank
 * 0 <-> 1, 2 <-> 3, ....
 */
#include <stdio.h>
#include <unistd.h>
#include <mpi.h>

int main( int argc, char *argv[])
{
  int rank, tag, source, destination;
  MPI_Status status;

  char hostname[1024];
  gethostname(hostname, 1024);

  MPI_Init(&argc, &argv);
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);

  int message_out = rank;
  int message_in = -1;
  tag = 99;
  int i; int n = 6;
  if (rank == 0 ) message_in = 333;
  for (i=0;i<n; i++){
  if(rank % n == i)
  {
    destination = (rank +1) %n;
    message_out = message_in;
    MPI_Send(&message_out, 1, MPI_INT, destination, tag, MPI_COMM_WORLD);
  }
  else if (rank % n == i+1)
  {
    source = (rank+n -1)%n ;

    MPI_Recv(&message_in,  1, MPI_INT, source, tag, MPI_COMM_WORLD, &status);
  }
  }
  printf("rank %d hosted on %s received from %d the message %d\n", rank, hostname, source, message_in);

  MPI_Finalize();
  return 0;
}
