#include <bits/stdc++.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/shm.h>
#include <thread>
#include <vector>

using namespace std;
const int PORT = 11031;
int _w;

int socket_id;
sockaddr_in server_addr;
int connection[10000], ccnt = 0;
socklen_t ser_addr_sz;
bool do_exit = false;

void try_accept() {
	timeval delay_t;
	delay_t.tv_sec = 1;
	delay_t.tv_usec = 0;
	
	while( do_exit == false ) {
		fd_set st;
		FD_ZERO(&st);
		FD_SET(socket_id, &st);
		
		if( select(socket_id+1, &st, nullptr, nullptr, &delay_t) > 0 ) {
			int now = accept(socket_id, reinterpret_cast<sockaddr*>(&server_addr), &ser_addr_sz);
			connection[ccnt] = now;
			++ccnt;
		}
	}
	// puts("try_accept finished");
}

void trans() {
	timeval delay_tm;
	delay_tm.tv_sec = 1;
	delay_tm.tv_usec = 0;
	
	char buf[100000];
	while( do_exit == false ) {
		for( int i = 0; i < ccnt; ++i ) {
			int it = connection[i];
			fd_set st;
			FD_ZERO(&st);
			FD_SET(it, &st);
			if( select(it+1, &st, nullptr, nullptr, &delay_tm) > 0 ) {
				int sz = recv(it, buf, sizeof buf, 0);
				cout << buf << endl;
				do_exit = strcmp(buf, "exit") == 0;
				string send_msg;
				while(1) {
					while( isspace( cin.peek() ) )
						cin.ignore();
					string tmp;
					getline(cin, tmp);
					if( tmp == "over" ) break;
					send_msg += tmp;
					send_msg += "\n";
				}
				send(it, send_msg.c_str(), send_msg.length()+1, 0);
				// cerr << send_msg << endl;
				// cerr << "do_exit = " << do_exit << endl;
				if( do_exit ) break;
			}
		}
	}
	// puts("trans finished");
}

int main() {
	memset(connection, -1, sizeof connection);
	
	socket_id = socket(AF_INET, SOCK_STREAM, 0);
	memset(&server_addr, 0, sizeof server_addr);
	server_addr.sin_family = AF_INET;
	server_addr.sin_port = htons(PORT);
	server_addr.sin_addr.s_addr = INADDR_ANY;
	assert( bind( socket_id, reinterpret_cast<sockaddr*>(&server_addr), sizeof server_addr ) == 0 );
	assert( listen( socket_id, 20 ) == 0 );
	ser_addr_sz = sizeof(server_addr);
	
	thread thr_try_accept(try_accept);
	thread thr_trans(trans);
	thr_try_accept.join();
	thr_trans.join();
	// puts("threads finished");
	for( int i = 0; i < ccnt; ++i )
		close( connection[i] );
	close( socket_id );
	
	return 0;
}
