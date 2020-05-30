#ifndef TRAIN_HPP
#define TRAIN_HPP

#include "const_variable.hpp"
#include "Date.hpp"
#include "Time.hpp"

class Train {
public:
	char train_id[TRAIN_ID_LEN];
	int station_num;
	int seat_num;
	char stations[STATION_NUM_MAX][STATION_LEN];
	int prices[STATION_NUM_MAX];
	Time start_time;
	int travel_times[STATION_NUM_MAX];
	int stopover_times[STATION_NUM_MAX];
	Date sale_date_begin, sale_date_end;
	char type;
	bool deleted;
	int create_time;
};

#endif // TRAIN_HPP
