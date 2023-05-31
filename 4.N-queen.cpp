#include <bits/stdc++.h>
#include <chrono>
using namespace std::chrono;
using namespace std;

void display(vector<vector<int>> board, int N)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << board[i][j] << " ";
        }
        cout << "\n";
    }
}

bool isSafe(int row, int col, vector<bool> rows, vector<bool> left_digonals, vector<bool> Right_digonals,int N)
{
    if (rows[row] == true || left_digonals[row + col] == true || Right_digonals[col - row + N - 1] == true)
    {
        return false;
    }
    return true;
}

bool bbound(vector<vector<int>> &board, int col, vector<bool> rows, vector<bool> left_digonals, vector<bool> Right_digonals, int N)
{
    if (col >= N)
    {
        return true;
    }
    for (int i = 0; i < N; i++)
    {
        if (isSafe(i, col, rows, left_digonals, Right_digonals,N) == true)
        {
            rows[i] = true;
            left_digonals[i + col] = true;
            Right_digonals[col - i + N - 1] = true;
            board[i][col] = 1;
            if (bbound(board, col + 1, rows, left_digonals, Right_digonals,N) == true)
            {
                return true;
            }
            rows[i] = false;
            left_digonals[i + col] = false;
            Right_digonals[col - i + N - 1] = false;
            board[i][col] = 0;
        }
    }
    return false;
}

bool is_possible(int row, int col, vector<vector<int>> &board, int n)
{
    int duprow = row;
    int dupcol = col;
    while (row >= 0 && col >= 0)
    {
        if (board[row][col] == 1)
        {
            return false;
        }
        row--;
        col--;
    }
    row = duprow;
    col = dupcol;
    while (col >= 0)
    {
        if (board[row][col] == 1)
        {
            return false;
        }
        col--;
    }
    col = dupcol;
    row = duprow;
    while (row < n && col >= 0)
    {
        if (board[row][col] == 1)
        {
            return false;
        }
        row++;
        col--;
    }
    return true;
}
bool btracker(vector<vector<int>> &board, int col, int n)
{
    if (col == n)
    {
        return true;
    }
    for (int i = 0; i < n; i++)
    {
        if (is_possible(i, col, board, n))
        {
            board[i][col] = 1;
                if(btracker(board,col+1,n)){
                return true;
                }
                board[i][col] = 0;
        }
    }
    return false;
}

void back_tracking(vector<vector<int>> &board)
{
    if (btracker(board, 0, board.size()))
    {
        cout << "solution is possible\n";
        display(board, board.size());
    }
    else
    {
        cout << "NO possible solution exist\n";
    }
}

void branch_bound(vector<vector<int>> &board)
{
    int n = board.size();
    vector<bool> rows(n, 0);
    vector<bool> left_digonals(2 * n - 1, 0);
    vector<bool> Right_digonals(2 * n - 1, 0);

    if (bbound(board, 0, rows, left_digonals, Right_digonals, board.size()))
    {
        cout << "solution is possible\n";
        display(board, n);
    }
    else
    {
        cout << "NO possible solution exist\n";
    }
}

int main()
{
    int n;
    cout << "Enter the number of queens";
    cin >> n;

    int ch;
    bool flag = true;
    while (flag)
    {
        cout << "-------MENU----------\n";
        cout << "ENter the correct choice number\n";
        cout << "1.Using bactraking\n";
        cout << "2.using Branch bound\n";
        cout << "\n";
        cin >> ch;
        if (ch == 1)
        {
                vector<vector<int>> board(n, vector<int>(n, 0));
                // auto start = high_resolution_clock::now();

                back_tracking(board);

                // auto stop = high_resolution_clock::now();

                // auto duration = duration_cast<microseconds>(stop - start);

                // cout << "Time taken by backtracking solution: " << duration.count() << " microseconds" << endl;
        }
        else if (ch == 2)
        {
                vector<vector<int>> board(n, vector<int>(n, 0));
                // auto start = high_resolution_clock::now();

                branch_bound(board);

                // auto stop = high_resolution_clock::now();

                // auto duration = duration_cast<microseconds>(stop - start);

                // cout << "Time taken by brach bound solution: " << duration.count() << " microseconds" << endl;
        }
        else
        {
                flag = false;
                break;
        }
    }

    return 0;
}