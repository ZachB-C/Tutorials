// This is just to test the graph.h does what it is intended to do.
//
#include <iostream>

#include "graph.h"

// We can have different load constructors for our binary tree
// bool isSearchTree, vector<T> data; vector<T> data (for complete tree);  
// vector<bool> present, vector<T> data; (for each child 
// (left and right separately) of each node it has true if that child exists
// and false if it doesn't this goes in order top to bottom left to right)
// data is the corresponding data, data starts with the data for the first node
// and then contains the data for every true node.
int main() {
	// Build a simple graph and print it.ia
	std::cout<<"Start"<<std::endl;
	GraphNode<int> node = GraphNode<int>(0);
	node.print();
	std::cout<<"Child "<<std::endl;
	node.add_child(&node);
	std::cout<<"Print "<<std::endl;
	node.print();
	std::cout<<"Clear children"<<std::endl;
	node.clear_children();
//	node.~GraphNode();
//	node.~GraphNode();
	Graph<int> graph = Graph<int>({0,1,2,3,4}, {{1,3},{0,4},{2},{4},{2}});
	graph.print();
	std::cout<<"Try to delete."<<std::endl;
//	graph.~Graph();
	for( size_t i = 0; i < graph.nodes.size(); ++i ) {
		std::cout<<"Dat: "<<graph.nodes[i].data<<std::endl;
		graph.nodes[i].clear_children();
		graph.nodes[i].print();
	}	
	graph.print();
	std::cout<<"Deleted."<<std::endl;
	// Then try to do a recursive print starting at a node.
	// Maybe use a queue? I think I have a queue structure somewhere I
	// can use... maybe add a queue to the stack and queue thing.


	return 0;
}
