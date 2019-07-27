#ifndef AGENT_H
#define AGENT_H

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~LIBRARY

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "input_values.h"

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~STRUCT

typedef struct agents
{

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Profile Related

  int uid_int ;                                                                 // Id of the agent
  int age_int ;                                                                 // Age of the agent
  int gender_int ;                                                              // 0 = Male / 1 = Female 
  int vaccination_bool ;                                                        // 0 = No / 1 = Yes
  struct agents *interactions_struct[ number_of_interactions_int ] ;  	        // array of pointers to interacting agents

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Disease Related

  int health_int ;                                                              // 0 = susceptible / 1 = infected / 2 = recovered
  int next_health_int ;                                                         // 1 = infected / 2 = recovered Related with "time_on_health_state_int"
  int time_on_health_state_int ;                                                // Time the agent take to change health state

} agents ;

#endif

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~END