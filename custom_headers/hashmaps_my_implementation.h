/*

Created on Fri 13 1:11:20 2019

@author: Dhruv


*/


/*
This is My custom implementation of a simple hashMap data structure functionality
available in c++.


*/
#include<string>
using namespace std;

template<typename V>
class MapNode{   // class for our linkedList node
	public:
		string key;  // our key ;
		V value; // value
		MapNode* next;  // address of next element for linkedList
		
		// constructor
		MapNode(string key, V value){
			this->key = key;
			this->value = value;
			next = NULL;
		}

		// destructor
		~MapNode(){
			delete next;
		}



};

// class for our hashmap
template<typename V>
class ourmap{

public:
	MapNode<v>** buckets;  // MapNode<v>* would be head of linkedList , now for each element we want all element in arary so MapNode<v>**
	int count;  //  count of element in each buckets
	int numBuckets; // num of index in buckets i.e size

	// constructor
	ourmap(){
		count =0;
		numBuckets = 5 // temporary we take numBuckets = 5
		for(int i=0;i<numBuckets;i++){
			buckets[i] = NULL;
		}
	}

	// destructor
	~ourmap(){
		for(int i=0;i<numBuckets;i++){
			delete buckets[i];   // delete everything from array
		}
		delete [] buckets; // delete array itself
	}	

	// get the size of size();
	int size(){
		return count; 
	}


private:

	int getBucketIndex(string key){
		int hashCode = 0; // initially taking hashCode as 0;
		int currentCoeff = 1;
		int p = 41; // taking our factor as prime number p, because it helps in good distribution of hashCodes
		for(int i=key.length()-1;i>=0;i--){
			hashCode+=currentCoeff*key[i];
			currentCoeff*=p;
			hashCodes = hashCode % numBuckets;
			currentCoeff = currentCoeff % numBuckets;   // just an optimization so that our hashCode doesnt get out of range of bucket size;
		}
		return hashCode % numBuckets;
	}

public:



// function to get the value of key given by user;
 V getValue(string key){
 	int bucketIndex = getBucketIndex(key); // getting the bucket index where we will fetch value
 	MapNode<v> * head = buckets[bucketIndex];  // taking head pointer

	while(head!=NULL){

		if(head->key = key){
			return head->value;  // key found in our linkedList so we can simply return its value;
		}

		head = head->next;
	}
	return 0; // not found 
 }



 void insert(string key,V value){

 	int bucketIndex = getBucketIndex(key);
 	MapNode<v> *head = buckets[bucketIndex]; // taking head pointer
	
	while(head!=NULL){

		if(head->key = key){
			head->value = value;  // key already present so just update its value
			return;
		}

		head = head->next;
	}
	// now if key is not present;

	head = buckets[bucketIndex]; // head as bucketIndex;
	MapNode<v>* node = new MapNode<key,value>; // create a new node with our key and value			
	node->next =head;
	buckets[bucketIndex] = node;  // update the head position
	count++;

 }

 V remove(string key){

 	int bucketIndex = getBucketIndex(key); // getting index 
 	MapNode<v> *head = buckets[bucketIndex];  // taking head pointer
 	MapNode<v>* prev  = NULL;  // we also have to take a prev pointer so that we can delete a node
 	while(head!=NULL){

 		if(head->key == key){
 			if(prev = NULL){
 				bucket[bucketIndex] = head->next;
 			}else{
 				prev->next = head->next; 
 			}

 			V value = head->value; // store value as we have to return it.
 			head->next = NULL;  // also carefully disconnect head's connection
 			delete head;	// only after disconnection delete the head
 			count--;
 			return value;
 		}
 		prev = head;

 		head = head->next;
 	}

 	return 0;
 }





};
