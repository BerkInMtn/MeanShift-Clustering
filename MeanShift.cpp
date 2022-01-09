#include "MeanShift.h"
#include <iostream>
#include "Clustering.h"
#include "Edge.h"
#include "Node.h"
#include <string>

using namespace std;

// Constructor
MeanShift::MeanShift(std::string dir)
    :Clustering(dir)    // Member initializer to give the directory Clustering object.
{
    cout << " has begun for MeanShift" << endl;
}

void MeanShift::meanShift(double bandwidth)
{
    // Iterate according to iteration number.
    for (int j = 0; j < NUM_ITERATIONS; j++) {
        // Iterate for every loaded nodes.
        for (int i = 0; i < loaded_data.size(); i++) {
            // Send every node to process with all the other nodes.
            Node newPoint = shiftNode(shifted_points[i], loaded_data, bandwidth);
            // Initialize the returned node as a shifted pointed to the Clustering object.
            shifted_points[i] = newPoint;
        }
    }
}

Node MeanShift::shiftNode(const Node& oldPoint, const std::vector<Node>& allPoints, double bandwidth)
{
    // Create an empty Node object.
    Node shiftedPoint(0.0, 0.0);
    double totalWeight = 0.0;

    // Iterate through every node for specific Node object.
    for (unsigned int i = 0; i < allPoints.size(); i++){
        // An empty edge object to get relations between every points .
        Edge* temp_edge = new Edge(oldPoint, allPoints[i]);
        shiftedPoint += allPoints[i] * temp_edge->gaussianKernel(bandwidth);
        totalWeight += temp_edge->gaussianKernel(bandwidth);
        // Destroy the temporary Edge object.
        delete temp_edge;
    }
    return shiftedPoint /= totalWeight;
}

// Destructor.
MeanShift::~MeanShift(){
    cout << "MeanShift process is completed..." << endl;
}