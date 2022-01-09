#include "Clustering.h"
#include "Node.h"
#include "Graph.h"
#include "Edge.h"
#include <vector>
#include <list>
#include <algorithm>
#include <fstream>
#include <iostream>

using namespace std;	

Clustering::Clustering(std::string dir)
	:data_dir(dir)
{
	cout << "Clustering process";
}

void Clustering::writeTxt_File(void)
{
	// to label the results.
	int cluster_id = 0;
	// Iterate over clusters.
	for (auto it = clusters.begin(); it != clusters.end(); ++it)
	{
		// Output file for results.
		ofstream file("result/cls_"+ to_string(cluster_id) +".txt", std::ofstream::out);
		// Nodes for the specific cluster.
		vector <Node> temp = it->getAllNodes();
		// Iterate over all point of current cluster.
		for(auto it = temp.begin(); it != temp.end(); it++){
			// Write the coordinates of the Nodes in to a line.
  			file << to_string(it->getX()) << " " << to_string(it->getY()) << endl;
		}
		// Pass to new cluster
		cluster_id++;
	}
}

void Clustering::readTxt_File(void)
{
	// Input file for input dataset
	ifstream input;
	input.open(data_dir);
	// first element
	double st;
	// second element
	double nd;
	// Iterate through line
	while(input >> st >> nd){
		Node temp(st,nd);
		loaded_data.push_back(temp);
	}
	// Initialize the loaded points to the shifted points to send them into meanshift function
	shifted_points = loaded_data;
}

void Clustering::print(void) const
{
	int size_of_data = loaded_data.size();
	// Iterate over input data.
	for(int i = 0; i<size_of_data; i++){
		cout << loaded_data[i] << endl;
	}
}

void Clustering::buildCluster(void)
{
	// Iterate over input data set
	for(uint32_t i = 0; i < loaded_data.size(); i++){
		// Create an iterator for list of clusters.
		list <Graph>::iterator iter = clusters.begin();
		
		// Check the point is belong to current cluster.
		while(iter != clusters.end()){
			Edge* temp_edge = new Edge(iter->getCentroid(), shifted_points[i]);
			if(temp_edge->euclideanDistance() <= ClusterEps){
				iter->updateCentroid(shifted_points[i]);
				iter->setNewNode(loaded_data[i]);
				break;
			}
			delete temp_edge;
			iter++;
		}

		// It means we should create new cluster for current Node object..
		if(iter == clusters.end()){
			// Initialize the first node as centroid using constructor
			Graph new_cluster(shifted_points[i]);
			// Add the current node the Cluster
			new_cluster.setNewNode(loaded_data[i]);
			// Add the new cluster to the list of clusters
			clusters.push_back(new_cluster);
		}
	}
}


int Clustering::getNumClusters(void)
{
	return clusters.size();
}

list<Graph> Clustering::getClusters(void) const
{
	return clusters;
}

void Clustering::plotCluster(void)
{
	// Iterate over different clusters.
	int num_clusters = getNumClusters()-1;
	// Create a command to compile for GNUPlot.
	string command = "plot \'result/cls_0.txt\' u 1:2 with circles fill solid lc 0 lw 1 notitle";
	gnuplot p;
	p("set terminal wxt");
	p("set style circle radius 300");
	// For every cluster change the color and file name.
	for(int i = num_clusters; i != 0; i--){
		command += ", \'result/cls_"+ to_string(i) +".txt\' u 1:2 with circles fill solid lc "+ to_string(i) +" lw 1 notitle";
	}

	p(command);
}