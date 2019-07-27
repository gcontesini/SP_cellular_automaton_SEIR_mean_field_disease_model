#ifndef WRITE_POPULATION_HEALTH_IN_FILE_H
#define WRITE_POPULATION_HEALTH_IN_FILE_H

#include "create_population.h"
#include "agent_struct.h"

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~WRITE POPULATION IN FILE

void writePopulationHealthInFile(
  FILE *simulation_dynamic_file ,
  struct agents population_struct_mtx_[size_x_int][size_y_int]
)
{
  int i_int, j_int;

  for( i_int=0; i_int<size_x_int; i_int++ )
  {
    for( j_int=0; j_int<size_y_int; j_int++ )
    {
      if(j_int == size_y_int-1 )
      {                              
        fprintf(
          simulation_dynamic_file,\
          "%d\n",\
          population_struct_mtx_[i_int][j_int].health_int
        );
      }
      else
      {
        fprintf(
          simulation_dynamic_file,\
          "%d ",\
          population_struct_mtx_[i_int][j_int].health_int
        ); 
      }
    }
  }
  fprintf(
    simulation_dynamic_file,\
    "\n"
  );
}

#endif