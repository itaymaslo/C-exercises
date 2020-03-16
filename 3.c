# include<stdio.h>
# include<stdlib.h>

int** init_square(int square_size);  
void print_square(int** square, int square_size);  
void generate_magic_square(int** square, int square_size); 
void free_square(int** square, int square_size); 

int EMPTY_CELL_VALUE = 0;

int main() {
	/*
 	* Exercise 3 - Generating magic squares.
 	*/
	int square_size = 0;
	
	printf("Choose the size of the magic square : ");
	scanf("%d", &square_size);

	if (square_size % 2 == 0) {
		printf("Error! da la Loubere's only works for odd sizes, please choose odd size next time\n");
		return 1;
	}	

	int** square = init_square(square_size);
	generate_magic_square(square, square_size);
	print_square(square, square_size);
	
	free_square(square, square_size);
	return 0;
}

int** init_square(int square_size) {
	/*
 	* Malloc and give initial values to the cells in the square.
 	*/ 
	int** square = (int**)malloc(square_size * sizeof(int*));

	for (int i = 0; i < square_size; ++i) {
		square[i] = (int*)malloc(square_size * sizeof(int));
		for (int j = 0; j < square_size  ; ++j)
			square[i][j] = EMPTY_CELL_VALUE;
	}
	return square;
}

void generate_magic_square(int ** square, int square_size) {
	/*
 	* Make the given empty square a magic square,
 	* using the da la Lounere's method.
 	*/
	int col = square_size / 2;
	int row = 0;
	
	for (int i = 1; i <= square_size * square_size; ++i) {
		square[row][col] = i;
		int new_col = col + 1;
		int new_row = row - 1;
		
		if (new_col == square_size)
			new_col = 0;
		if (new_row == -1)
			new_row = square_size - 1;
		
		if (square[new_row][new_col] == EMPTY_CELL_VALUE) {
			col = new_col;
			row = new_row;
		}

		else {
			if (row == square_size - 1)
				row = 0;
			else
				row++;
		}
	}
}

int count_digits(int num) {
	int count = 0;
	while(num != 0) {
		num /= 10;
		++count;
	}
	return count;
}

void  print_square(int** square, int square_size) {
	int space_max = count_digits(square_size * square_size) + 1;
	for (int i = 0; i < square_size; ++i) {
		for (int j = 0; j < square_size; ++j) {
			int spaces = space_max - count_digits(square[i][j]);
			printf("%d",square[i][j]);
			for (int t = 0; t < spaces; ++t)
				printf(" ");
		}
		printf("\n");
	};
	printf("\n");
}

void free_square(int** array, int square_size) {
	for (int i = 0; i < square_size; i++)
		free(array[i]);
	free(array);
}

