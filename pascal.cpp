#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

// Build Pascal's triangle with n rows
vector<vector<long long>> buildTriangle(int rows)
{
    vector<vector<long long>> tri(rows);

    for (int i = 0; i < rows; i++)
    {
        tri[i].resize(i + 1);

        for (int j = 0; j <= i; j++)
        {
            if (j == 0 || j == i)
                tri[i][j] = 1;
            else
                tri[i][j] = tri[i - 1][j - 1] + tri[i - 1][j];
        }
    }
    return tri;
}

// Print Pascal's triangle visually
void printTriangle(const vector<vector<long long>>& tri)
{
    int rows = tri.size();

    for (int i = 0; i < rows; i++)
    {
        cout << string((rows - i) * 2, ' ');
        for (long long val : tri[i])
        {
            cout << setw(4) << val;
        }
        cout << endl;
    }
}

int readRows()
{
    while (true)
    {
        cout << "Enter number of rows (1–40): ";
        int n;
        cin >> n;

        if (cin.fail() || n < 1 || n > 40)
        {
            cin.clear();
            cin.ignore(256, '\n');
            cout << "Invalid input. Try again." << endl;
        }
        else
        {
            return n;
        }
    }
}

int main()
{
    int rows = readRows();

    auto triangle = buildTriangle(rows);

    cout << "\nPascal Triangle:\n";
    printTriangle(triangle);

    cout << "\nRow values:\n";
    for (size_t i = 0; i < triangle.size(); i++)
    {
        cout << i << ": ";
        for (size_t j = 0; j < triangle[i].size(); j++)
        {
            cout << triangle[i][j];
            if (j + 1 < triangle[i].size())
                cout << ",";
        }
        cout << endl;
    }

    cout << "\nPress ENTER to exit.";
    cin.ignore();
    cin.get();

    return 0;
}
