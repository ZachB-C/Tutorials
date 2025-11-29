// Here we define the class of graphs, it is quite simple but we'll add in 
// a few extra modules to make things a bit more exciting, like a traverse
// function to visit everything or a print function that does something similar.
// perhaps.
#include <iostream>
#include <vector>
#include <exception>

// Make a simple ID generator
size_t id_generator() {
	// Initialise value on first call
	static size_t id_value = 0;
	// Update the value for each call and return the previous value
	return id_value++;

}


// We have to use pointers to children because they may appear in multiple
// nodes, for trees they could hold the nodes themselves.
template <typename T>
class GraphNode {
	size_t id;
	public:
		GraphNode(T data);
		GraphNode(T data, std::vector<GraphNode<T>*> children);
		~GraphNode(); // Do not delete the children just nullify the
			      // pointer, as the graph structure can 
			      // delete the children.
		T data;
		std::vector<GraphNode<T>*> children;
		void clear_children();
		void add_child(GraphNode<T>* child);
		void print();
};


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
};

// For the tree nodes, we have no wrapper the idea is that each node
// holds its descendants and each node knows its parent and children,
// it holds a pointer to its parent but contains its children inside it.
// So the destroy calls destroy on the children.
template <typename T>
class TreeNode {
	size_t id;
	public: 
		TreeNode();
		TreeNode(T data); 
		TreeNode(T data, TreeNode<T>* parent); 
		// A recursive creation could be difficult?
		// Instead we will have a method to create 
		// trees
		~TreeNode();
		T data;
		TreeNode<T>* parent;
		std::vector<TreeNode<T>> children;
		void add_child(T data); // Adds a child with no descendants or
					// ancestors, makes a new child.
		void steal_child(TreeNode<T>& stolen_child); // Can take a child
			//  that is already defined and incorporate it.
			// already has parents
			// remove it from them		
		void delete_child(TreeNode<T>& excess_child); // Not sure how
			// easy this is to implement, we will need to
			// do a comparison, an overloaded equals? Each child
			// might need unique ID or we might have to do
			// it using a pointer instead.
};


////
///
///
///
/// Graph Nodes
///
///
///
///
///
///
///
///
///
///
///
///


template <typename T> 
GraphNode<T>::GraphNode(T data) {
	id = id_generator();
	this->data = data;
	children = {};
}

template <typename T>
GraphNode<T>::GraphNode(T data, std::vector<GraphNode<T>*> children) {
	id = id_generator();
	this.data = data;
	this.children = children;
}

template <typename T>
void GraphNode<T>::clear_children() {
	for( size_t i=0; i < children.size(); ++i) {
		// Wipe memory of children.
//		std::cout<<"in: "<<i<<std::endl;
		children[i] = NULL;	
	}
	while( children.size() != 0 ) {
		children.pop_back();
	}
}
template <typename T>
GraphNode<T>::~GraphNode() {
	// Get rid of references to children so they cannot be accessed.
//	std::cout<<"Test"<<std::endl;
	clear_children();
//	std::cout<<"Test 2"<<std::endl;
}


template <typename T>
void GraphNode<T>::add_child(GraphNode<T>* child) {
	// Add them to the list.
	children.push_back(child);
}

// Note this means << would need to be overloaded if we use types
// that cannot be printed in this way. We will stick to simple stuff
// so it should be fine. Should we do recursive print or not
// No way 
template <typename T>
void GraphNode<T>::print() {
	std::cout<<" ID: "<<id<<" Data: "<<data<<" Children IDs: ";
	for(GraphNode<T>* child : children) {
		std::cout<<child->id<<"\t";
	}
	std::cout<<std::endl;
	return;
}

////
///
////
/////
////
////  Graphs
////
////
////
////
////
////

template <typename T>
Graph<T>::Graph(
		std::vector<T> node_data, 
		std::vector<std::vector<size_t>> connection_data
	       )
{
	// Check we have the correct amount of connection data
	if( node_data.size() != connection_data.size() ) {
		throw std::length_error("There should be one set of connection"
				 "data for each node.");
	}
	// First we generate each node and add it to our list of nodes
	for( T data : node_data ) {
		// Add nodes to the list of nodes, each will have a
		// unique ID, the order matters as it will match
		// the connection_data.
//		std::cout<<"Constructor called."<<std::endl;
		nodes.push_back( GraphNode(data) );
	}
	// Now add the connection data to the nodes.
	// check we have the correct amount of connection data
	for( size_t n = 0; n < nodes.size(); ++n ) {
		// Loop through each node in each node's connection data
		for( size_t m : connection_data[n] ) {
			// Add the child's reference to the node
			// so it knows who it connects to.
		       	nodes[n].add_child( &nodes[m] ); 
		}
	}
}


template <typename T>
Graph<T>::~Graph() {
	// Cycle through each node calling the destructor for each
	for( GraphNode<T> node : nodes ) {
		// They will each get rid of any handing pointers 
		// so the pointers will be destroyed correctly.
		// Maybe they should use the unique pointer stuff to make 
		// it work better.
//		std::cout<<"Node: "<<node.data<<std::endl;
		node.clear_children();
//		std::cout<<"Node2: "<<node.data<<std::endl;
	}
}


template <typename T>
void Graph<T>::print() {
	for( GraphNode<T> node : nodes ) {
		node.print();
	}
	return;
}

