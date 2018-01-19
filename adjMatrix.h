//
// Created by Arad on 12/31/2017.
//
#include <sstream>
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int buildMatrix(string where2open, vector<vector<int> > &matrix) {
    ifstream myFile1;
    myFile1.open(where2open.c_str());
    string E1String, E2String;
    int E1,E2;
    int numberOfEdges = 0;
    while (myFile1.good()) {
        vector<int> rowToPush;
        getline(myFile1,E1String,',');
        getline(myFile1,E2String,'\n');
        stringstream convertor1(E1String);
        convertor1>>E1;
        stringstream convertor2(E2String);
        convertor2>>E2;
        rowToPush.push_back(E1);
        rowToPush.push_back(E2);
        matrix.push_back(rowToPush);
        numberOfEdges++;
    }
    myFile1.close();
    return numberOfEdges;

}

int numberOfVerticesOfAdjMatrix(vector<vector<int> >& matrix , int numberOfEdges){
    int numberOfVertices=1;
    for (int i=1 ; i<numberOfEdges ; i++){
        if(matrix[i][0]!=matrix[i-1][0])
            numberOfVertices++;
    }
    return numberOfVertices;
}