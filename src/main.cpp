#include "includes.hpp"

class UnitTest {
public:
	void test_file_operator() {
		using std::fstream;
		using std::cout;
		using std::endl;
		using std::pair;
		system("rm test_file");
		assert( FileOperator().create_file("test_file") );
		fstream test_file("test_file");
		pair<int,double> pr[10];
		for( int i = 0; i < 10; ++i ) {
			pr[i].first = 1 << i;
			pr[i].second = exp(i);
		}
		FileOperator().write( test_file, sizeof(pair<int,double>) * 5, pr, 5 );
		test_file.close();
		assert( FileOperator().create_file("test_file") == false );
		test_file.open("test_file");
		pair<int,double> tmp;
		FileOperator().read( test_file, sizeof(pair<int,double>) * 4, &tmp, 1 );
		cout << tmp.first << endl << tmp.second << endl;
		FileOperator().read( test_file, sizeof(pair<int,double>) * 7, &tmp, 1 );
		cout << tmp.first << endl << tmp.second << endl;
		int pos;
		cout << (pos = FileOperator().write( test_file, -1, pr+5, 5 )) << endl;
		FileOperator().read( test_file, int(pos + sizeof(pair<int,double>) * 3), &tmp, 1 );
		cout << tmp.first << endl << tmp.second << endl;
		test_file.close();
	}
	
	int split( std::string str, char ch, std::string *&ans ) {
		if( ch != ' ' ) {
			int cnt = 1;
			for( int i = 0; i < (int)str.length(); ++i )
				if( str[i] == ch )
					++cnt;
			ans = new std::string[cnt];
			int now = 0;
			for( int i = 0; i < (int)str.length(); ++i ) {
				if( str[i] == ch ) {
					++now;
				} else {
					ans[now].push_back( str[i] );
				}
			}
			assert( now == cnt-1 );
			return cnt;
		} else { // ch == ' '
			int cnt = 0;
			std::stringstream ss(str);
			std::string tmp;
			while( ss >> tmp ) ++cnt;
			ans = new std::string[cnt];
			ss = std::stringstream(str);
			for( int i = 0; i < cnt; ++i )
				ss >> ans[i];
			assert( bool(ss >> tmp) == false );
			return cnt;
		}
	}

	int read_num( std::string str ) {
		int x = 0;
		for( int i = 0; i < (int)str.length(); ++i )
			x = x * 10 + str[i] - '0';
		return x;
	}

	Time read_time( std::string str ) {
		int hour = read_num( str.substr(0, 2) );
		int minute = read_num( str.substr(3, 2) );
		return Time( Date(), hour, minute );
	}

	Date read_date( std::string str ) {
		int month = read_num( str.substr(0, 2) );
		int day = read_num( str.substr(3, 2) );
		return Date(2020, month, day);
	}
	
	void test_interface() {
		using std::cin;
		using std::cout;
		using std::endl;
		
		std::string cmd;
		while( isspace( cin.peek() ) )
			cin.ignore();
		getline(cin, cmd);
		
		std::string *argv = nullptr;
		int argc = split(cmd, ' ', argv);
	
		std::string train_id;
		int station_num;
		int seat_num;
		std::string stations;
		std::string prices;
		Time start_time;
		std::string travel_times;
		std::string stopover_times;
		std::string sale_date;
		char type;
	
		for( int i = 1; i < argc; i += 2 ) {
			if( argv[i] == "-i" ) {
				train_id = argv[i+1];
			} else if( argv[i] == "-n" ) {
				station_num = read_num( argv[i+1] );
			} else if( argv[i] == "-m" ) {
				seat_num = read_num( argv[i+1] );
			} else if( argv[i] == "-s" ) {
				stations = argv[i+1];
			} else if( argv[i] == "-p" ) {
				prices = argv[i+1];
			} else if( argv[i] == "-x" ) {
				start_time = read_time( argv[i+1] );
			} else if( argv[i] == "-t" ) {
				travel_times = argv[i+1];
			} else if( argv[i] == "-o" ) {
				stopover_times = argv[i+1];
			} else if( argv[i] == "-d" ) {
				sale_date = argv[i+1];
			} else if( argv[i] == "-y" ) {
				type = argv[i+1][0];
			} else {
				assert(0);
			}
		}
	
		char stations_real[STATION_NUM_MAX][STATION_LEN];
		int prices_real[STATION_NUM_MAX];
		int travel_times_real[STATION_NUM_MAX];
		int stopover_times_real[STATION_NUM_MAX];
		Date sale_date_begin;
		Date sale_date_end;
	
		sale_date_begin = read_date( sale_date.substr(0, 5) );
		sale_date_end = read_date( sale_date.substr(6, 5) );
	
		std::string *tmp = nullptr;
		int tn;
	
		tn = split( prices, '|', tmp );
		assert( tn == station_num - 1 );
		for( int i = 0; i < tn; ++i )
			prices_real[i] = read_num( tmp[i] );
		delete []tmp;
	
		tn = split( travel_times, '|', tmp );
		assert( tn == station_num - 1 );
		for( int i = 0; i < tn; ++i )
			travel_times_real[i] = read_num( tmp[i] );
		delete []tmp;
	
		if( station_num > 2 ) {
			tn = split( stopover_times, '|', tmp );
			assert( tn == station_num - 2 );
			for( int i = 0; i < tn; ++i )
				stopover_times_real[i] = read_num( tmp[i] );
			delete []tmp;
		}
	
		tn = split( stations, '|', tmp );
		assert( tn == station_num );
		for( int i = 0; i < tn; ++i )
			strcpy( stations_real[i], tmp[i].c_str() );
		delete []tmp;
		
		cout << train_id.c_str() << endl;
		cout << station_num << endl;
		cout << seat_num << endl;
		for( int i = 0; i < station_num; ++i )
			cout << stations_real[i] << endl;
		for( int i = 0; i < station_num-1; ++i )
			cout << prices_real[i] << endl;
		cout << start_time << endl;
		for( int i = 0; i < station_num-1; ++i )
			cout << travel_times_real[i] << endl;
		for( int i = 0; i < station_num-2; ++i )
			cout << stopover_times_real[i] << endl;
		cout << sale_date_begin << endl;
		cout << sale_date_end << endl;
		cout << type << endl;
	
		delete []argv;
	}
	
