const int USERNAME_LEN = 25;
const int PASSWORD_LEN = 35;
const int NAME_LEN = 20;
const int MAIL_ADDR_LEN = 35;
const int TRAIN_ID_LEN = 25;
const int STATION_LEN = 40;
const int STATION_NUM_MAX = 102;
const int DATE_MAX = 100;

class BTree {
public:
	// todo
};

class ReleasedTrainController {
public:
	void release_train( char train_id[] );
	void query_train( char train_id[], Date date );
	void modify_ticket( char train_id[],
						Date date,
						char from[],
						char to[],
						int num ); // positive for increasing and vice versa
	void add_order( char train_id[],
					Date date,
					char username[],
					int order_id );
	void delete_order( char train_id[],
					   Date date,
					   char username[],
					   int order_id );
	void adjust_order( char train_id[],
					   Date date );
};

class ReleasedTrain {
public:
	int ticket[DATE_MAX][STATION_MAX];
};

class TrainTrie {
public:
	void insert_string( char str[], int num );
	int query_string( char str[] );
	
	// todo
};

class TrainController {
public:
	int train_cnt;
	
	void add_train( char train_id[],
					int station_num,
					int seat_num,
					char stations[][STATION_LEN],
					int prices[],
					Time start_time,
					int travel_times[],
					int stopover_times[],
					Date sale_date_begin,
					Date sale_date_end,
					char type );
	void delete_train( char train_id[] );
	
	void load();
	void save();
};

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

class OrderController {
public:
	int order_cnt;
	
	void load();
	void save();
	
	// todo
};

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

class UserTrie {
public:
	void insert_string( char str[], User user );
	User query_string( char str[] );
	
	// todo
};

class UserController {
public:
	int user_cnt;
	
	void add_user( char cur_username[],
				   char username[],
				   char password[],
				   char name[],
				   char mail_addr[],
				   int privilege );
	void login( char username[], char password[] );
	void logout( char username[] );
	void query_profile( char cur_username[], char username[] );
	void modify_profile( char cur_username[],
						 char username[],
						 char password[], // empty is NULL
						 char name[], // empty is NULL
						 char mail_addr[], // empty is NULL
						 int privilege ); // empty is -1
	void query_order( char username[] );
	
	void load();
	void save();
};

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
	
	Order get_order( int order_id );
	void print_profile();
	void print_order();
	void add_order( Order order );
};

class Interface {
public:
	void start();
	void run();
	void exit();
};

int main() {
	Interface interface;
	interface.start();
	interface.run();
	return 0;
}
