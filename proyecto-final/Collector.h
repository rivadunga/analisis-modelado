#pragma once

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <map>
#include "Object.h"
using namespace std;

class Object;

/**
	MAIN CLASS to collect and handle memory references, it is
	equivalente to GARBAGE_COLLECTOR of java
*/

class Collector
{
private:
	
	Collector(){
		s_instance = this;
	}
	
	//Singleton pattern to improve performance	
	static Collector 	     *s_instance;

	//Vector with references	
	vector<void*>            refs;
	
	//Graph with references and their childs
	// Parent -> child -> child ...
	vector< vector<void*> >  graph;

	int getPos(void* o)
	{
		for (int i = 0; i < refs.size(); i++)
    		if (refs[i] == o) return i;
    	return -1;
	}
	

public:
	static Collector *getInstance()
    {
        if (!s_instance)
          s_instance = new Collector;
        return s_instance;
    }

	//Attach to the collector using a visitor pattern	
	
    void* attach(size_t size)
    {
    	void *o = malloc(size);
        refs.push_back(o);
        vector<void*> temp;
    	graph.push_back(temp);

    	cout << "attach: " << o << endl;
    	return o;
    }

    void * attach(size_t size, void* parent)
    {
    	void *o = malloc(size);
        refs.push_back(o);
        vector<void*> temp;
    	graph.push_back(temp);

        int pos = getPos(parent);
        if (pos != -1)	graph[pos].push_back(o);
    	cout << "attach-parent: " << o << endl;
    	return o;
    }

    void detach(void* o)
    {
        int pos = getPos(o);
        if (pos != -1){
    		for (int i = graph[pos].size() - 1; i >= 0; i--){
   				detach(graph[pos][i]);
   				graph[pos].erase(graph[pos].begin() + i);	
    		}
        	free(refs[pos]);
			refs.erase(refs.begin() + pos);	
			cout << "detach: " << o << endl;
		}
    }

    void notifyAttach(void* o){ ((Object*)o); }

    void notifyDetach(void* o){ ((Object*)o); }

    void clean()
    {
    	for (int i = refs.size() - 1; i >= 0; i--)
    		detach(refs[i]);
    }

    friend ostream& operator<<(std::ostream& os, const Collector& c){
    	os << endl << "--- Collector --- " << endl;
    	for (int i = 0; i < c.refs.size(); i++){
    		os << c.refs[i];
			for (int j = 0; j < c.graph[i].size(); j++){
    			os << "->" << c.graph[i][j];
    			if (j < c.graph[i].size() - 1) os << ",";
			}
    		os << endl;
    	}
    	os << endl;
    	return os;
	}
};
Collector* Collector::s_instance = 0;
