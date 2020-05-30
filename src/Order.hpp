#ifndef ORDER_HPP
#define ORDER_HPP

#include "const_variable.hpp"
#include "Date.hpp"

class Order {
public:
	char username[USERNAME_LEN];
	int order_id;
	int status;
	char train_id[TRAIN_ID_LEN];
	char from[STATION_LEN];
    char to[STATION_LEN];
	Date sale_date;
	long long price;
	int num;
	int buy_time;
};

#endif // ORDER_HPP
