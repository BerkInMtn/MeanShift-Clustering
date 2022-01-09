#include "Graph.h"
#include "Edge.h"
#include <iostream>
#include <map>


using namespace std;

// Define a multimap to sort the edges for kruskal algorithm according their weights.
typedef multimap<double, Edge, less<double>> Mdist;

// Constructor: set the centroid
Graph::Graph(Node& first_node)
	:centroid(first_node)
{
}

// Add a new node for cluster.
void Graph::setNewNode(const Node& node)
{
	points_of_cluster.push_back(node);
}

// According to new point update centroid.
void Graph::updateCentroid(const Node& shifted_node)
{
	this->centroid *= points_of_cluster.size();
	this->centroid += shifted_node;
	this->centroid /= points_of_cluster.size() + 1;
}

// Returns all nodes.
vector<Node>& Graph::getAllNodes(void)
{	
	return this->points_of_cluster;
}

// Returns centroid.
Node& Graph::getCentroid(void)
{
	return this->centroid;
}

// Returns the number of the nodes which belongs the this cluster.
int Graph::getNumberOfNodes(void) const
{
	return this->points_of_cluster.size();
}

// Kruskal algorithm to get MST
void Graph::Kruskal(void)
{
	// To store the sorted order the edges according to their weights.
	Mdist sorted_order;
	// Iterate for every relation of nodes eachother
	for(auto it_outer = points_of_cluster.begin(); it_outer != points_of_cluster.end(); it_outer++){
		for(auto it_inner = it_outer+1; it_inner != points_of_cluster.end(); it_inner++){
			// Do not match the same nodes
			if(it_inner == it_outer)
				break;
			Edge tempE(*it_inner, *it_outer);
			// Add all nodes into multimap
			sorted_order.insert(Mdist::value_type(tempE.euclideanDistance(), tempE));
		}
	}

	for(Mdist::const_iterator it = sorted_order.begin(); it!= sorted_order.end(); ++it){
		// send the child point of current edge recursive funtion
		if(!(findPath(it->second.getParent()) == it->second.getParent()))
			minimum_spanning_tree.push_back(it->second);
	}
}

Node Graph::findPath(Node node){
	Node control;
	for(auto it = minimum_spanning_tree.begin(); it != minimum_spanning_tree.end(); it++){
		// To prevent possible loops
		if((*it).getChild() == node)
			control = findPath((*it).getParent());
	}
		// If there is loop
		if(control == node)
			return node;
	// If no loop link
	return control;

}

// Returns the MST edges. 
vector<Edge> Graph::getMST(void) const
{
	return minimum_spanning_tree;
}