#ifndef USER_CONTROLLER_HPP
#define USER_CONTROLLER_HPP

#include "Order.hpp"

class Interface;

class UserController {
public:
	int user_cnt;
	std::fstream btree_file; // updated
	std::fstream info_file; // updated
	Interface *interface;
	
	void add_user( const char cur_username[],
				   const char username[],
				   const char password[],
				   const char name[],
				   const char mail_addr[],
				   int privilege );
	void login( const char username[],
				const char password[] );
	void logout( const char username[] );
	void query_profile( const char cur_username[],
						const char username[] );
	void modify_profile( const char cur_username[],
						 const char username[],
						 const char password[], // empty is NULL
						 const char name[], // empty is NULL
						 const char mail_addr[], // empty is NULL
						 int privilege ); // empty is -1
	void query_order( const char username[] );
	
	void load( Interface *ifs );
	void save();
	
	void modify_order( const char username[], int order_id, Order order );
	Order get_order( const char username[], int order_id );
	void print_profile( const char username[] );
	void print_order( const char username[] );
	void add_order( const char username[], Order order );
};

#endif // USER_CONTROLLER_HPP
