#ifndef UPDATE_INTERACTIONS_H
#define UPDATE_INTERACTIONS_H

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~LIBRARY

#include "agent_struct.h"
#include "counters_struct.h"

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~UPDATE INTERACTIONS

updateInteractions(
  struct agents population_struct_mtx_[size_x_int][size_y_int] ,
  struct counters *population_info_struct_ ,
  int i_int_ ,
  int j_int_
)
{
  int person_int ;

  if( 
    population_struct_mtx_[i_int_][j_int_].time_on_health_state_int == \
      disease_time_int
  )
  {
    population_struct_mtx_[i_int_][j_int_].health_int = \
      population_struct_mtx_[i_int_][j_int_].next_health_int ;
    population_struct_mtx_[i_int_][j_int_].time_on_health_state_int = 0 ;

    if( population_struct_mtx_[i_int_][j_int_].health_int == infected_int )
    {
      population_info_struct_->number_of_infected_int++ ;
      population_info_struct_->number_of_susceptible_int-- ; 
    }
    else if( 
      population_struct_mtx_[i_int_][j_int_].health_int == recovered_int
    )
    {
      population_info_struct_->number_of_infected_int-- ;
      population_info_struct_->number_of_recovered_int++ ;
    }
  }
  else if( population_struct_mtx_[i_int_][j_int_].health_int != recovered_int )
  {
    population_struct_mtx_[i_int_][j_int_].time_on_health_state_int++ ;
  }
}

#endif

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~END