#ifndef MAKE_INTERACTIONS_H
#define MAKE_INTERACTIONS_H

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~LIBRARY

#include "agent_struct.h"

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~MAKE INTERACTIONS

makeInteractions(
  struct agents population_struct_mtx_[size_x_int][size_y_int],
  int i_int_,
  int j_int_
)
{
  int person_int ;
  if( 
    population_struct_mtx_[i_int_][j_int_].health_int == 0 \
    && \
    population_struct_mtx_[i_int_][j_int_].next_health_int == 0
  )
  {
    for( person_int=0; person_int<number_of_interactions_int; person_int++ )
    {
      if(
        population_struct_mtx_[i_int_][j_int_].\
          interactions_struct[person_int]->health_int == infected_int
        &&
        rand() % 101 < ( r_0_float * 100 )
        &&
        population_struct_mtx_[i_int_][j_int_].vaccination_bool != 1
      )
      {
        population_struct_mtx_[i_int_][j_int_].next_health_int = infected_int ;
      }
    }
  }
  else if( population_struct_mtx_[i_int_][j_int_].health_int == infected_int )
  {
    population_struct_mtx_[i_int_][j_int_].next_health_int = recovered_int ;
  }
}

#endif          