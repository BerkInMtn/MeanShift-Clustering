#include <iostream>
#include "Node.h"
#include "Graph.h"
#include "Clustering.h"
#include "Edge.h"
#include "MeanShift.h"
//#include "matplotlibcpp.h"
	

#include <iostream>
using namespace std;


int main(){

	MeanShift m1("/home/brkn/Desktop/oop_project/data/20.txt");
	m1.readTxt_File();
	m1.print();
	m1.meanShift(16380.0);
	m1.buildCluster();

	cout << "Number of clusters: " << m1.getClusters().size() << endl;
	m1.writeTxt_File();
	
	m1.plotCluster();
	


	return 0;
}