/*  Work name: Fianl task--> BFS, DFS, Dijkstra and Prim implementation
    Subject: Data Structure
    Author: Kevin Alejandro Salazar
    Date: 06/12/2021
    Compiler: g++.exe (Rev10, Built by MSYS2 project) 10.2.0
 */


#include<iostream>
#include<map>
#include<vector>
#include "agrm.hpp"
// #include "TADgrafo.h"

using namespace std;

ostream & operator<<(ostream &out, const Graf &grafx){ // Show with overload
	for(auto const &vertex: grafx){
		out<< vertex.first<<": ";

		out<<"[";

		for(size_t i=0; i<vertex.second.size();i++){
			out<<vertex.second[i];

			if(i!=vertex.second.size()-1){
				out<<", ";
			}
		}

		out<<"]";

		out<<endl;
	}

	return out;
}
int main (int argc, char *argv[]) {
	
	Graf graf;

	graf["A"]={"B","C"};
	graf["B"]={"A", "D"};
	graf["C"]={"A", "D","E"};
	graf["D"]={"B","C"};
	graf["E"]={"C"};
	
	cout<<graf;

    vector<string> checked1 = deepSearch(graf);

    for(auto const &vertex: checked1) {
        cout<< vertex<< endl;
    }

	cout<< endl;

	vector<string> checked2 = amplitudeSearch(graf);

    for(auto const &vertex: checked2) {
        cout<< vertex<< endl;
    }
	
	return 0;
}