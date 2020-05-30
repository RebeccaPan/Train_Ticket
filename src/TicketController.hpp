#ifndef TICKET_CONTROLLER_HPP
#define TICKET_CONTROLLER_HPP

#include <fstream>
#include <string>
#include "Date.hpp"

class Interface;

class TicketController {
public:
	std::fstream btree_file;
	std::fstream info_file;
	Interface *interface;
	
	int query_pass( const char station[], std::string *train_id );
	void query_ticket( const char from[],
					   const char to[],
					   Date date,
					   const char priority[] );
	void query_transfer( const char from[],
						 const char to[],
						 Date date,
						 const char priority[] );
	void buy_ticket( const char username[],
					 const char train_id[],
					 Date date,
					 const char from[],
					 const char to[],
					 int num,
					 bool que );
	void refund_ticket( const char username[],
						int order_id );
	
	void load( Interface *ifs );
	void save();
};

#endif // TICKET_CONTROLLER_HPP
