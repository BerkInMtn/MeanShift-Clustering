#ifndef GNUPLOT_H
#define GNUPLOT_H

#include <iostream>
#include <string>

using namespace std;

class gnuplot{
public:
	gnuplot();
	~gnuplot();
	void operator()(const string& command);
protected:
	FILE *gnuplotpipe;
};

#endif