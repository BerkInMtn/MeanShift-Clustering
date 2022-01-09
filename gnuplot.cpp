#include "gnuplot.h"

gnuplot::gnuplot(){
	gnuplotpipe = popen("gnuplot -persist", "w");
	if(!gnuplotpipe)
		cerr << ("Gnuplot not found !");
}

gnuplot::~gnuplot()
{
	fprintf(gnuplotpipe, "exit\n");
	pclose(gnuplotpipe);
}

void gnuplot::operator()(const string& command)
{
	fprintf(gnuplotpipe, "%s\n", command.c_str());
	fflush(gnuplotpipe);
}