//generate test csv with random server incidents

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


 
int main() {
  int start_date, end_date, duration_limit, id_limit, rows, datediff, c, incidentnum, randdate, outagedur, id;
  rows=250000; //how many rows to generate
  start_date=1117598400; //start date
  end_date=1388534400; //end date
  datediff=end_date-start_date;
  duration_limit=300; //maximum incident length in seconds
  id_limit=50; //how many servers
  struct tm * ts;
  char       buf[80]; //for human time
  char *strs[17] = {"CyberAttack", "CyberAttack", "Outage", "Outage", "Outage", "Maintenance", "Maintenance", "Maintenance", "Maintenance", "Maintenance", "Maintenance", "Maintenance", "Maintenance", "Maintenance", "Maintenance", "Maintenance", "Power"};

  //seed random number 
  srand(time(NULL));


  //header
  //printf("ServerID,IncidentType,DateTime,EpochTime,OutageDuration_Min");
 
  for (c = 1; c <= rows; c++) {

    id = rand() % id_limit+1;
    printf("%i,", id);
    incidentnum = rand() % 17;
    printf("%s,", strs[incidentnum]);

    randdate = rand() % datediff + start_date;
    time_t epoch_time_as_time_t = randdate;
    ts = localtime(&epoch_time_as_time_t);
    //oracle     strftime(buf, sizeof(buf), "%d/%b/%Y %I:%M:%S %p", ts);
    strftime(buf, sizeof(buf), "%Y-%m-%d %H:%M:%S", ts);
    printf("%s,", buf);  
    printf("%i,", randdate);
    
    outagedur = rand() % duration_limit+1;
    printf("%i\n", outagedur);

  }
 
  return 0;
}
