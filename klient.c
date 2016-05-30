#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/msg.h>
#include <unistd.h>

int main()
{
	char *data[2];
	char dane[30];
	
	time_t czas;
	czas = time(NULL);
	struct tm *dzien;
	dzien = localtime(&czas);
	
	if ((dzien->tm_wday > 4) || (dzien->tm_wday == 0))
	{
		key_t klucz;
		int ID;
		
		if ((klucz = ftok("./serwer",'b')) == -1)
		{
			perror("ftok");
			exit(1);
		}

		if ((ID = msgget(klucz, 0666)) == -1)
		{
			perror("msgget");
			exit(1);
		}
	
		if (msgrcv (ID, NULL, 30, 1, IPC_NOWAIT) == -1)
		{
			perror("msgrcv");
			exit(1);
		}
	
		data[0]="./verify.sh";
		data[1]=dane;
		execvp (data[0], data);
	}
	else
		printf("Nie ma weekendu, nie ma zabawy");
	
return 0;
}