	//*
	void test_btree() {
		FileOperator().create_new_file("test_btree");
		FileOperator().create_new_file("test_btree_info");
		
		std::fstream btree_file("test_btree");
		std::fstream info_file("test_btree_info");
		
		assert( btree_file && info_file );
		
		BTree<int,int> btree;
	    
		int *arr = new int[1000000];
		for( int i = 0; i < 1000000; ++i )
			arr[i] = i;
		std::random_shuffle(arr, arr+1000000);
		
		for( int i = 0; i < 1000000; ++i )
			btree.insert( arr[i], arr[i], btree_file, info_file );
		
		for( int i = 0; i < 10; ++i ) {
			int x = rand() % 1000000;
			printf( "query(%d) = %d\n", x, btree.query(x, btree_file, info_file) );
		}
		for( int i = 0; i < 20; ++i ) {
			int x = rand() % 1000000 - 500000;
			printf( "exist(%d) = %d\n", x, (int)btree.exist(x, btree_file) );
		}
		
		for( int i = 0; i < 1000000; ++i )
			btree.insert( arr[i], arr[i] * 10, btree_file, info_file );
		
		for( int i = 0; i < 10; ++i ) {
			int x = rand() % 1000000;
			printf( "query(%d) = %d\n", x, btree.query(x, btree_file, info_file) );
		}
		
		std::pair<int,int> *pr;
		int cnt = btree.query_list(2005, 9005, btree_file, info_file, pr);
		assert( cnt == 9005 - 2005 + 1 );
		for( int i = 0; i < 20; ++i )
			printf( "%d %d\n", pr[i].first, pr[i].second );
		delete []pr;
		
		for( int i = 0; i < 1000000; ++i )
			arr[i] = i;
		
	    for( int i = 0; i < 1000000; ++i ) {
			if( i == 0 || i == 1 ) arr[i] = 1000000;
			else {
				if( arr[i] == 1000000 ) {
					continue;
				} else {
					for( int j = i+i; j < 1000000; j += i )
						arr[j] = 1000000;
				}
			}
		}
		
		for( int i = 0; i < 1000000; ++i )
			if( arr[i] == 1000000 ) arr[i] = i;
			else arr[i] = -1;
		
		std::random_shuffle(arr, arr+1000000);
		for( int i = 0; i < 1000000; ++i )
			btree.remove( arr[i], btree_file );
		
		cnt = btree.query_list(7000, 10007, btree_file, info_file, pr);
		for( int i = 0; i < cnt; ++i )
			printf( "%d %d\n", pr[i].first, pr[i].second );
		delete []pr;
		
		printf( "exist(%d) = %d\n", 998244353, btree.exist(998244353, btree_file) );
		printf( "exist(%d) = %d\n", 2333, btree.exist(2333, btree_file) );
		printf( "exist(%d) = %d\n", 1, btree.exist(1, btree_file) );
		printf( "exist(%d) = %d\n", -1, btree.exist(-1, btree_file) );
		printf( "exist(%d) = %d\n", 10003, btree.exist(10003, btree_file) );
		
		for( int i = 0; i < 1000000; ++i )
			btree.insert( i, i * 10, btree_file, info_file );
		
		cnt = btree.query_list(-1, 1000000, btree_file, info_file, pr);
		assert( cnt == 1000000 );
		for( int i = 0; i < 20; ++i )
			printf( "%d %d\n", pr[1000000-i-1].first, pr[1000000-i-1].second );
		delete []pr;
		
		// delete []arr;
	}
	//*/
};

int main() {
	// UnitTest().test_file_operator();
	// UnitTest().test_interface();
	UnitTest().test_btree();
	/*
	Interface interface;
	interface.start();
	interface.run();
	//*/
	return 0;
}
