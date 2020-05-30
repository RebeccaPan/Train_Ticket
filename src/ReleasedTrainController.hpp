#ifndef RELEASED_TRAIN_CONTROLLER_HPP
#define RELEASED_TRAIN_CONTROLLER_HPP

#include <fstream>
#include "Date.hpp"

class Interface;

class ReleasedTrainController {
public:
	std::fstream ticket_file;
	std::fstream que_btree_file;
	std::fstream que_info_file;
	Interface *interface;
	
	void release_train( const char train_id[] );
	void query_train( const char train_id[], Date date );
	void modify_ticket( const char train_id[],
						Date date,
						const char from[],
						const char to[],
						int num ); // positive for increasing and vice versa
	void add_order( const char train_id[],
					Date date,
					const char username[],
					int order_id );
	void delete_order( const char train_id[],
					   Date date,
					   const char username[],
					   int order_id,
					   int buy_time = -1 );
	void adjust_order( const char train_id[],
					   Date date );
	int query_ticket( const char train_id[],
					  Date date,
					  const char from[],
					  const char to[] );
	
	void load( Interface *ifs );
	void save();
};

#endif // RELEASED_TRAIN_CONTROLLER_HPP
