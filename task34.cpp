#include <iostream>
#include <string>
#include <fstream>
#include <stdexcept>
                                                                                                                                                                    
using namespace std;
                                                    
int main() {
	
        //1 matrix
        ifstream matrix_file("matrix.txt");
        string temp_m;                                                                                                                                              
        int m = 0;
        int n = 0;
                                                                                                                                                                    
        //size 1 matrix
        while (getline(matrix_file, temp_m)) {
                m++;                                                                                                                                                
                n = 0;                                                                                                                                              
                for (int i=0;i<temp_m.length();i++) {
                        if (temp_m[i] != ' ') {
                                n++;                                                                                                                                
                        }                                                                                                                                           
                }                                                                                                                                                   
        }                                                                                                                                                           
                                                                                                                                                                    
        matrix_file.clear();                                                                                                                                        
        matrix_file.seekg(0);                                                                                                                                       
                                                                                                                                                                    
        //mas for 1 matrix
        int** matrix_mas1{new int*[m]{}};
        for (int i = 0; i<m; i++) {
                matrix_mas1[i] = new int[n]{};
        }                                                                                                                                                           
                                                                                                                                                                    
        //fill 1 matrix from file
        int k = 0;
        while (getline(matrix_file, temp_m)) {
			int i = 0;
                for (int j=0;j<temp_m.length();j++) {
                        if (temp_m[j] != ' ') {
                                matrix_mas1[k][i] = temp_m[j] - '0';
                                i++;                                                                                                                                
                        }                                                                                                                                           
                }                                                                                                                                                   
                k++;                                                                                                                                                
        }                                                                                                                                                           
                                                                                                                                                                    
        //2 matrix
        int** matrix_mas2{new int*[m]{}};
        for (int i = 0; i<m; i++) {
                matrix_mas2[i] = new int[n]{};
        }
		                                                                                                                                                           
        //fill with cin                                                                                                                                                            
        //using exceptions
        cout << "Size of your matrix: " << n << "x" << m << endl;
        cout << "For the addition operation, your matrix must be the same size" << endl;
        cout << "Enter the matrix" << endl;
        for (int i = 0; i<m; i++) {
                cout << "Enter row №" << i+1 << endl;
                for (int j = 0; j<n; j++){
                        bool fl_ok = false;
                        string tmp = "";
						while (fl_ok == false) {
							cout << "Enter the number: " << endl;
							cin >> tmp;
							try {
								matrix_mas2[i][j] = stoi(tmp);
							}
							catch(std::invalid_argument e) {
							    cout << "Only numbers are allowed! \n";
							    continue;
							}
							catch(std::out_of_range e) {
    							cout << "Too big number! \n";
    							continue;
							}
							catch(...) {
    							cout << "Unknown error! \n";
    							continue;
							}
							if (matrix_mas2[i][j] > 0) {
								fl_ok = true;
							}
						}                                                                                                                   
                }                                                                                                                                                   
        }                                                                                                                                                           
                                                                                                                                                                    
        //РѕР±СЉСЏРІР»РµРЅРёРµ РјР°С‚СЂРёС†С‹ РґР»СЏ СЂРµР·СѓР»СЊС‚Р°С‚Р° СЃР»РѕР¶РµРЅРёСЏ
        int** matrix_mas3{new int*[m]{}};
        for (int i = 0; i<m; i++) {
                matrix_mas3[i] = new int[n]{};
        }                                                                                                                                                           
                                                                                                                                                                    
        //СЃР»РѕР¶РµРЅРёРµ РјР°С‚СЂРёС†
		cout << "Summ of matrixes:" << endl;
        for (int i = 0; i<m; i++) {
                for (int j=0; j<n; j++) {
                        matrix_mas3[i][j] = matrix_mas1[i][j] + matrix_mas2[i][j];                                                                                  
                        cout << matrix_mas3[i][j] << " ";
                }                                                                                                                                                   
        cout << endl;                                                                                                                                               
        }                                                                                                                                                           
                                                                                                                                                                    
        //РїСЂРѕРёР·РІРµРґРµРЅРёРµ РґРІСѓРјРµСЂРЅС‹С… РјР°С‚СЂРёС†
        cout << "Enter " << m << "x" << n << " matrix for the multiplication" << endl;
                                                                                                                                                                    
        //РѕР±СЉСЏРІР»РµРЅРёРµ РјР°С‚СЂРёС†С‹ РґР»СЏ РїСЂРѕРёР·РІРµРґРµРЅРёСЏ
        int** matrix_mas4{new int*[n]{}};
        for (int i = 0; i<n; i++) {
                matrix_mas4[i] = new int[m]{};
        }                                                                                                                                                           
                                                                                                                                                                    
        //fill matrix for muliplication
        for (int i = 0; i<n; i++) {
                cout << "Enter the " << i+1 << "row: " << endl;
                for (int j = 0; j<m; j++){
                        bool fl_ok = false;
                        string tmp = "";
						while (fl_ok == false) {
							cout << "Enter the number: " << endl;
							cin >> tmp;
							try {
								matrix_mas4[i][j] = stoi(tmp);
							}
							catch(std::invalid_argument e) {
							    cout << "Only numbers are allowed! \n";
							    continue;
							}
							catch(std::out_of_range e) {
    							cout << "Too big number! \n";
    							continue;
							}
							catch(...) {
    							cout << "Unknown error! \n";
    							continue;
							}
							if (matrix_mas4[i][j] > 0) {
								fl_ok = true;
							}
						}                                                                                                                  
                }                                                                                                                                                   
        }                                                                                                                                                           
                                                                                                                                                                    
        //СЃРѕР·РґР°РЅРёРµ РјР°С‚СЂРёС†С‹ РґР»СЏ СЂРµР·СѓР»СЊС‚Р°С‚Р° РїСЂРѕРёР·РІРµРґРµРЅРёСЏ
        int** matrix_mas5{new int*[m]{}};
        for (int i = 0; i<m; i++) {
                matrix_mas5[i] = new int[m]{};
        }                                                                                                                                                           
                                                                                                                                                                    
        for (int i = 0; i<m; i++) {
			for (int j = 0; j<m; j++) {
                        matrix_mas5[i][j] = 0;                                                                                                                      
                }                                                                                                                                                   
        }                                                                                                                                                           
                                                                                                                                                                    
        //РІС‹С‡РёСЃР»РµРЅРёРµ РїСЂРѕРёР·РІРµРґРµРЅРёСЏ
        cout << "Matrix multiplication: " << endl;
        for (int i = 0; i < m; i++){
                for (int j = 0; j < m; j++){
                        for (int l = 0; l < n; l++){
                                matrix_mas5[i][j] += matrix_mas1[i][l] * matrix_mas4[l][j];                                                                         
                        }                                                                                                                                           
                        cout << matrix_mas5[i][j] << " ";
                }                                                                                                                                                   
        cout << endl;                                                                                                                                               
        }                                                                                                                                                           
                                                                                                                                                                    
        //РІС‹С‡РёСЃР»РµРЅРёРµ С‚СЂР°РЅСЃРїРѕРЅРёСЂРѕРІР°РЅРЅРѕР№ РјР°С‚СЂРёС†С‹
        cout << "The transposed matrix: " << endl;
        for (int i = 0; i<m; i++) {
                for (int j = 0; j<n; j++) {
                        matrix_mas4[j][i] = matrix_mas1[i][j];                                                                                                      
                }                                                                                                                                                   
        }                                                                                                                                                           
                                                                                                                                                                    
        //РІС‹РІРѕРґ С‚СЂР°РЅСЃРїРѕРЅРёСЂРѕРІР°РЅРЅРѕР№ РјР°С‚СЂРёС†С‹ РІ С„Р°Р№Р» matrixt.txt
        ofstream out_file("matrixt.txt");
        for (int i = 0; i<n; i++) {
                for (int j = 0; j<m; j++) {
                        out_file << matrix_mas4[i][j] << " ";
                        cout << matrix_mas4[i][j] << " ";
                }                                                                                                                                                   
                out_file << "\n";
				cout << endl;                                                                                                                                       
        }                                                                                                                                                           
        out_file.close();                                                                                                                                           
                                                                                                                                                                    
        //СѓРґР°Р»РµРЅРёРµ РґРІСѓРјРµСЂРЅС‹С… РјР°СЃСЃРёРІРѕРІ
        for (int i = 0; i < m; i++){
                delete[] matrix_mas1[i];
                delete[] matrix_mas2[i];
                delete[] matrix_mas3[i];
                delete[] matrix_mas4[i];
                delete[] matrix_mas5[i];
        }                                                                                                                                                           
        delete[] matrix_mas1;
        delete[] matrix_mas2;
        delete[] matrix_mas3;
        delete[] matrix_mas4;
        delete[] matrix_mas5;
                                                                                                                                                                    
        return 0;
}
