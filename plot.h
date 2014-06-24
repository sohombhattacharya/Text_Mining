//Sohom Bhattacharya
//Plot.h
//void setId(int value);--------------------------------> (Checkpoint function) Sets value for id of plot. 
//void setXlabelstring(string xinput);------------------> (Checkpoint function) Sets x label string based on input. 
//void setYlabelstring(string yinput);------------------> (Checkpoint function) Sets y label string based on input. 
//void setNumpoints(int val);---------------------------> (Checkpoint function) Sets value for number of points. 
//void plot2D(double x[], double y[], int size);--------> Prints out a coordinate plane with points based on x and y coordinates given. 
//int getId();------------------------------------------> (Checkpoint function) Returns id value. 
//string getXlabelstring();-----------------------------> (Checkpoint function) Returns x label string. 
//string getYlabelstring();-----------------------------> (Checkpoint function) Returns y label string. 
//int getNumpoints();-----------------------------------> (Checkpoint function) Returns number of points. 
//void histogram(int* freq, int size);------------------> Prints a histogram based on the frequencies given. 
//void createFirstMarks(int n, int m, char** a);--------> Creates a set of marks for a ruler. 
//void mark(int m, int h, char** a);--------------------> Draws a mark based on given location. 
//void ruler(int l, int r, int h, char** a);------------> Draws the entire ruler utilizing mark. 
//void printLeftSideRuler(int n, int h, char** a);------> Draws ruler on the left side of the plot. 
//void printRightSideRuler(int n, int h, char** a);-----> Draws ruler on bottom of the plot. 

#ifndef plots
#define plots
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <fstream>

using namespace std;

class Plot
{

public: 
void setId(int value);
void setXlabelstring(string xinput);
void setYlabelstring(string yinput);
void setNumpoints(int val);
void plot2D(double x[], double y[], int size);
int getId();
string getXlabelstring();
string getYlabelstring();
int getNumpoints();
void histogram(int* freq, int size);
void createFirstMarks(int n, int m, char** a);
void mark(int m, int h, char** a);
void ruler(int l, int r, int h, char** a);
void printLeftSideRuler(int n, int h, char** a);
void printRightSideRuler(int n, int h, char** a);



private: 
int id; 
string xlabel;
string ylabel;
int numPoints;




};
#endif 