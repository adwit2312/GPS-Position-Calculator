#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


typedef struct theUser
{
    double latitude, longitude, altitude, time;
    char name[40];
}user_t;
typedef struct distanceToUser {
    double distance;
    char name[40];
} fromUser_t;

user_t theUser(double, double, double, double, char *);
void scan_user(user_t *);
void readFile(char *);
int searchesOtherPpl(char[]);
void searchesOtherData(char[], int, user_t[]);
void calcDistance(user_t, int, user_t[], fromUser_t[]);
user_t closestPerson(int, user_t[], fromUser_t[]);



user_t closestPerson(int uAmounts, user_t oUsers[uAmounts], fromUser_t oDistances[uAmounts])
{
    int cP = 0; // place holder number

    for (int i = 0; i < uAmounts; i++){      // checks if a distance is smaller than the smallest if it is it becomes the smallest
        if (oDistances[i].distance < oDistances[cP].distance){
            cP = i;
        }
    }
    printf("\n %s is the closest with a distance of %lf", oDistances[cP].name,oDistances[cP].distance);
    return oUsers[cP];
}


void calcDistance(user_t uMain, int ursAmounts, user_t oUsers[ursAmounts], fromUser_t oDistance[ursAmounts]) 
{
    double latitude = uMain.latitude, longitude = uMain.longitude, altitude = uMain.altitude; // sets up variables
    for (int i = 0; i < ursAmounts; i++) // calculates
    {
        oDistance[i].distance = sqrt(pow((latitude - oUsers[i].latitude), 2) + pow((longitude - oUsers[i].longitude), 2) + pow((altitude - oUsers[i].altitude), 2));
        strcpy(oDistance[i].name, oUsers[i].name); //long distance calculations gets stored in a structure with their name
    }
}

void scan_user(user_t *userScanned){
    double latitude, longitude, altitude, time;
    char name[40];

     printf("\n Your name?: ");
    scanf("%s", &name);
    printf("Enter your Latitude, Longitude, Altitude, and Time in this exact order : \n");
    scanf("\n%lf\n%lf\n%lf\n%lf", &latitude, &longitude, &altitude, &time); // get the user info
    printf("%s :\n%lf\n%lf\n%lf\n%lf nanoseconds are the inputed values.\n", name, latitude, longitude, altitude, time); // restated the users info
    *userScanned = theUser(latitude, longitude, altitude, time, name); // fills the structure
}


user_t theUser(double latitude, double longitude, double altitude, double time, char *name) //makes stuff into structures
{
user_t uTemporary = {latitude, longitude, altitude, time, "\0"};
strcpy(uTemporary.name, name);
return uTemporary;
}

void readFile(char *fileName)
{
    printf("What is the name of the file? :\n");
    fgets(fileName, 40, stdin); //gives file name with enter at the end
    fileName[strlen(fileName) - 1] = '\0'; // gets rid of the enter at the end
}

int main (void) {

    user_t uScanned, uClosest;
    int uAmounts;
    char fileName[40] = {'0'};

    readFile(fileName);

    uAmounts = searchesOtherPpl(fileName);

    scan_user(&uScanned);

  user_t uOthers[uAmounts];

  searchesOtherData(fileName, uAmounts, uOthers);

  for (int i = 0; i < uAmounts; i++)
    {
      printf("\nName: %s\nTime: %.01f\nLat: %1g\nLong: %1g\nAlt: %1g\n", uOthers[i].name,uOthers[i].time,uOthers[i].latitude,uOthers[i].longitude,uOthers[i].altitude);
      
    }

  fromUser_t oDistances[uAmounts];

  calcDistance(uScanned, uAmounts, uOthers, oDistances);

  uClosest = closestPerson(uAmounts, uOthers, oDistances);
  
}


int searchesOtherPpl(char address[40]) {
    FILE *fileP = NULL;
    char cTemporary;
    int uAmount = 0;
    fileP = fopen(address, "r"); // opens the file
    if (fileP == NULL)
    {
        printf("\n You misspelled the file name\n");
        exit(1);
    }
    else
    {
        cTemporary = fgetc(fileP); // grab the first char

        while ((cTemporary > 47 && cTemporary < 58)) //scans the whole line to find the value does it in ascii
        {
            uAmount += (cTemporary - '0'); // turn the ascii to normal digits
            uAmount *= 10; // moves up one decimal place
            cTemporary = fgetc(fileP);
        }
        uAmount /= 10; //moves the decimal place back
    }

    fclose(fileP); // closes the file
    return uAmount;

}

void searchesOtherData(char storage[40], int uAmounts, user_t other_users[uAmounts]){
     FILE *fileP = NULL; // makes the file pointer
    char name[40];                                          //this one too
    double time, latitude, longitude, altitude; // variables for filling in data^
        fileP = fopen(storage, "r"); //opens file
        fscanf(fileP, "%*s"); // skips the first line
        for (int i = 0; i < uAmounts; i++)  //
        {
            fscanf(fileP, "%s", name); //fills in their info
            fscanf(fileP, "%lf", &time);
            fscanf(fileP, "%lf", &latitude);
            fscanf(fileP, "%lf", &longitude);
            fscanf(fileP, "%lf", &altitude);

            other_users[i] = theUser(latitude, longitude, altitude, time, name); //puts their info in an array
        }
    fclose(fileP); //closes file

}
