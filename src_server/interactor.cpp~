#include <bits/stdc++.h>
#include <unistd.h>
#include <signal.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>

using namespace std;
int _w;

void run_server() {
	int out = open("server2main", O_WRONLY);
	int in = open("main2server", O_RDONLY);
	
	dup2(in, 0);
	dup2(out, 1);
	close(in);
	close(out);
	
	execl("server", "server", nullptr);
}

void run_main() {
	int in = open("server2main", O_RDONLY);
	int out = open("main2server", O_WRONLY);
	
	dup2(in, 0);
	dup2(out, 1);
	close(in);
	close(out);
	
	execl("main", "main", nullptr);
}

int main() {
	mkfifo("server2main", 0644);
	mkfifo("main2server", 0644);
	
	pid_t pid_server, pid_main;
	
	pid_server = fork();
	if( pid_server == 0 ) {
		run_server();
		return 0;
	}
	
	pid_main = fork();
	if( pid_main == 0 ) {
		run_main();
		return 0;
	}
	
	waitpid(pid_server, nullptr, 0);
	waitpid(pid_main, nullptr, 0);
	
	return 0;
}
