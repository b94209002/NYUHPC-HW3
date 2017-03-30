## NYU HPC HW3.
### Mu-Hua Chien 
### mhc431@nyu.edu

1. Test for correct communication mpirun -np 20 ./int_ring 1

0 rounds, rank 1 received from 0 the message 0   
0 rounds, rank 2 received from 1 the message 1   
0 rounds, rank 3 received from 2 the message 3    
0 rounds, rank 4 received from 3 the message 6    
0 rounds, rank 5 received from 4 the message 10    
0 rounds, rank 6 received from 5 the message 15    
0 rounds, rank 7 received from 6 the message 21     
0 rounds, rank 8 received from 7 the message 28     
0 rounds, rank 9 received from 8 the message 36     
0 rounds, rank 11 received from 10 the message 55     
0 rounds, rank 12 received from 11 the message 66     
0 rounds, rank 13 received from 12 the message 78     
0 rounds, rank 10 received from 9 the message 45    
0 rounds, rank 14 received from 13 the message 91     
0 rounds, rank 15 received from 14 the message 105     
0 rounds, rank 16 received from 15 the message 120    
0 rounds, rank 17 received from 16 the message 136    
0 rounds, rank 18 received from 17 the message 153    
0 rounds, rank 0 received from 19 the message 190    
0 rounds, rank 19 received from 18 the message 171    

2. Test for latency about CIMS crunchy1.cims.nyu.edu with 20 nodes 

mpirun -n 20 ./int_ring 1000

1000 rounds, rank 0, communication time 4.636791 sec. 

Latency = 2.3 x 10^-4 sec

mpirun -n 10 ./int_ring 1000

1000 rounds, rank 0, communication time 0.014833 sec.

Latency = 1.5 x 10^-6 sec 

3. Test for large array data[500,000]

mpirun -n 20 ./int_ring 100

100 rounds, rank 0, communication time 59.738771 sec.

Bandwidth = 2 x 100 x 20 / 59.738771 = 66.95 MB/s 

mpirun -n 10 ./int_ring 100

100 rounds, rank 0, communication time 14.280453 sec.

ndwidth = 2 x 100 x 10 / 59.738771 = 60.10 MB/s


