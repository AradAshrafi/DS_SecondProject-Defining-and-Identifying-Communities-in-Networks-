int returnMin(int a, int b) {
    if (a <= b)
        return a;
    else
        return b;
}

//for adjMat ->
Cij *buildConstantsArrayForAdjMat(vector<vector<int> > &adjMatrix, int numberOfEdges) {
    Cij *constantsArray = new Cij[numberOfEdges];
    int index = 0;

    for (int i = 0; i < numberOfEdges; i++) {
        int Zij = 0;
        constantsArray[index].i = adjMatrix[i][0];//i or index
        constantsArray[index].j = adjMatrix[i][1];
        int m = i;
        if (m > 0)
            while (adjMatrix[m - 1][0] == adjMatrix[i][0]) {//find the first index of the first element
                m--;
                if (m == 0)
                    break;
            }
        int j = 0;//find the first index of the second element
        while (adjMatrix[j][0] != adjMatrix[i][1] && j < numberOfEdges - 1)
            j++;
        int M0 = m;//origin of the first vertex
        int n=j;//it'll be the origin of the second matrix two lines below here:D
        while (adjMatrix[m][0] == adjMatrix[i][0] && m < numberOfEdges) {
            n = j;//origin of the second vertex
            while (adjMatrix[n][0] == adjMatrix[i][1]) {
                if (adjMatrix[m][1] == adjMatrix[n][1]) {
                    Zij++;
                }
                if(n==numberOfEdges-1)
                    break;
                n++;
            }
            if(m==numberOfEdges-1)
                break;
            m++;

        }
        cout<<Zij<<" ";
        returnMin((m - M0), (n - j)) ? constantsArray[index].data =
                                                       (Zij + 1)*1.0 / returnMin((m - M0 - 1), (n - j - 1))
                                             : constantsArray[index].data = 0;
        index++;
        cout<<"constant is : "<<constantsArray[index-1].data<<endl;
    }
    return constantsArray;
}

//for Both Of Them  --->
void structConstantsArray(Cij *constantsArray, int numberOfEdges) {
    int index = 0;
    for (int i = 0; i < numberOfEdges; i++) {
        int Zij = 0;
        int j = 0;//find the first index of the second element
        while (constantsArray[j].i != constantsArray[i].j && j < numberOfEdges - 1)
            j++;
        int m = i;
        while (constantsArray[m].i == constantsArray[i].i && m - 1 > 0)//find the first index of the firs element
            m--;
        int M0 = m;//origin of the first vertex
        int n = j;//origin of the second vertex
        while (constantsArray[m].i == constantsArray[i].i && m <= numberOfEdges) {
            while (constantsArray[n].i == constantsArray[i].j && n <= numberOfEdges) {
                if (constantsArray[m].j == constantsArray[n].j)
                    Zij++;
                n++;
            }
            m++;
        }
        returnMin((m - M0 - 1), (n - j - 1)) ? constantsArray[index].data =
                                                       (Zij + 1) * 1.0/ returnMin((m - M0 - 1), (n - j - 1))
                                             : constantsArray[index].data = 0;
        index++;
    }
}

//for adjList
Cij *buildConstantsArrayForAdjList(vector<node *> &adjList, int numberOfEdges) {
    Cij *constantsArray = new Cij[numberOfEdges];
    int index = 0;
    int numberOfVertices = adjList.size();
    for (int i = 0; i < numberOfVertices; i++) {
        node *j = adjList[i];
        while (j->next) {
            j = j->next;
            constantsArray[index].i = adjList[i]->data;
            constantsArray[index].j = j->data;
            index++;
        }
    }
    structConstantsArray(constantsArray, numberOfEdges);

    return constantsArray;
};

