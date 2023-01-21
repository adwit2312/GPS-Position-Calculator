# GPS-Position-Calculator
GPS Position Calculation in C

INPUT:

When running the program, it will ask the user to input the specific file they have that will be used to read different users' position in Latitude, Longitude, Altitude and Time. The user should input only a file with extension .txt.

OUTPUT:

Example of the program:

The program will first prompt the user to enter the filename by saying "What is the name of the file? :". After inputting the filename with extension .txt, the program will continue with asking the user's name as "Your name?: ". After inputting the name, it will prompt the user to enter their GPS position coordinates in latitude, longitude, altitude and time. After the user inputs their specific coordinates, this is the result it will show this as an example:

Adwit :
1000013.000000
1543.210000
2503.020000
155.300000 nanoseconds are the inputed values.

Name: Zac
Time: 1000013.0
Lat: 1543.21
Long: 2503.02
Alt: 155.3

Name: Lise
Time: 1000015.0
Lat: 2501.87
Long: 1100.21
Alt: 266.3

Name: Hermanus
Time: 1000014.0
Lat: 1541.54
Long: 2470.33
Alt: 153.92

 Lise is the closest with a distance of 997513.736065


This is an example program.

If the user enters an incorrect filename type which is not .txt, it will show a result saying: 

"You misspelled the file name"
