#include <iostream>
#include <string>
#include <vector>


class board{

	void place_queen(int r, int c);
	voide remove_queen(int r, int c);
	bool is_free(int r, int c)const;

	void print()const;

	private:
		vector<vector<int>> s;
};

board::board(){
	s.resize(8, vector<int>(8,0));
}

void board::place_queen(int r, int c){
	if  (r < 8 && c<8 && r>=0 && c>=0 && s.at(r).at(c)== 0){
		for (int j = 0; j < 8; j++){
			s.at(j).at(c)++;  // column
			s.at(r).at(j)++;  // row

			if (c-r+j>= 0 && c-r+j < 8){ // main diagonal
				s.at(j).at(c-r+j)++;

			if (c+r-j>= 0 && c-r+j<8){
				s.at(j).at(c+r-j)++;
			}
			s.at(r).at(c) = -1;
		}
	}

	void board::remove_queen(int r, int c){
		if (r<8 && c<8 && r>= 0 && c>= 0 && s.at(r).at(c) == -1){
			for (int j=0; j<8; j++){
				s.at(j).at(c)--;
				s.at(r).at(j)--;

				if (c-r+j >= 0 && c-r+j < 8){
					s.at(j).at(c-r+j)--;
				}
				if (c+r-j >=0 && c+r-j<8){
					s.at(j).at(c+r-j)--;
				}
				s.at(r).at(c) = 0;
			}
		}

		bool board::is_free(int r, int c)const{
			return (s.at(r).at(c) == 0);
		}
		

		
	}
}

	
