#ifndef USER_HPP
#define USER_HPP

#include "const_variable.hpp"
#include "Order.hpp"

class User {
public:
	char username[USERNAME_LEN];
	char password[PASSWORD_LEN];
	char name[NAME_LEN];
	char mail_addr[MAIL_ADDR_LEN];
	int privilege;
	int create_time;
	int order_cnt;
	int is_login;
};

#endif // USER_HPP
