#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#define OK 1

using namespace std;

struct Connectivity {
	
	Connectivity(int src, int dest, int weight){
		source = src;
		destination = dest;
		cost = weight;
	}
	
	int source;
	int destination;
	int cost;
	
	bool operator <(Connectivity &compared){
		return cost < compared.cost; // 오름차순 
	}
	
};

vector<Connectivity> inputList;
vector<int> rootOfCities(101);

int Find(int city){
	
	// num doesn't belong to any tree
	if(city == rootOfCities[city]) return city;
	// update and find
	else return rootOfCities[city] = Find(rootOfCities[city]);
	
}

int Union(int first, int second){
	
	int rootOfFirst = Find(first);
	int rootOfSecond = Find(second);
	
	if(rootOfFirst != rootOfSecond) {
		rootOfCities[rootOfFirst] = rootOfSecond;
		return OK;
	}
	else {
		return -1;
	}
}

int main(int argc, char** argv) {
	
	// freopen("input.txt", "rt", stdin);
	
	int numOfVertices, numOfEdges; 
	cin >> numOfVertices >> numOfEdges; 
	
	for(int i = 0; i < numOfEdges; i++){
		int source, dest, weight;
		cin >> source >> dest >> weight;
		Connectivity connectivity(source, dest, weight);
		inputList.push_back(connectivity);
	}
	
	for(int i = 1; i <= numOfVertices; i++){
		rootOfCities[i] = i; 
	}
	
	sort(inputList.begin(), inputList.end());
	
	int totalCost = 0;
	for(vector<Connectivity>::iterator it = inputList.begin(); it != inputList.end(); it++){
		// e.g., (2 - 9)
		Connectivity road = (*it);
		if(Union(road.source, road.destination) == OK){
			totalCost += road.cost;
		}
	}
	
	cout << totalCost;
	
	return 0;
}
