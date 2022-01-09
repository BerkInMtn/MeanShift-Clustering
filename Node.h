#ifndef NODE_H
#define NODE_H

#include <string>
#include <iostream>

using namespace std;

/**
 * Stores for every points, X and Y coordinates.
 * 
 */
class Node{

	/// A friend function to use cout object with Node class object directly.
	friend std::ostream &operator<<(std::ostream&, const Node&);
	/// An operator overloading to compare two objects whether they are equal.
    friend bool operator==(const Node&, const Node&);

public:

	/// Constructor to set X and Y coordinates, with default values.
	Node(double X = 0.0, double Y = 0.0);

	/// Sets the x coordinates.
	void setX(double);
	/// Sets the y coordinates.
	void setY(double);

	/// Returns the x coordinates.
	double getX(void) const;
	/// Returns the x coordinates.
	double getY(void) const;
	/// Returns a unique ID for every Node object.
	std::string getID(void) const;

	/// Prints the Node objects in the form of P(x, y).
	void print(void);

	/// An operator overloading to sum two differents Node objects.
	Node &operator+=(const Node &otherNode);

	/// An operator overloading to multiply coordinates with same literal.
    Node operator*(double d) const;

	/// An operator overloading to multiply coordinates with same literal and assign result to a new Node object.
    Node &operator*=(double d);

	/// An operator overloading to divide coordinates with same literal.
    Node operator/(double d) const;

	/// An operator overloading to divide coordinates with same literal and assign result to a new Node object.
    Node &operator/=(double d);

    /// Destructor
    ~Node();

private:
	/// X coordinate data attribute.
	double x;
	/// X coordinate data attribute.
	double y;

	/// Prefix to set a prefix for ID.
	static constexpr const char* prefix= "Node_";
	/// An index to set a prefix for ID.
	int index;
	/// To set index attribute counts the current objects int the program.
	static int count;
};

#endif