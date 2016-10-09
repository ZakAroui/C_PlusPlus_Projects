#include <iostream>
#include <fstream>
using namespace std;

void readpuzzle ( int grid[][9]);
bool isValid(int i, int j, int grid[][9]);
bool isValid(int grid[][9]);
void printGrid(int grid[] [9]);

int main()
    {                                                                         //main
    int grid [9][9] = {{6,2,4,5,3,9,1,8,7},{5,1,9,7,2,8,6,3,4},{8,3,7,6,1,4,2,9,5},{1,4,3,8,6,5,7,2,9},{9,5,8,2,4,7,3,6,1},{7,6,2,3,9,1,4,5,8},{3,7,1,9,5,6,8,4,2},{4,9,6,1,8,2,5,7,3},{2,8,5,4,7,3,9,1,6}};

    //readpuzzle (grid);

      if (!isValid(grid))
        cout << "Invalid input" << endl;
      else if (isValid(grid)){
        cout<<"The solution is correct"<<endl;
        printGrid(grid);}

    return 0;
    }                                                                         //end main

    void readpuzzle (int grid[][9])
    {                                                                       //readpuzzle
      // Create a Scanner
      cout << "Enter a Sudoku puzzle:" << endl;

      for (int i = 0; i < 9; i++){
          cout<<"enter "<<i<<"th row"<<endl;
          for (int j = 0; j < 9; j++)
             cin >> grid[i] [j];
      }
      cout << "Well!!" << endl;
    }                                                                        //end readpuzzle

    bool isValid(int i, int j, int grid[] [9])
    {                                                                        //isValid
      // Check whether grid[i][j] is valid at the i's row
  for (int column = 0; column < 9; column++)
        if (column != j && grid[i] [column] == grid[i] [j])
          return false;

      // Check whether grid[i][j] is valid at the j's column
      for (int row = 0; row < 9; row++)
        if (row != i && grid[row] [j] == grid[i] [j])
          return false;

      // Check whether grid[i][j] is valid in the 3 by 3 box
      for (int row = (i / 3) * 3; row < (i / 3) * 3 + 3; row++)
        for (int col = (j / 3) * 3; col < (j / 3) * 3 + 3; col++)
          if (row != i && col != j && grid[row] [col] == grid[i] [j])
            return false;

      return true; // The current value at grid[i][j] is valid
    }                                                                       //end isValid

    /** Check whether the fixed cells are valid in the grid */
    bool isValid(int grid[][9])
    {                                                                       //isValid 2
      // Check for duplicate numbers                                        //
      for (int i = 0; i < 9; i++)                                           //
        for (int j = 0; j < 9; j++)                                         //
          if (grid[i][j] != 0)                                              //
            if (!isValid(i, j, grid))                                       //
              return false;                                                 //
                                                                            //
      // Check whether numbers are in the range                             //
      for (int i = 0; i < 9; i++)                                           //
        for (int j = 0; j < 9; j++)                                         //
          if ((grid[i][j] <= 0) || (grid[i][j] > 9))                        //
            return false;                                                   //
                                                                            //
      return true; // The fixed cells are valid                             //
    }                                                                       //end isValid 2

    /** Print the values in the grid */
    void printGrid(int grid[] [9])
    {                                                                       //printGrid
      cout << endl;
      for (int i = 0; i < 9; i++)                                           //
      {                                                                     //
        for (int j = 0; j < 9; j++){                                         //
          cout << grid[i] [j] << " ";                                       //
          if(j==2 || j==5)
              cout<<"| ";
        }
        cout << endl;                                                         //
        if(i==2 || i==5){
        for(int j=0; j<7; j++)
            cout<<"---";
        }
        cout<<endl;
      }                                                                     //
    }                                                                       //end printGrid
