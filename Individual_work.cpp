#include<iostream>
#include<vector>

int board_size;

//Time Compleixity of O(n), where n is the length of the board.
void hori_vert(std::vector<std::vector<int>>& board, int x, int y){
	for(int i = 0 ; i < board_size; i++){
		board[0+i][x] = 1;
		board[y][0+i] = 1;	
	}
}

//Time Complexity of O(n), n is the distance from the edges
void secondary_diagonal(std::vector<std::vector<int>>& board, int x, int y){

	int curr_x = x-1;
	int curr_y = y+1;
	
	while(curr_x >= 0 && curr_y < board_size){
		board[curr_y][curr_x] = 1;
		curr_x--;
		curr_y++;
	}

	curr_x = x+1;
	curr_y = y-1;

	while(curr_x < board_size && curr_y >= 0){
		board[curr_y][curr_x] = 1;
		curr_x++;
		curr_y--;
	}

}

//Time Complexity of O(n), n is the distance from the edges
void main_diagonal(std::vector<std::vector<int>>& board, int x, int y){

	int curr_x = x+1;
	int curr_y = y+1;
	
	while(curr_x < board_size && curr_y < board_size){
		board[curr_y][curr_x] = 1;
		curr_x++;
		curr_y++;
	}

	curr_x = x-1;
	curr_y = y-1;

	while(curr_x >= 0 && curr_y >= 0){
		board[curr_y][curr_x] = 1;
		curr_x--;
		curr_y--;
	}

}

//Time complexity of O(n), n is the length of the board.
void mark_occupied(std::vector<std::vector<int>>& board, int x, int y) {
	//Horizontal and vertical	
	hori_vert(board, x, y);
	//second diagonal
	secondary_diagonal(board, x, y);
	//main diagonal
	main_diagonal(board, x, y);
	//marking the Queen
	board[y][x] = 2;
}

//Time complexity of O(n^2), where n is the length of the board
void show_board(std::vector<std::vector<int>> board){
    	for (int i = 0; i < board_size; i++) {
    		for (int j = 0; j < board_size; j++) {
		    	if(board[i][j] == 1 && (i+j)%2 == 0){
				std::cout<< "⬜";
			}
			else if(board[i][j] == 1){
				std::cout<<"⬛";
			}
			else{
				std::cout<<"♛ ";
			}
		}
		std::cout << std::endl;
    	}

	std::cout<<std::endl;
}

//Time complexity of O(n!), n is the length of the board.
bool queen_board(std::vector<std::vector<int>> board, int x, int y, int count = 0) {
		
	mark_occupied(board, x, y);
	count++;

	if (count == board_size) {
		show_board(board);
		return true;    
	    
	}

	for (int i = 0; i < board_size ; i++) {
		if(board[y+1][i] == 0){
			if (queen_board(board, i, y+1, count)) return true;
		}
	}
	
	return false;


}


//Overall, O(n!).
int main() {

	std::cout<<"How long is the side of the board: ";

	std::cin>>board_size;

	std::cout<<std::endl;

	std::vector<std::vector<int>> board = {};

	std::vector<int> zero_vector = {};
	//O(n), n is length of the board
	for (int i = 0; i < board_size; i++) {
		zero_vector.push_back(0);
	}


	//O(n), n is length of the board
	for (int i = 0; i < board_size; i++) {
		board.push_back(zero_vector);
	}

	//O(n*n!)->O(n!)
    	for (int j = 0; j < board_size; j++) {
    		if(queen_board(board,j,0)) return 0;
    	}
    	

    	std::cout<<"No possible solutions.";

	return 0;
}
