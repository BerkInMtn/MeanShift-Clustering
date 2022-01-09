#ifndef MEANSHIFT_H
#define MEANSHIFT_H

#include <iostream>
#include "Clustering.h"
#include "Node.h"
#include <string>

#define NUM_ITERATIONS 10

using namespace std;

/**
 * Meanshift class to apply meanshift clustering approaches. Meanshift class inherits
 * general clustering methods from Clustering class. Original points are the input for 
 * this class and after process shifted points are initialize to Clustering object attributes.
 */
class MeanShift : public Clustering
{

public:

	/// Constructor: Inherits from Clustering class sends the directory of input data.
	MeanShift(std::string dir = "Data not found...");
	/// Main funciton for meanshift process. Bandwidth as an input for that function, we can define the bandwidth as radius for the searching area.	
	void meanShift(double);
	/// shiftNode functions is the utility funtions for the meanshift process. Every nodes after calculation specify a total weight for itself.
	Node shiftNode(const Node&, const std::vector<Node> &, double);
	/// Destructor
	~MeanShift();
};

#endif