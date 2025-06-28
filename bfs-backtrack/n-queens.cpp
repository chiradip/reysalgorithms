/*
Problem Statement: There is a chesssboard on size N X N, and N number of queens. You have to find how many ways 
you can place N queens in the board so that no queen can attack no other queen.
2 queens are in attacking position if - they share same ROW OR same COL or same DIAGONAL or same Anti-DIAGONAL.
*/

poss_boards = 0;

def possible_boards(N: Int): Int {
	// DO THE MAGIC Here 
	dfs_backtrack(0 /*RowIndex*/, N, new_list);
	return poss_boards;
}

def dfs_backtrack(row-idx, N, board /*the board under construction*/) {
	if (row-idx == N) {
		// I have a finished board 
		poss_boards += 1;
		return;
	}
	for (col-idx <- 0 until N) {
		if (is_legal(row-idx, col-idx, board, N)) {
			board.addLast(col-idx /*at row-idx*/);
			dfs_backtrack(row-idx + 1, N, board);
			board.removeLast(); // backtracking 
		}
	}
}

def is_legal(row-idx, col-idx, board, N /*size of the board*/): bool {
	for (r <- 0 until row-idx) {
		c = board.get(r);
		if (row-idx + col-idx == r + c || row-idx - col-idx == r - c || col-idx == c) return false;
	}
	return true;
}