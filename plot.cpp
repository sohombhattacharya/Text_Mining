//Sohom Bhattacharya
//Plot.cpp
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

#include "plot.h"
#include "const.h"

//Pre-condition: value is of type int
//Post-condition: value is of type int
void Plot::setId(int value)
{
	id = value;
}

//Pre-condition: val is of type int
//Post-condition: val is of type int
void Plot::setNumpoints(int val)
{
	numPoints = val;
}

//Pre-condition: xinput is of type string
//Post-condition: xinput is of type string
void Plot::setXlabelstring(string xinput)
{
	xlabel = xinput;
}

//Pre-condition: yinput is of type string
//Post-condition: yinput is of type string
void Plot::setYlabelstring(string yinput)
{
	ylabel = yinput;
}

//Pre-condition: id is of type int
//Post-condition: id is of type int
int Plot::getId()
{
	return id;
}

//Pre-condition: numPoints is of type int
//Post-condition: numPoints is of type int
int Plot::getNumpoints()
{
	return numPoints;
}

//Pre-condition: xlabel is of type string
//Post-condition: xlabel is of type string
string Plot::getXlabelstring()
{
	return xlabel;
}

//Pre-condition: ylabel is of type string
//Post-condition: ylabel is of type string
string Plot::getYlabelstring()
{
	return ylabel;
}


const  int YPOINTS=100;
const  int XPOINTS= 100;

//Pre-condition: {size != 0}
//Post-condition: {size != 0}
void Plot::plot2D(double x[], double y[], int size)
{

	
	
	//scale y values
	double ymax = y[0]; 
	for (int i = 0; i < size; i++)
	{
		if (ymax < y[i])
			ymax = y[i];
	
	}
	
	if (ymax > 50 && ymax <=500)
	{
		for (int i = 0; i < size; i++)
			y[i] = y[i]/10;
	}

	if (ymax > 500 && ymax <= 5000)
	{
		for (int i = 0; i < size; i++)
			y[i] = y[i]/100;
	}
	
	if (ymax > 5000 && ymax <= 50000)
	{
		for (int i = 0; i < size; i++)
			y[i] = y[i]/1000;
	}

	if(ymax > 50000 && ymax <= 500000)
	{
		for (int i = 0; i < size; i++)
			y[i] = y[i]/10000;
	}
	

	//scale x values
	double xmax = x[0]; 
	for (int i = 0; i < size; i++)
	{
		if (xmax < x[i])
			xmax = x[i];
	
	}
	
	if (xmax > 50 && ymax <=500)
	{
		for (int i = 0; i < size; i++)
			x[i] = x[i]/10;
	}

	if (xmax > 500 && xmax <= 5000)
	{
		for (int i = 0; i < size; i++)
			x[i] = x[i]/100;
	}
	
	if (xmax > 5000 && xmax <= 50000)
	{
		for (int i = 0; i < size; i++)
			x[i] = x[i]/1000;
	}

	if(xmax > 50000 && xmax <= 500000)
	{
		for (int i = 0; i < size; i++)
			x[i] = x[i]/10000;
	}


	char plot[YPOINTS][XPOINTS]; 

	for (int i = 0; i < YPOINTS; i++)
	{ 
		for (int j = 0; j < XPOINTS; j++)
		{
			plot[i][j] = ' ';
		
		}
	}
	
	for (int i = 0; i < YPOINTS; i++)
	{
	plot[i][0] = '|';
	}

	for (int i = 0; i < XPOINTS; i++)
	{
	plot[YPOINTS-1][i] = '_';
	
	}



	for (int i = 0; i < size; i++)
	{
		int xvalue = floor(x[i]);
		int yvalue = floor(y[i]);

		int x = xvalue;
		int y = YPOINTS-yvalue;
		if ( x < XPOINTS && y < YPOINTS  && x >= 0 && y >= 0  )
			plot[y][x] = '*';
		else
			cout << "x, y (" << x << "," <<  y << " ) exceeds plot capacity (50,50) , can not set this point in plot"  << endl;
		

	}




	for (int i = 0; i < YPOINTS; i++)
	{
	
		for (int j = 0; j < XPOINTS; j++)
		{
			cout << plot[i][j];
		}
	    cout << endl;
	
	}


	cout << "Word first line and last line values can be found above the plot" << endl;
	cout << " " << endl;	
	cout << "X VALUES: 0 TO 20" << endl;
	cout << "Y VALUES: 0 TO 100" << endl;
	cout << " " << endl;

	cout << "If words are found on similar numbered lines, only one point will show up" << endl;
	cout << " " << endl;
	cout << "If a list of words have a high difference in their first line counts, some points will not show up on the plot to show relativity" << endl;

}

