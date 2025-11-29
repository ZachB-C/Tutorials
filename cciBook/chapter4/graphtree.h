// Here we define the class of graphs, it is quite simple but we'll add in 
// a few extra modules to make things a bit more exciting, like a traverse
// function to visit everything or a print function that does something similar.
// perhaps.
#include <iostream>
#include <vector>

// We have to use pointers to children because they may appear in multiple
// nodes, for trees they could hold the nodes themselves.
template <typename T>
class GraphNode {
	public:
		GraphNode(T data, std::vector<GraphNode<T>*> children);
		~GraphNode(); // Do not delete the children just nullify the
			      // pointer, as the graph structure can 
			      // delete the children.
		T data;
		std::vector<GraphNode<T>*> children;
		void add_child(GraphNode<T> child);
		void print();
}


template <typename T>
class Graph {
	public:
		// Input vector of vectors. Node's data runs from node zero
		// to node ? Connection data lists directed connections for 
		// each node in turn, from 0 to n and provides the links.
		Graph(std::vector<T> node_data, 
		      std::vector<std::vector<size_t>> connection_data);
		// Constructor is trivial so don't define.
		~Graph(); // Make sure we only destroy it once.
		std::vector<GraphNode<T>> nodes; // Stores all the nodes in 
						 // the graph.

		void print(); // Prints out the nodes, their data and their
			      // links.
}


template <typename T> 
GraphNode<T>::GraphNode(
