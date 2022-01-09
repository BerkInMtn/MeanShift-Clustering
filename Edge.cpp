#include <iostream>

#include "Edge.h"
#include <math.h>

using namespace std;	

// Consturctor
Edge::Edge(const Node& P1, const Node& P2)
	:p1(P1),
	p2(P2)
{
	//cout << "Edge Constructor" << endl;
}

// Calculates and returns euclidean distance between two Node objects in type of double.
double Edge::euclideanDistance(void)
{
	double a = pow((p1.getX() - p2.getX()), 2);
	double b = pow((p1.getY() - p2.getY()), 2);

	return sqrt(a + b);
}
// Calculates and returns gaussian kernel between two Node objects in type of double.
double Edge::gaussianKernel(double bandwidth)
{
	return std::exp(-powf(euclideanDistance(), 2.0) / (2.0 * powf(bandwidth, 2)));
}

// Returns first Node as Parent node.
Node Edge::getParent(void) const
{
	return p1;
}
// Returns second Node as Child node.
Node Edge::getChild(void) const
{
	return p2;
}
// Destructor
Edge::~Edge()
{
	//cout << "Edge Deconstructor" << endl;
}