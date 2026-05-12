#include <iostream>
#include <vector>
#include <ostream>

class TicTacToe {
public:
    const size_t N; 
    const size_t K; 
private:
    std::vector<std::vector<int>> Table;

    int currentPlayer;

public:
    TicTacToe(size_t n, size_t k): N(n), K(k), currentPlayer(1) {
        Table.resize(N);
        for (size_t i = 0; i != N; ++i) {
            Table[i].assign(N, 0);
        }
    }

    int operator()(size_t i, size_t j) const {
        return Table[i][j];
    }

    int GetCurrentPlayer() const {
        return currentPlayer;
    }

    bool Set(size_t i, size_t j) {
        Table[i][j] = currentPlayer;
        currentPlayer = currentPlayer % 2 + 1;
        bool wins = CheckRow(i, j) || CheckColumn(i, j) || CheckDiagonal1(i, j) || CheckDiagonal2(i, j);
        return wins;
    }

private:
    bool CheckRow(size_t i, size_t j) const {
        size_t d1 = 0;
        while (d1 <= j && Table[i][j - d1] == Table[i][j]) {
            ++d1;
        }

        size_t d2 = 0;
        while (j + d2 < N && Table[i][j + d2] == Table[i][j]) {
            ++d2;
        }
        return d1 + d2 > K;
    }

    bool CheckColumn(size_t i, size_t j) const {
        size_t d1 = 0;
        while (d1 <= i && Table[i - d1][j] == Table[i][j]) {
            ++d1;
        }

        size_t d2 = 0;
        while (i + d2 < N && Table[i + d2][j] == Table[i][j]) {
            ++d2;
        }
        return d1 + d2 > K;
    }

    bool CheckDiagonal1(size_t i, size_t j) const {
        size_t d1 = 0;
        while(i + d1 < N and j + d1 < N and Table[i + d1][j + d1] == Table[i][j]) {
            ++d1;
        }
        size_t d2 = 0;
        while (i >= d2 and j >= d2 and Table[i - d2][j - d2] == Table[i][j])
        {
            ++d2;
        }
        return d1 + d2 > K;
    }

    bool CheckDiagonal2(size_t i, size_t j) const {
        size_t d1 = 0;
        while(i + d1 < N and j >= d1 and Table[i + d1][j - d1] == Table[i][j]) {
            ++d1;
        }
        size_t d2 = 0;
        while (i >= d2 and j + d2 < N and Table[i - d2][j + d2] == Table[i][j])
        {
            ++d2;
        }
        return d1 + d2 > K;
    }
};

    std::ostream& operator << (std::ostream& out, TicTacToe& field) {
    for (size_t i = 0; i != field.N; ++i) {
        for (size_t j = 0; j != field.N; ++j) {
            switch (field(i, j)) {
                case 0:
                    std::cout << '.';
                    continue;
                case 1:
                    std::cout << 'X';
                    continue;
                case 2:
                    std::cout << 'O';
            }
        }
        std::cout << "\n";
    }
    return out;
}