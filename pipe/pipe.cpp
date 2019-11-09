#include<iostream>
#include<unistd.h>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<sys/types.h>
#include<sys/wait.h>
using namespace std;

int main()
{
	int fd[2]; // fd[0]读管道	fd[1]写管道
	int pfd = pipe(fd); // 创建管道
	pid_t pid = fork();
	if (pid > 0)
	{
		// 父进程读子进程的数据
		char c[1024] = {0}; int ret;
		wait(NULL);
		read(fd[0], c, sizeof(c));
		cout << c << endl;

	}
	else if (pid == 0)
	{
		// 子进程写给父进程数据
		char buf[1024] = "Hello Wprld!!!";
		write(fd[1], buf, strlen(buf));
	}
	else
		perror("pipe");
	return 0;
}