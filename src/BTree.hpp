#ifndef BTREE_HPP
#define BTREE_HPP

#include <fstream>
#include <utility>
#include "FileOperator.hpp"

template<typename Key, typename Value, int BLKSZ = 512>
class BTree {
public:
	enum {
		KeyCnt = (BLKSZ - sizeof(bool) - sizeof(int)) / (sizeof(Key) + sizeof(int)),
		ValueCnt = (BLKSZ - sizeof(int) * 3) / sizeof(std::pair<Key,int>)
	};
	
	void insert( Key key,
				 Value value,
				 std::fstream &btree_file,
				 std::fstream &value_file );
	void remove( Key key,
				 std::fstream &btree_file );
	void modify( Key key,
				 Value value,
				 std::fstream &btree_file,
				 std::fstream &value_file );
	int query_list( Key key_left,
					Key key_right,
					std::fstream &btree_file,
					std::fstream &value_file,
					std::pair<Key, Value> *&value ); // inside new outside delete
	Value query( Key key,
				 std::fstream &btree_file,
				 std::fstream &value_file );
	bool exist( Key key,
				std::fstream &btree_file );
	
private:
	
	class Node {
	public:
		Key key[KeyCnt];
		int ch[KeyCnt];
		bool leaf;
		int cnt;
		
		Node() {
			leaf = false;
			cnt = 0;
		}
	};
	
	class Leaf {
	public:
		std::pair<Key,int> value[ValueCnt];
		int cnt;
		int pre, nxt;
		
		Leaf() {
			cnt = 0;
			pre = nxt = -1;
		}
	};
	
	FileOperator fop;
};

template<typename Key, typename Value, int BLKSZ>
void BTree<Key, Value, BLKSZ> :: insert( Key key,
										 Value value,
										 std::fstream &btree_file,
										 std::fstream &value_file ) {
	if( fop.end_pos( btree_file ) == 0 ) { // new file
		Node root;
		fop.write( btree_file, -1, &root, 1 );
		assert( fop.end_pos( btree_file ) == sizeof(Node) );
		
		Leaf root_leaf;
		fop.write( btree_file, -1, &root_leaf, 1 );
		assert( fop.end_pos( btree_file ) == sizeof(Node) + sizeof(Leaf) );
	}
	
	Node root;
	fop.read( btree_file, 0, &root, 1 );
	if( root.cnt == 0 ) { // root is leaf
		
		std::tuple<bool,int,int> tmp = insert_leaf( sizeof(Node),
													key,
													value,
													btree_file,
													value_file );
		if( std::get<0>(tmp) == false ) {
			root.cnt = 1;
			root.leaf = true;
			root.ch[0] = std::get<1>(tmp);
			root.ch[1] = std::get<2>(tmp);
			root.key[0] = get_min_leaf( root.ch[0] );
			root.key[1] = get_min_leaf( root.ch[1] );
			fop.write( btree_file, 0, &root, 1 );
		}
		
	} else { // root is node
		
		std::tuple<bool,int,int> tmp = insert_node( 0,
													key,
													value,
													btree_file,
													value_file );
		if( std::get<0>(tmp) == false ) {
			root.cnt = 1;
			root.leaf = false;
			root.ch[0] = std::get<1>(tmp);
			root.ch[1] = std::get<2>(tmp);
			root.key[0] = get_min_node( root.ch[0] );
			root.key[1] = get_min_node( root.ch[1] );
			fop.write( btree_file, 0, &root, 1 );
		}
	}
}

template<typename Key, typename Value, int BLKSZ>
void BTree<Key, Value, BLKSZ> :: remove( Key key,
										 std::fstream &btree_file ) {
	;
}

template<typename Key, typename Value, int BLKSZ>
void BTree<Key, Value, BLKSZ> :: modify( Key key,
										 Value value,
										 std::fstream &btree_file,
										 std::fstream &value_file ) {
	insert(key, value, btree_file, value_file);
}

template<typename Key, typename Value, int BLKSZ>
int BTree<Key, Value, BLKSZ> :: query_list( Key key_left,
											Key key_right,
											std::fstream &btree_file,
											std::fstream &value_file,
											std::pair<Key, Value> *&value ) { // inside new outside delete
	;
}

template<typename Key, typename Value, int BLKSZ>
Value BTree<Key, Value, BLKSZ> :: query( Key key,
										 std::fstream &btree_file,
										 std::fstream &value_file ) {
	if( fop.end_pos( btree_file ) == 0 ) { // new file
		assert(0); // not existed
		return Value();
	} else {
		Node root;
		fop.read( btree_file, 0, &root, 1 );
		if( root.cnt == 0 ) { // root is leaf
			return query_leaf( sizeof(Node),
							   key,
							   btree_file,
							   value_file );
		} else { // root is node
			return query_node( 0,
							   key,
							   btree_file,
							   value_file );
		}
	}
}

template<typename Key, typename Value, int BLKSZ>
bool BTree<Key, Value, BLKSZ> :: exist( Key key,
										std::fstream &btree_file ) {
	if( fop.end_pos( btree_file ) == 0 ) { // new file
		return false;
	} else {
		Node root;
		fop.read( btree_file, 0, &root, 1 );
		if( root.cnt == 0 ) { // root is leaf
			return exist_leaf( sizeof(Node), key, btree_file );
		} else { // root is node
			return exist_node( 0, key, btree_file );
		}
	}
}

#endif // BTREE_HPP
