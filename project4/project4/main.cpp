//
//  main.cpp
//  project4
//
//  Created by Taylor Mansfield on 10/28/12.
//  Copyright (c) 2012 Taylor Mansfield. All rights reserved.
//

#include <iostream>
#include "sim_engine.h"
#include "StatModule.h"


int main(int argc, const char * argv[])
{
 StatModule *stat_mod = new StatModule();
 SimEngine sim_eng(stat_mod, 
	p_jobs_per_cycle_distribution,
	double p_service_time_distribution,
	double p_job_id_distribution ,
	double total_time);
 sim_eng.Sim();
 stat_mod.printstats();
}

