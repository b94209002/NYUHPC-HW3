/* Communication ping-pong:
 * Exchange between messages between mpirank
 * 0 <-> 1, 2 <-> 3, ....
 */
#include <stdio.h>
#include <unistd.h>
#include <mpi.h>

int main( int argc, char *argv[])
{
  int rank, tag, source, destination, m;
  MPI_Status status;

  MPI_Init(&argc, &argv);
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);

  if (argc != 2) {
    fprintf(stderr, "Function needs the number of passes as input arguments!\n");
   MPI_Finalize(); return 0;
  }

  m = atol(argv[1]);
  int message_out = rank;
  int message_in = -1;
  tag = 99;
  int i,k; int n = 6;

  double  time1,time2;
  time1 = MPI_Wtime();

  if (rank == 0 ) message_in = 0 ;
  for ( k = 0; k < m; k++){
 
  for (i=0;i<n; i++){
  if(rank % n == i)
  {
    destination = (rank +1) %n;
    message_out = message_in + rank;
    MPI_Send(&message_out, 1, MPI_INT, destination, tag, MPI_COMM_WORLD);
  }
  else if ((rank+n-1) % n == i)
  {
    source = (rank+n -1)%n ;

    MPI_Recv(&message_in,  1, MPI_INT, source, tag, MPI_COMM_WORLD, &status);
  }
  }
//  printf("%d rounds, rank %d received from %d the message %d \n",k, rank, source, message_in);
  }
  time2 = MPI_Wtime();
  double elapsed = time2 - time1;
  printf("%d rounds, rank %d, communication time %f \n ",k, rank, elapsed);

  MPI_Finalize();
  return 0;
}
