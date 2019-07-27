#ifndef WRITE_POPULATION_STATISTICS_IN_FILE_H
#define WRITE_POPULATION_STATISTICS_IN_FILE_H

#include "create_population.h"
#include "agent_struct.h"
#include "counters_struct.h"

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Write Population Statistics in File

void writePopulationStatisticsInFile(
  FILE *simulation_statistics_file ,
  struct counters *population_info_struct_ ,
  int day_int_
)
{
  int i_int, j_int;

  fprintf(
    simulation_statistics_file,\
    "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~day - %d\n",
    day_int_
  ) ;

  fprintf(
    simulation_statistics_file ,
    "\nPopulation Status:\n"
  ) ;

  fprintf(
    simulation_statistics_file,
    "\tAverage Age = %.2f\n",
    ( population_info_struct_->average_age_int/(size_x_int*size_y_int))
  ) ;

  fprintf(
    simulation_statistics_file ,
    "\tpercentage_of_male_float = %.2f\n" ,
    ( population_info_struct_->number_of_male_int/(size_x_int*size_y_int))
  ) ;

  fprintf(
    simulation_statistics_file,
    "\tpercentage_of_vaccination_float = %.2f\n",
    ( population_info_struct_->number_of_vaccinated_int / (size_x_int*size_y_int) )
  ) ;

  fprintf(
    simulation_statistics_file ,
    "\nDisease Status:\n"
  ) ;

  fprintf(
    simulation_statistics_file,
    "\tpercentage_of_susceptible_float = %.2f\n",
    ( population_info_struct_->number_of_susceptible_int / (size_x_int*size_y_int) )
  ) ;

  fprintf(
    simulation_statistics_file,
    "\tpercentage_of_infected_float = %.2f\n",
    ( population_info_struct_->number_of_infected_int /(size_x_int*size_y_int))
  ) ;

  fprintf(
    simulation_statistics_file,
    "\tpercentage_of_recovered_float = %.2f\n",
    ( population_info_struct_->number_of_recovered_int /(size_x_int*size_y_int))
  ) ;
  fprintf(
  simulation_statistics_file,
  "\n"
  ) ;
}

#endif