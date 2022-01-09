#ifndef EDGE_H
#define EDGE_H

#include "Node.h"

/**
 * Stores two Node objects using compositon principle.
 * Calculates weight and gaussian kernel functionalities, and to use in Kruskal algorithm first Node
 * named as Parent and second is Child Node.
 */
class Edge{

public:

	/// Constructor: Initialize Node objects.
	Edge(const Node&, const Node&);

	///	Returns distance between two Nodes.
	double euclideanDistance(void);
	/// Calculates the gaussian kernel that these two Node create.
	double gaussianKernel(double);

	/// Returns first Node as Parent Node.
	Node getParent(void) const;
	/// Returns second Node as Child Node.
	Node getChild(void) const;

	~Edge();

private:

	/// First Node class object.
	const Node& p1;
	/// Second Node class object.
	const Node& p2;

};

#endif