#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

class point {
    int i;
    int j;
};

void ff(vector<vector<int> > &sth) {
    cout << (sth)[0][0];
    cout << (sth)[0][1];
    cout << sth[1][2];
    cout << sth[1][1];
}

int main() {
//    vector<vector <int> >a;
//    vector <int> newRow;
//    newRow.push_back(0);
//    newRow.push_back(1);
//    newRow.push_back(2);
//    a.push_back(newRow);
//    a.push_back(newRow);
//    cout<<a.size();
//    cout<<newRow.size();
    string E1String, E2String;
    int E1,E2;
    ifstream myFile;
    myFile.open("C:\\Users\\asus\\Desktop\\testCases\\test.txt");
    if(!myFile)
        cout<<"error";
    while (myFile.good()) {
        getline(myFile,E1String,',');
        getline(myFile,E2String,'\n');
        stringstream convertor1(E1String);
        convertor1>>E1;
        stringstream convertor2(E2String);
        convertor2>>E2;
        cout<<E1<<"  "<<E2<<endl;
    }

}
