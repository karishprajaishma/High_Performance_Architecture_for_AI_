#include <mpi.h>
#include <stdio.h>

int main(int argc, char** argv) {
    // Initialize the MPI environment
    MPI_Init(&argc, &argv);

    // Get the rank and size of the process
    int world_rank, world_size;
    MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);
    MPI_Comm_size(MPI_COMM_WORLD, &world_size);

    // Get the processor name
    char processor_name[MPI_MAX_PROCESSOR_NAME];
    int name_len;
    MPI_Get_processor_name(processor_name, &name_len);

    //// Ensure we have 4 processes (for 2x2 matrix)
    if (world_size != 4) {
        if (world_rank == 0) {
            printf("This program requires exactly 4 processes.\n");
        }
        MPI_Finalize();
        return -1;
    }

    // Define the matrices
    int A[2][2] = {
        {1, 2},
        {3, 4}
    };
    int B[2][2] = {
        {5, 6},
        {7, 8}
    };
    int C[2][2]; // Resultant matrix

    // Determine the element this process will compute
    int row = world_rank / 2; // Row index
    int col = world_rank % 2; // Column index

    // Perform addition for the assigned element
    int local_result = A[row][col] + B[row][col];

    // Print the processor information and computation details
    printf("Process %d running on processor %s computed C[%d][%d] = %d\n",
        world_rank, processor_name, row, col, local_result);

    // Gather the results from all processes
    MPI_Gather(&local_result, 1, MPI_INT, C, 1, MPI_INT, 0, MPI_COMM_WORLD);

    // Print the resultant matrix on process 0
    if (world_rank == 0) {
        printf("Resultant matrix C:\n");
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                printf("%d ", C[i][j]);
            }
            printf("\n");
        }
    }

    // Finalize the MPI environment
    MPI_Finalize();
    return 0;
}
