#include <unistd.h>
#include <iostream>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <thread>
#include <chrono>
#include <fstream>
#include <string>


using namespace std;

char **sir = (char **)malloc(10 * sizeof(char *));
time_t timesir[10];

int change = 0;
int check = 0;

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

void dividerestore(string dir, string fullnume)
{
  
  string fout (dir);
  fout += "bufferdir/";

  int i = 0;
  int length = 0;
  for(i = fullnume.length() - 1; i >= 0; i--)
    if(fullnume[i] == '.')
      break;
    cout << i << " " << fullnume.length() - 1 << '\n';
  char c_nume[20];
  char c_ext[10];
  length = fullnume.copy(c_nume,i,0);
  c_nume[length] = '\0';
  length = fullnume.copy(c_ext,fullnume.length() - 1,i);
  c_ext[length] = '\0';
  cout << c_nume << c_ext << '\n';
  string nume(c_nume);
  string ext(c_ext);

  ifstream finfile (dir + fullnume,ifstream::binary);
  ofstream foutfile (fout + nume + "_final" + ext,ofstream::binary);

  long size = 1000;

  i=0;

  while(finfile.eof() == false)
  {

  ofstream outfile (fout + nume + "_" + to_string(i) + ".txt",ofstream::binary);
  char* buffer = new char[size];

  finfile.read (buffer,size);

  outfile.write (buffer,size);

  delete[] buffer;

  outfile.close();

  i++;

  }
  int sup = i;
  i = 0;
  while(i<sup)
  {

  ifstream infile (fout + nume + "_" + to_string(i) + ".txt",ofstream::binary);
  char* buffer = new char[size];

  infile.read (buffer,size);

  foutfile.write (buffer,size);

  delete[] buffer;

  infile.close();

  i++;
  
  }

  foutfile.close();
  finfile.close();

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

	    	//cout << nm << ' ';

	    	if ( check == 0 )
	    	{
	            	if (mkdir("bufferdir", 0777) == -1)
	            	{
        			cerr << "Error :  " << strerror(errno) << endl;
  		    	}
    		    	else
    		    	{
    		    		cout << "Directory created" << endl;
    		    	}
       			check = 1;
	    	}
	    	else if (strcmp(nm, "bufferdir") == 0)
	            	continue;

	    	int var = find_file(nm);
	    	
		if(var)
		{
			time_t timer;
			time(&timer);
			//check time(nm);

			if( difftime(timer,timesir[var-1]) >= 15 ) //time(nm)>10s
			{ 
				//transfera fisieru in 1KB
				string st_dir(dir);
				string st_nm(nm);
				dividerestore(st_dir,st_nm);
				printf("\n%s | curent poz in sir:%d max poz:%d\n", nm, var-1, change);
				
				if( remove(nm) != 0 )
    					perror( "Error deleting file" );
  				else
    					puts( "File successfully deleted" );

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
	//cout << '\n';
	closedir(dirp);
	
	return 0;
}

int main()
{
	
	while(1)
	{
		this_thread::sleep_for (chrono::milliseconds(500));
		check_dir("/home/ban/Desktop/pics/");
		
	}
	return(0);
}
