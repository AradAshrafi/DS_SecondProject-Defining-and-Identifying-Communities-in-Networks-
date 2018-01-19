#include <iostream>
#include "constantsClass.h"
#include "adjMatrix.h"
#include "adjList.h"
#include "constantsCalculation.h"
#include "quickSort.h"
#include "insertionSort.h"
#include "mergeSort.h"
#include "bubbleSort.h"
#include <fstream>
#include <vector>

using namespace std;

void what2do(string dataStructure, int whichSort, string where2open) {
    if (dataStructure == "linkedList") {
        vector<node *> adjList;
        int numberOfEdges;//twice of the real amount because each edge calculate two times.
        numberOfEdges = buildList(where2open, adjList);
        cout<<"flag1";
        Cij *constantsArray = buildConstantsArrayForAdjList(adjList, numberOfEdges);
        cout<<"flag2";
        int numberOfVertices=adjList.size();
        cout<<"Edges : " << numberOfEdges <<endl<< "Vertices : "<<numberOfVertices;
        switch (whichSort) {
            case 1: {
                quickSort(constantsArray,0,numberOfEdges-1);
                for (int i = 0; i < numberOfEdges; i++)
                    cout << constantsArray[i].data << endl;
                break;
            }
            case 2: {
                insertionSort(constantsArray,numberOfEdges-1);
                break;
            }
            case 3: {
                merge_sort(constantsArray,0,numberOfEdges-1);
                break;
            }
            case 4: {
                bubbleSort(constantsArray,numberOfEdges-1);
                break;
            }
            case 5: {
                cout << "optimum insertion N";
                break;
            }
            case 6: {
                cout << "optimum bubble N";
                break;
            }

        }
    } else {
        vector<vector<int> > adjMatrix;
        int numberOfEdges = buildMatrix(where2open, adjMatrix);
        int numberOfVertices=numberOfVerticesOfAdjMatrix(adjMatrix,numberOfEdges);
        cout<<"Edges : " <<numberOfEdges <<endl<< "Vertices : "<<numberOfVertices<<endl;
        Cij *constantsArray = buildConstantsArrayForAdjMat(adjMatrix, numberOfEdges);
        switch (whichSort) {
            case 1: {
                quickSort(constantsArray,0,numberOfEdges-1);
                break;
            }
            case 2: {
                insertionSort(constantsArray,numberOfEdges);

                break;
            }
            case 3: {
                merge_sort(constantsArray,0,numberOfEdges-1);
                break;
            }
            case 4: {
                bubbleSort(constantsArray,numberOfEdges);
//                for(int i=0;i<numberOfEdges;i++)
//                    cout<<constantsArray[i].data<<endl;
                break;
            }
            case 5: {
                cout << "optimum insertion N";
                break;
            }
            case 6: {
                cout << "optimum bubble N";
                break;
            }
        }
    }
}

int main() {
    string where2open;
    int maxData = 0;
    cout << "enter the path of your file : ";
    getline(cin, where2open);
    ifstream myFile;
    myFile.open(where2open.c_str());
    if (!myFile) {
        cout << "unable to find the file you've requested";
    } else {
        myFile.close();
        string dataStructure = "meeh";//just to initialize in a way that goes into the while loop
        while (dataStructure != "linkedList" && dataStructure != "matrix" && dataStructure != "0") {
            cout << "what data structure do you want to use ?"
                    " linkedList or matrix ? " << endl;
            cout << "plz just give me one of these two notation : "
                    "linkedList - _ - matrix [enter 0 to exit] " << endl;
            cin >> dataStructure;
        }
        if (dataStructure != "0") {
            int whichSort = 7;//just to initialize in a way that while's condition be true
            while (whichSort > 6 || whichSort <= 0) {
                cout << "what kind of sort do you want to use ? "
                        "[1:quick,2:insertion,3:merge,4:bubble,"
                        "5:optimum insertion N,6:omptimum bubble N]"
                        "enter 0 to quit" << endl;
                cin >> whichSort;
            }
            what2do(dataStructure, whichSort, where2open);
        }
    }
    system("pause");
}
