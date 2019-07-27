/*
#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~#
#   Feb. 2015 - Gulherme Contesini <gcontesini@gmail.com>                      #
#                                                                              #
#   An Agent-Based Model to Simulate the Spread of Infectious Diseases.        #
#                                                                              #
#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~#
*/

/*
#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~#
# Modules                                                                      #
#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~#
*/

#include "agent_struct.h"
#include "counters_struct.h"
#include "initialize_counters.h"
#include "create_population.h"
#include "make_interactions.h"
#include "update_interactions.h"
#include "write_disease_statistics_in_file.h"
#include "write_population_health_in_file.h"
#include "write_population_statistics_in_file.h"

/*
#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~#
# Files                                                                        #
#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~#
*/

FILE                             \
  * simulation_statistics_file  ,\
  * disease_statistics_file     ,\
  * simulation_dynamic_file     ;

/*
#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~#
# Main                                                                         #
#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~#
*/

void main()
{

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Variables

  int i_int, j_int, k_int, time_int ; 

  time_int = 0 ;
  i_int = time_int ;
  j_int = i_int ;

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~POPULATION

  struct agents population_struct_mtx[ size_x_int ][ size_y_int ] ;

  struct counters *population_info_struct ;

  population_info_struct = \
    ( struct counters * ) malloc( sizeof( struct counters ) ) ;

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~FILE
  
  disease_statistics_file = fopen("disease_statistics.txt", "w") ;
  simulation_statistics_file = fopen("simulation_statistics.txt", "w") ;
  simulation_dynamic_file = fopen("simulation_dynamic.txt", "w") ;

  if ( simulation_statistics_file == NULL )
  {
    printf( "Can't open output file simulation_statistics.txt !\n" ) ;
  }
  if ( disease_statistics_file == NULL )
  {
    printf( "Can't open output file simulation_dynamic.txt !\n" ) ;
  }
  if ( simulation_dynamic_file == NULL )
  {
    printf( "Can't open output file simulation_dynamic.txt !\n" ) ;
  }

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~CREATE POPULATION

  initializeCounters(
    population_info_struct
  ) ;

  createPopulation(
    population_struct_mtx  ,
    population_info_struct 
  ) ;
  
  writeDiseaseStatisticsInFile(
    disease_statistics_file   ,
    population_info_struct
  ) ;
  
  writePopulationHealthInFile(
    simulation_dynamic_file  ,
    population_struct_mtx    
  ) ; 

  writePopulationStatisticsInFile(
    simulation_statistics_file   ,
    population_info_struct       ,
    time_int
  ) ; 

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~SIMULATION

  for( time_int=0; time_int<simulation_time_int; time_int++ )
  {
    for( i_int=0; i_int<size_x_int; i_int++ )
    {
      for( j_int=0; j_int<size_y_int; j_int++ )
      {
        {
          makeInteractions(
            population_struct_mtx ,
            i_int ,
            j_int
          ) ;
        }
        updateInteractions(
          population_struct_mtx  ,
          population_info_struct ,
          i_int,
          j_int
        ) ;
      }
    }

  writePopulationHealthInFile(
    simulation_dynamic_file  ,
    population_struct_mtx
  ) ; 

  writeDiseaseStatisticsInFile(
    disease_statistics_file   ,
    population_info_struct
  ) ;
  
  writePopulationStatisticsInFile(
    simulation_statistics_file   ,
    population_info_struct       ,
    time_int
  ) ;

  }

  fclose( simulation_statistics_file ) ;
  fclose( simulation_dynamic_file ) ;
  printf("End of program!\n") ;

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~END

}
