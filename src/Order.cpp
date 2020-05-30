#include "includes.hpp"

Order::Order(const char _username[],
		  int _order_id,
		  int _status,
		  char _train_id[],
		  char _from[],
		  char _to[],
		  Date _sale_date,
		  long long _price,
		  int _num,
		  int _buy_time):
          order_id(_order_id),
          status(_status),
          price(_price),
          num(_num),
          buy_time(_buy_time) {
    strcmp(username, _username);
    strcmp(train_id, _train_id);
    strcmp(from, _from);
    strcmp(to, _to);
    sale_date = _sale_date; // Warning: no operator= for class Date
}

Order::~Order() {}