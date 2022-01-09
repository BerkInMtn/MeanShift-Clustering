#ifndef GRAPH_H
#define GRAPH_H

#include "Edge.h"
#include "Node.h"
#include <vector>

using namespace std;

/**
 * This class objects are created in the buildCluster funciton Clustering class. It stores clusters points and centroid. After
 * building process to obtain the minimum spanning tree uses Kruskal graph algorithm.
*/
class Graph{

public:
	/// Constructor: To initialize the first node of the cluster as centroid.
	explicit Graph(Node&);
	/// Add new node to the cluster.
	void setNewNode(const Node&);
	/// Update the centroid after every new point.
	void updateCentroid(const Node&);

	/// Returns the all nodes for that cluster.
	vector<Node>& getAllNodes(void);
	///	Returns the centroid to use the comparing process in the buildCluster method.
	Node& getCentroid(void);
	/// Returns the number of this cluster.
	int getNumberOfNodes(void) const;

	/// Kruskal algoritm to get minimum spanning tree.
	void Kruskal(void);
	/// A utility function for kruskal algorithm.
	Node findPath(Node);
	/// To store spanning tree edges.
	vector<Edge> getMST(void) const;

private:

	/// To store centroid.
	Node centroid;
	/// To store the nodes for cluster.
	vector <Node> points_of_cluster;
	/// To store the edges of the MST.
	vector <Edge> minimum_spanning_tree;

};

#endif	// GRAPH_H