#include <iostream>
#include <vector>

const int N = 9;

bool isSafe(const std::vector<std::vector<int>>& board, int row, int col, int num) {
    // Cek pada baris
    for (int x = 0; x < N; ++x) {
        if (board[row][x] == num) {
            return false;
        }
    }

    // Cek pada kolom
    for (int x = 0; x < N; ++x) {
        if (board[x][col] == num) {
            return false;
        }
    }

    // Cek pada subgrid 3x3
    int startRow = row - row % 3;
    int startCol = col - col % 3;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[i + startRow][j + startCol] == num) {
                return false;
            }
        }
    }

    return true;
}

bool findEmptyPosition(const std::vector<std::vector<int>>& board, int& row, int& col) {
    for (row = 0; row < N; ++row) {
        for (col = 0; col < N; ++col) {
            if (board[row][col] == 0) {
                return true; // Ditemukan sel kosong
            }
        }
    }
    return false; // Tidak ada sel kosong
}

bool solveSudoku(std::vector<std::vector<int>>& board) {
    int row, col;

    if (!findEmptyPosition(board, row, col)) {
        return true; // Semua sel sudah terisi
    }

    for (int num = 1; num <= 9; ++num) {
        if (isSafe(board, row, col, num)) {
            // Tempatkan angka pada sel
            board[row][col] = num;

            // Rekursif untuk mencoba angka selanjutnya
            if (solveSudoku(board)) {
                return true;
            }

            // Jika tidak berhasil, reset sel menjadi 0
            board[row][col] = 0;
        }
    }

    return false; // Tidak ada solusi untuk posisi ini
}

void printSudoku(const std::vector<std::vector<int>>& board) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            std::cout << board[i][j] << " ";
        }
        std::cout << '\n';
    }
}

int main() {
    std::vector<std::vector<int>> sudokuBoard(N, std::vector<int>(N, 0));

    std::cout << "Masukkan papan Sudoku (gunakan angka 0 untuk sel kosong):\n";
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            std::cin >> sudokuBoard[i][j];
        }
    }

    if (solveSudoku(sudokuBoard)) {
        std::cout << "Solved Sudoku:\n";
        printSudoku(sudokuBoard);
    } else {
        std::cout << "No solution exists.\n";
    }

    return 0;
}

