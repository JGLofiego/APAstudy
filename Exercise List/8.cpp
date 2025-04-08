#include<iostream>
#include<vector>
using namespace std;

bool result;

void procura(vector<vector <int> > matrix, vector<vector <bool> > visited, int i, int j){
	if(i >= 0 && i < 5 && j >= 0 && j < 5 && !result){
		visited[i][j] = true;
		if(i == 4 && j == 4)
			result = true;
		else
		{
			// vai para baixo, cima, esquerda ou direita
			if(i + 1 < 5 && matrix[i + 1][j] == 0 && !visited[i + 1][j])
				procura(matrix, visited, i + 1, j); //direita
				
			if(i - 1 >= 0 && matrix[i - 1][j] == 0 && !visited[i - 1][j])
				procura(matrix, visited, i - 1, j); //esquerda
				
			if(j + 1 < 5 && matrix[i][j + 1] == 0 && !visited[i][j + 1])
				procura(matrix, visited, i, j + 1); //baixo
				
			if(j - 1 >= 0 && matrix[i][j - 1] == 0 && !visited[i][j - 1])
				procura(matrix, visited, i, j - 1);//cima
		}
	}
}

int main(){
	int cases;
	int aux;
	
	cin >> cases;
	
	for(int i = 0; i < cases; i++){
		
		vector<vector <int> > mat(5, vector<int> {0, 0, 0, 0, 0});
		vector<vector <bool> > visited(5, vector<bool>{false, false, false, false, false});
		
		// for(j = 0; j < 5; j++){
		// 	mat[j].resize(5); //redimensionar
		// 	coordenadas[j].resize(5);//redimensionar
		// }

		for(int j = 0; j < 5; j++){
			for(int k = 0; k < 5; k++){
				cin >> aux;
				mat[j][k] = aux;
			}
		}

		result = false;
		procura(mat, visited, 0, 0);
		
		if(result)
			cout << "COPS" <<endl;
		else
			cout << "ROBBERS" << endl;
	}
}