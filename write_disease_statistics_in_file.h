#ifndef WRITE_DISEASE_STATISTICS_IN_FILE_H
#define WRITE_DISEASE_STATISTICS_IN_FILE_H

#include "create_population.h"
#include "agent_struct.h"
#include "counters_struct.h"

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Write Population Statistics in File

void writeDiseaseStatisticsInFile(
  FILE *simulation_statistics_file ,
  struct counters *population_info_struct_
)
{
  fprintf(
    simulation_statistics_file,
    "%.2f\t%.2f\t%.2f\n",
    (population_info_struct_->number_of_susceptible_int/(size_x_int*size_y_int)),
    (population_info_struct_->number_of_infected_int /(size_x_int*size_y_int)),
    (population_info_struct_->number_of_recovered_int/(size_x_int*size_y_int))
  ) ;
}

#endif