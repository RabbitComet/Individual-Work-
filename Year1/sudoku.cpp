#include<iostream>
#include<vector>
#include<math.h>

bool hori_vert(std::vector<std::vector<int>> board,int size, int x, int y){
	
	for(int i = 0; i< size; i++){
		if((board[y][i] == board[y][x] && i != x) || (board[i][x] == board[y][x] && i != y)){
			return false;
		}
	}	

	return true;

}

bool check_box(std::vector<std::vector<int>> board,int size, int x, int y){
	
	int side_root = sqrt(size);
	
	int x_mult = 0;
	int y_mult = 0;

	for(int i = 1 ; i < side_root;i++){
		if(x>=side_root*i){
			x_mult++;
		}	
		if(y>=side_root*i){
			y_mult++;
		}
	}	
	
	int box_start_x = side_root * x_mult;
	int box_start_y = side_root * y_mult;

	for(int i = box_start_y; i < box_start_y + side_root; i++){
	
		for(int j  = box_start_x; j < box_start_x + side_root; j++){
	
			if(board[i][j] == board[y][x] && &board[i][j] != &board[y][x]){
				return false;
			}
	
		}
	}

	return true;
}

bool run_checks(std::vector<std::vector<int>> board, int size, int x, int y){
	return hori_vert(board,size,x,y) && check_box(board, size, x, y);
}

int num_len(int num){
	int len = 0;

	for(int i = num; i > 0; i/=10){
		len++;
	}

	if(len==0) return 1;
	
	return len;
	
}

void show_board(std::vector<std::vector<int>> board, int size){
	int space_total = 1 + num_len(size);
	
	for(int i = 0 ; i < size; i++){
	
		for(int j = 0 ; j < size ; j++){
	
			std::cout<< board[i][j] << std::string( space_total - num_len( board[i][j] ) , ' ' );
	
			if( j % (int)sqrt(size) == sqrt(size) - 1 && j!= size - 1){
	
				std::cout<< "|" << std::string( space_total - 1 , ' ' );
	
			}
	
		}
	
		std::cout<<std::endl;
	
		if(i%(int)sqrt(size) == sqrt(size)-1 && i != size-1){
	
			std::cout<<std::string(size*space_total + ((int)sqrt(size)-1)*space_total,'-')<<std::endl;
	
		}
	}
}

bool solve_sudoku(std::vector<std::vector<int>> board,int size ,int x = 0, int y = 0){ 
	
	if(y == size){
		show_board(board, size);
		return true;			
	}

	int initial_num = board[y][x];

	for(int i = 1; i<=size; i++){
		
		if(initial_num != 0){
			i = size + 1;
		}
		else{
			board[y][x] = i;
		}

		if(run_checks(board,size,x,y)){
	
			if(x<size-1){
				if(solve_sudoku(board,size,x+1,y)){
					return true;
				}
			}
			else{
				if(solve_sudoku(board,size,0,y+1)){
					return true;
				}
			}
		}
	}

	return false;
	
}



int main(){
	
	int size = 4;

	std::cout<<"How big do you want your sudoku board: ";

	std::cin>> size; 

	std::vector<std::vector<int>> sudoku_board;
	std::vector<int> zero_vect;

	for(int i = 0; i < size; i++){
		zero_vect.push_back(0);
	}

	for(int i = 0; i < size; i++){
		sudoku_board.push_back(zero_vect);
	}
	

	int x,y,inputs,input;

	std::cout<<"How many numbers do you want to input manually.";
	std::cin>>inputs;

	for(int i = 0; i< inputs; i++){
		std::cout<<"Row(y): ";
		std::cin>>y;
	
		std::cout<<"Column(x): ";
		std::cin>>x;
	
		std::cout<<"Number: ";
		std::cin>>input;

		sudoku_board[y][x] = input;
	}

	show_board(sudoku_board, size);

	std::cout<<std::endl;
	std::cout<<"Press enter to solve\n";
	std::cin.ignore();
	std::cin.ignore();

	if(!solve_sudoku(sudoku_board,size)){
		std::cout<<"No Solution";
	}

	return 0;
}
