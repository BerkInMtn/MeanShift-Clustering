#ifndef CLUSTERING_H
#define CLUSTERING_H

#include "Node.h"
#include "Graph.h"
#include "gnuplot.h"

#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <fstream>
#include <stdio.h>


using namespace std;

#define ClusterEps 0.4

/**
 * Clustering class for classical manupliation about input, output and results. Getting inputs
 * from the system printing current cluster and plotting the colored sheme of different
 * clusters.
*/

class Clustering{

public:

	/// Constructor: initizlize the data directory to get input coordinates.
	Clustering(std::string dir = "Data not found...");
	/// Reads the 2D data coordinates from .txt files and initialize them to the loaded points and shifted points.
	void readTxt_File(void);
	/// Prints the input data with original coordinates.
	void print(void) const;
	/// After meanshift process this function arranges the original points for the different clusters by using shifted point informations.
	void buildCluster(void);
	/// Return the number of different clusters.
	int getNumClusters(void);
	/// Return a list which stores the different clusters with their coordinates.
	list<Graph> getClusters(void) const;
	

	/// To plot the graph first we should write resultant clusters into a txt file. This funtion have to use before plot execution.
	void writeTxt_File(void);
	/// To plot the diagram according results. This function reads the information from the result folder cluster by cluster.
	void plotCluster(void);

protected:

	/// Original input data.
	std::vector <Node> loaded_data;
	/// Proccessed data after meanshift functions.
	std::vector <Node> shifted_points;

private:

	/// Data directory for input dataset.
	const std::string data_dir;
	/// To store the different clusters in a list.
	list<Graph> clusters;

};

#endif