const int  HIST_X = 100;
const int  HIST_Y = 20;

//Pre-condition: {size != 0}
//Post-condition: {size != 0}
void Plot::histogram(int freq[], int size)
{
   
	char histogram[HIST_Y][HIST_X];

	for (int i = 0; i < HIST_Y; i++)
	{ 
		for (int j = 0; j < HIST_X; j++)
		{
			histogram[i][j] = ' ';
		
		}
	}


	for (int i = 0; i <HIST_Y; i++)
	{
	histogram[i][0] = '|';
	}

	for (int i = 0; i < HIST_X; i++)
	{
	histogram[HIST_Y-1][i] = '_';
	
	}


	double ymax = freq[0]; 
	for (int i = 0; i < size; i++)
	{
		if (ymax < freq[i])
			ymax = freq[i];
	
	}

	if (ymax > 20 && ymax <=200)
	{
		for (int i = 0; i < size; i++)
			freq[i] = freq[i]/10;
	}

	if (ymax > 200 && ymax <= 2000)
	{
		for (int i = 0; i < size; i++)
			freq[i] = freq[i]/100;
	}
	
	if (ymax > 2000 && ymax <= 20000)
	{
		for (int i = 0; i < size; i++)
			freq[i] = freq[i]/1000;
	}

	if(ymax > 20000 && ymax <= 200000)
	{
		for (int i = 0; i < size; i++)
			freq[i] = freq[i]/10000;
	}

	if(ymax > 200000 && ymax <= 2000000)
	{
		for (int i = 0; i < size; i++)
			freq[i] = freq[i]/100000;
	}

	for (int i = 0; i < size; i++)
	{
		int height = freq[i];

		for (int j = 0; j < height; j++)
		{
			int x = HIST_Y - 1-j;
			int y = i+1;
			if ( x < HIST_Y && y < HIST_X && x >=0 && y >= 0 ) 
				histogram[x][y] = '*';
			else
				cout << " " << endl;
		}
	}

	for (int i = 0; i < HIST_Y; i++)
	{
	
		for (int j = 0; j < HIST_X; j++)
		{
			cout << histogram[i][j];
		}
	cout << endl;
	
	}
	
	cout << " " << endl;	
	cout << "Y VALUES: 0 TO 20" << endl;
	cout << "X VALUES: 0 TO 100" << endl;
	cout << " " << endl;

	cout << "In certain situation due to scaling, extremely low frequencies, relative to the maximum frequency, will not show up in the histogram because they will be scaled to 0" << endl;


}

//Pre-condition: {i == 0}
//Post-condition: {i < n}
void Plot::createFirstMarks(int n, int m, char** a)
{
 
  for(int i = 0 ; i < n; i++)
		for(int j = 0 ; j < m; j++)
			a[i][j] = ' ';
}

//Pre-condition: {i == 0}
//Post-condition: {i < h}
void Plot::mark(int m, int h, char** a)
{
  
  for(int i = 0; i < h; i++)
      a[m][i] = 'l';
}

//Pre-condition: {m == (l+r)/2}
//Post-condition: {m == (l+r)/2}
void Plot::ruler(int l, int r, int h, char** a)
{
  int m = (l+r)/2;
  if(h>0)
    {
      ruler(l, m, h-1, a);
      mark(m, h, a);
      ruler(m, r, h-1, a);
    }
}

//Pre-condition: {i == 0} 
//Post-condition: {i < n}
void Plot::printLeftSideRuler(int n, int h, char** a) // prints in columns
{
  
  for(int i=0; i<n; i++)
    {
      for(int j = 0; j < h; j++)
	  cout << a[i][j];

      cout << "\n";
    }
}

//Pre-condition: {i = h-1}
//Post-condition: {i > -1}
void Plot::printRightSideRuler(int n, int h, char** a) // prints in rows 
{
 
  for(int i = h-1 ; i > -1; i--)
    {
      for(int j = 0 ; j < n; j++)
	  cout << a[j][i];
	 
      cout << "\n";
    }
}



