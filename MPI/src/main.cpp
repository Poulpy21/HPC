
#include <cstdio>
#include "log.hpp"
#include "mpi.h"
 
int main( int argc, char *argv[] )
{
    using log4cpp::log_console;
    log4cpp::initLogs();

    static const char* MPI_levels[4] = {"MPI_THREAD_SINGLE", "MPI_THREAD_FUNNELED", "MPI_THREAD_SERIALIZED", "MPI_THREAD_MULTIPLE"}; 
    
    int claimed = MPI_THREAD_MULTIPLE;
    int provided = -1;
    MPI_Init_thread(&argc, &argv, claimed, &provided);
    
    log_console->infoStream() << "Query thread level: " << MPI_levels[claimed] ;
    log_console->infoStream() << "Init thread level: " << MPI_levels[provided] ;
 
    MPI_Finalize();

    return EXIT_SUCCESS;
}

