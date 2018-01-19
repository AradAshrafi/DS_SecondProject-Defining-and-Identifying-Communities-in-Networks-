//
// Created by Arad on 12/31/2017.
//
#include <sstream>
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

class node {
public:
    int data;
    node *next;

    node() {
        data = 0;
        next = NULL;
    }
};

int buildList(string where2open, vector<node *> &adjList) {
    node *just2begin = new node();//*** important : is a node with data 0 in the 0 index to make less comparisons,i've deleted at last
    adjList.push_back(just2begin);
    ifstream myFile2;
    myFile2.open(where2open.c_str());
    string line;
    string E1String, E2String;
    int E1,E2;
    int index = 0, numberOfEdges = 0;
    while (myFile2.good()) {
        getline(myFile2,E1String,',');
        getline(myFile2,E2String,'\n');
        stringstream convertor1(E1String);
        convertor1>>E1;
        stringstream convertor2(E2String);
        convertor2>>E2;
        if (E1 != adjList[index]->data) {
            node *startingNode = new node();
            startingNode->data = E1;
            adjList.push_back(startingNode);
            node *destinationNode = new node();
            destinationNode->data = E2;
            startingNode->next = destinationNode;
            index++;
            numberOfEdges++;
        } else {
            node *check = adjList[index];
            while (check->next) {
                check = check->next;
            }
            node *destinationNode = new node();
            destinationNode->data = E2;
            check->next = destinationNode;
            numberOfEdges++;
        }
    }
    adjList.erase(adjList.begin());
    myFile2.close();
    return numberOfEdges;

}