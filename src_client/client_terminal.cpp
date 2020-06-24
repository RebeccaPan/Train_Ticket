#include <bits/stdc++.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <fcntl.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <sys/shm.h>

using namespace std;
const int PORT = 11031;
int _w;

in_addr_t input_ip() {
	string str;
	in_addr_t ip;
	while(1) {
		cout << "Server IP:" << endl;
		cin >> str;
		ip = inet_addr(str.c_str());
		if( ip == INADDR_NONE ) {
			cout << "你在开玩笑" << endl;
		} else {
			break;
		}
	}
	return ip;
}

int main() {
	int socket_id = socket(AF_INET, SOCK_STREAM, 0);
	
	sockaddr_in ser_addr;
	memset(&ser_addr, 0, sizeof ser_addr);
	ser_addr.sin_family = AF_INET;
	ser_addr.sin_port = htons(PORT);
	ser_addr.sin_addr.s_addr = input_ip();
	
	if( connect(socket_id, reinterpret_cast<sockaddr*>(&ser_addr), sizeof ser_addr) < 0 ) {
		puts("server pigeoned");
		return 0;
	}
	
	while(1) {
		while( isspace( cin.peek() ) )
			cin.ignore();
		string str;
		getline(cin, str);
		
		char buf[1000];
		sprintf(buf, "%s", str.c_str());
		send(socket_id, buf, sizeof buf, 0);
		
		while(1) {
			recv(socket_id, buf, sizeof buf, 0);
			cout << buf << endl;
			if( strcmp(buf, "over") == 0 ) break;
		}
	}
	
	close(socket_id);
	return 0;
}
