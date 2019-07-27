#ifndef INITIALIZE_COUNTERS_H
#define INITIALIZE_COUNTERS_H

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~LIBRARY

#include "counters_struct.h"

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~FUNCTION

void initializeCounters(
	struct counters *population_info_struct_ 
)
{
  population_info_struct_->number_of_agents_int = 0.0 ;
  population_info_struct_->number_of_male_int = 0.0 ;
  population_info_struct_->average_age_int = 0.0 ;

  population_info_struct_->number_of_vaccinated_int = 0.0 ;
  population_info_struct_->number_of_susceptible_int = 0.0 ; 
  population_info_struct_->number_of_infected_int = 0.0 ;
  population_info_struct_->number_of_recovered_int = 0.0 ; 
}

#endif

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~END