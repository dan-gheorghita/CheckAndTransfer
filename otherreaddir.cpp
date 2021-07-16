#include <unistd.h>
#include <iostream>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <cstdlib>
#include <ctime>
#include <thread>
#include <chrono>


using namespace std;

char **sir = (char **)malloc(10 * sizeof(char *));
time_t timesir[10];

int change = 0;

int find_file(const char *nm)
{
        int i;
        for(i = 0; i < change ; i++)
                        if( strcmp(*(sir +i),nm) == NULL )
                        {
                        //cout << nm << ' ';
                        return i+1;
                        }
        return 0;
                        
}

void stergere(int k)
{
	int i;
	for(i = k; i < change - 1; i++)
	{
		strcpy(*(sir + i),*(sir + i+1));
		timesir[i] = timesir[i+1];
	}
	
	free(*(sir + change - 1));
}


int check_dir(const char *dir)
{
 	

	if (chdir(dir) == -1){
		perror(dir);
		return 1;
	}

	DIR *dirp = opendir(".");
	
	struct dirent *dent;

	while( (dent = readdir(dirp)) != NULL )
	{
		char *nm = dent->d_name;

		if (strcmp(nm, ".") == 0 || strcmp(nm, "..") == 0)
	            continue;

	    	int var = find_file(nm);
	    	
		if(var)
		{
			time_t timer;
			time(&timer);
			//check time(nm);

			if( difftime(timer,timesir[var-1]) >= 10 ) //time(nm)>10s
			{ 
				//transfera fisieru in 1KB
				printf("%s %d %d\n", nm, var-1, change);
				stergere(var-1);
				change--;
			}
			
			
			
			
		}
		else
		{
			cout << nm << ' ';
			//*(sir + change) = nm;
			*(sir + change) = (char *)malloc(strlen(nm) + 1);
			strcpy(*(sir + change),(char *)nm);

			//set time(nm);
			timesir[change] = time(NULL);

			//timesir = (time_t *) realloc (timesir, change * sizeof(time_t));
			//*(timesir + change) = time(NULL);
			change++;
		}
		
	}
	cout << '\n';
	closedir(dirp);
	
	return 0;
}

int main()
{
	
	while(1)
	{
		this_thread::sleep_for (chrono::milliseconds(500));
		check_dir("/home/ban/Desktop/pics");
		
	}
	return(0);
}
