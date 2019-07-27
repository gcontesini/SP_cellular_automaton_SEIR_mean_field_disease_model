#ifndef CREATE_POPULATION_H
#define CREATE_POPULATION_H

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~LIBRARY

#include "agent_struct.h"
#include "counters_struct.h"

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~CREATE POPULATION

void createPopulation(
  struct agents population_struct_mtx_[size_x_int][size_y_int] ,
  struct counters *population_info_struct_                 
)
{
  int i_int, j_int, k_int;
  int position_x_int, position_y_int ;

  for( i_int=0; i_int<size_x_int; i_int++ )
  {
    for( j_int=0; j_int<size_y_int; j_int++ )
    {

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ID

      population_struct_mtx_[i_int][j_int].uid_int = i_int + j_int ;
      population_info_struct_->number_of_agents_int++ ;

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~AGE

      population_struct_mtx_[i_int][j_int].age_int = rand() % 90 ;
      population_info_struct_->average_age_int =       \
        population_info_struct_->average_age_int      +\
        population_struct_mtx_[i_int][j_int].age_int ;

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~TIME

      population_struct_mtx_[i_int][j_int].time_on_health_state_int = 0 ;

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~GENDER

      if( rand() % 101 < percetage_of_male_float * 100 )
      {
        population_struct_mtx_[i_int][j_int].gender_int = 0 ;
        population_info_struct_->number_of_male_int++ ;
      }
      else
      {
        population_struct_mtx_[i_int][j_int].gender_int = 1 ;
      }

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~VACCTINATION

      if( rand() % 101 < vaccination_percetage_float * 100 )
      {
        population_struct_mtx_[i_int][j_int].vaccination_bool = 1 ;
        population_info_struct_->number_of_vaccinated_int++ ;
      }
      else
      {
        population_struct_mtx_[i_int][j_int].vaccination_bool = 0 ;
      }

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~INFECTED

      if( rand() % 101 < percetage_of_initial_infected_float * 100 )
      {
        population_struct_mtx_[i_int][j_int].health_int = 1 ;
        population_struct_mtx_[i_int][j_int].next_health_int = 1 ;
        population_info_struct_->number_of_infected_int++ ;
      }
      else
      {
        population_struct_mtx_[i_int][j_int].health_int = 0 ;
        population_struct_mtx_[i_int][j_int].next_health_int = 0 ;
        population_info_struct_->number_of_susceptible_int++ ;
      }
    }
  }

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~INTERACTIONS

  for( i_int=0; i_int<size_x_int; i_int++ )
  {
    for( j_int=0; j_int<size_y_int; j_int++ )
    {

      // position_x_int = rand() % size_x_int ;
      // position_y_int = rand() % size_y_int ;
      // population_struct_mtx_[i_int][j_int].interactions_struct[ k_int ] = \
      //   &population_struct_mtx_[ position_x_int ][ position_y_int ] ;

      //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Von Neumann Neighborhood      
      k_int = 0 ;
      if( i_int == 0 && j_int == 0 )
      {
        population_struct_mtx_[i_int][j_int].interactions_struct[ k_int ] = \
          &population_struct_mtx_[ (size_x_int-1)%size_x_int ][ j_int ] ;

        k_int++ ;

        population_struct_mtx_[i_int][j_int].interactions_struct[ k_int ] = \
          &population_struct_mtx_[ (size_x_int+1)%size_x_int ][ j_int ] ;

        k_int++ ;

        population_struct_mtx_[i_int][j_int].interactions_struct[ k_int ] = \
          &population_struct_mtx_[ i_int ][ (size_y_int-1)%size_y_int ] ;  

        k_int++ ;

        population_struct_mtx_[i_int][j_int].interactions_struct[ k_int ] = \
          &population_struct_mtx_[ i_int ][ (size_y_int+1)%size_y_int ] ;

        k_int++ ;
      } 
      else if( i_int == 0 && j_int != 0 )
      {
        population_struct_mtx_[i_int][j_int].interactions_struct[ k_int ] = \
          &population_struct_mtx_[ (size_x_int-1)%size_x_int ][ j_int ] ;

        k_int++ ;

        population_struct_mtx_[i_int][j_int].interactions_struct[ k_int ] = \
          &population_struct_mtx_[ (size_x_int+1)%size_x_int ][ j_int ] ;

        k_int++ ;

        population_struct_mtx_[i_int][j_int].interactions_struct[ k_int ] = \
          &population_struct_mtx_[ i_int ][ (j_int-1)%size_y_int ] ;  

        k_int++ ;

        population_struct_mtx_[i_int][j_int].interactions_struct[ k_int ] = \
          &population_struct_mtx_[ i_int+1 ][ (j_int+1)%size_y_int ] ;

        k_int++ ;
      }
      else if( i_int != 0 && j_int == 0 )
      {
        population_struct_mtx_[i_int][j_int].interactions_struct[ k_int ] = \
          &population_struct_mtx_[ (i_int-1)%size_x_int ][ j_int ] ;

        k_int++ ;

        population_struct_mtx_[i_int][j_int].interactions_struct[ k_int ] = \
          &population_struct_mtx_[ (i_int+1)%size_x_int ][ j_int ] ;

        k_int++ ;

        population_struct_mtx_[i_int][j_int].interactions_struct[ k_int ] = \
          &population_struct_mtx_[ i_int ][ (size_y_int-1)%size_y_int ] ;  

        k_int++ ;

        population_struct_mtx_[i_int][j_int].interactions_struct[ k_int ] = \
          &population_struct_mtx_[ i_int ][ (size_y_int+1)%size_y_int ] ;

        k_int++ ;
      }   
      else
      {

        population_struct_mtx_[i_int][j_int].interactions_struct[ k_int ] = \
          &population_struct_mtx_[ (i_int-1)%size_x_int ][ j_int ] ;

        k_int++ ;

        population_struct_mtx_[i_int][j_int].interactions_struct[ k_int ] = \
          &population_struct_mtx_[ (i_int+1)%size_x_int ][ j_int ] ;

        k_int++ ;

        population_struct_mtx_[i_int][j_int].interactions_struct[ k_int ] = \
          &population_struct_mtx_[ i_int ][ (j_int-1)%size_y_int ] ;  

        k_int++ ;

        population_struct_mtx_[i_int][j_int].interactions_struct[ k_int ] = \
          &population_struct_mtx_[ i_int ][ (j_int+1)%size_y_int ] ;

        k_int++ ;
      }
    }
  }
}

#endif
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~END