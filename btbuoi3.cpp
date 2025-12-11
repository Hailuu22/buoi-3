#include<iostream>
#include<fstream>
#include<sstream>
#include<vector>
using namespace std;
void printMatran(vector<vector<int>> matran){
    for (int i = 0 ; i < matran.size(); i++){
        for(int j = 0 ; j < matran[i].size();j++){
            cout << matran[i][j];
            if (j < matran[i].size() -1 ){
                cout << ",";
            }
        }
        cout << endl;
    }
}
int main(){
    fstream file("book2.csv");
    vector<vector<int>> matran1;
    vector<vector<int>> matran2;
    string line;


    // đọc ma trận 1
    getline(file,line);
    while(getline(file,line)){
        if(line.find("matran") != string::npos){
            break;
        }
        vector<int> row;
        stringstream ss(line);
        string cell;
        while(getline(ss,cell,',')){
            row.push_back(stoi(cell));
        }
        matran1.push_back(row);
    }


    // số hàng , số cột của ma trận 1 , m là số hàng , n là số cột
    int n1 = matran1[0].size();
    int m1 = matran1.size();



    // đọc ma trận 2 
    while(getline(file,line)){
        vector<int> row1;
        string cell2;
        stringstream ss(line);
        while(getline(ss,cell2,',')){
            row1.push_back(stoi(cell2));
        }
        matran2.push_back(row1);
    }
    // số hàng , số cột ma trận 2 
    int n2 = matran2[0].size();
    int m2 = matran2.size();


    // tính tổng , hiệu 2 ma trận
    vector<vector<int>> matrantong;
    vector<vector<int>> matranhieu;
    if (m1 == m2 && n1 == n2 ){
        for (int i = 0 ; i < n1 ; i++){
            vector<int> tong;
            vector<int> hieu;
            for (int j = 0 ; j < m1 ; j++){
                tong.push_back(matran1[i][j] + matran2[i][j]);
                hieu.push_back(matran1[i][j] - matran2[i][j]);
            }
            matrantong.push_back(tong);
            matranhieu.push_back(hieu);
        }


        // in ra ma trận tổng , hiệu
        cout << "tong ma tran" << endl;
        printMatran(matrantong);
        cout << "hieu ma tran" << endl;
        printMatran(matranhieu);
    }else{
        cout << "Khong co ket qua tong , hieu" << endl;
    }


    // nhân 2 ma trận
    vector<vector<int>> matrantich;
    if (n1 = m2){
        for (int i = 0 ;i < m1; i++ ){
            vector<int> tich;
            for (int j = 0 ; j < n2;j++){
                tich.push_back(0);
                for (int p = 0 ; p < n1 ; p++){
                    tich[j] += matran1[i][p] * matran2[p][j];
                }
            }
            matrantich.push_back(tich);
        }
    }else{
        cout << " Khong nhan duoc 2 ma tran "<< endl;
    }


    
    // in ra ma trận tích
    cout << "nhan ma tran "<< endl;
    printMatran(matrantich);
    return 0;
}