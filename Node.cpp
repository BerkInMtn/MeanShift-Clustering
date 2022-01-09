#include "Node.h"
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int Node::count = 0;

// Constructor
Node::Node(double X, double Y)
	:index(count)
{
	setX(X);
	setY(Y);
	count++;
}
// Set Functions
void Node::setX(double X)
{
	x = X;
}
void Node::setY(double Y)
{
	y = Y;
}

// Get Functions
double Node::getX(void) const
{
	return x;
}
double Node::getY(void) const
{
	return y;
}
std::string Node::getID(void) const
{
	return	prefix + std::to_string(index);
}

// Print Funtions
void Node::print(void)
{
	std::cout << std::fixed << std::setprecision(6) << getID() << "(" << getX() << ", " << getY() << ")" << std::endl;
}

std::ostream &operator<<(std::ostream& out, const Node& node)
{
	out << std::fixed << std::setprecision(6) << node.getID() << "(" << node.getX() << ", " << node.getY() << ")";
	return out;
}

// Operator Overloadings
Node &Node::operator+=(const Node &otherNode){

	this->setX(this->getX() + otherNode.getX());
	this->setY(this->getY() + otherNode.getY());

    return *this;
}

Node Node::operator*(const double d) const {
    Node node(this->getX() * d, this->getY() * d);
    return node;
}

Node &Node::operator*=(const double d) {
	this->setX(this->getX() * d);
	this->setY(this->getY() * d);
    return *this;
}

Node Node::operator/(const double d) const {
    Node node(this->getX() / d, this->getY() / d);
    return node;
}


Node &Node::operator/=(const double d) {
	this->setX(this->getX() / d);
	this->setY(this->getY() / d);
    return *this;
}
bool operator==(const Node &first, const Node &second){

	if(first.getX() == second.getX() && first.getY() == second.getY())
		return true;
    return false;
}

// Destructor
Node::~Node(){
	count--;
}