
 /*
 LoShuMagicSquare
*/

#include <iostream>
#include <iomanip>
using namespace std;

// Global constants 
const int ROWS = 3;  
const int COLS = 3;  
const int MIN = 1;  
const int MAX = 9;  

// Function prototypes
bool isMagicSquare(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size);
bool checkRange(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size, int min, int max);
bool checkUnique(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size);
bool checkRowSum(int arrayrow1[], int arrayrow2[], int arrayrow3[], int size);
bool checkColSum(int arrayrow1[], int arrayrow2[], int arrayrow3[], int size);
bool checkDiagSum(int arrayrow1[], int arrayrow2[], int arrayrow3[], int size);
void fillArray(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size);
void showArray(int arrayrow1[], int arrayrow2[], int arrayrow3[], int size);

int main()
{
  const int ARRAY_SIZE = 3;
  int arrayRow1[ARRAY_SIZE], // stores the first row of the magic square
      arrayRow2[ARRAY_SIZE], // stores the second row
      arrayRow3[ARRAY_SIZE]; // stores the third row
  //determines if the user wants to try another guess of a magic square
  char shouldContinue = 'y';

  // repeats depending on whether wants to try againg
  while (shouldContinue == 'y' || shouldContinue == 'Y')
  {
    //calls the fillArray function that promts the user for values to insert into the arrays
    fillArray(arrayRow1, arrayRow2, arrayRow3, ARRAY_SIZE);
    // calls the showArray function which displays the magic Square
    showArray(arrayRow1, arrayRow2, arrayRow3, ARRAY_SIZE);
    //calls the isMagicSquare function which determines if the values 
    //the user inputs forms a magic square
    bool magicSquare = isMagicSquare(arrayRow1, arrayRow2, arrayRow3, ARRAY_SIZE);

    // informs the user that the values form a magic square or not
    if(magicSquare)
      cout << "This is a Lo Shu Magic Square.\n";
    else 
      cout << "This is not a Lo Shu Magic Square.\n";
    
    // ask the user whether they want to input more squares
    cout << "\nDo you want to try agin(y/n): ";
    cin >> shouldContinue;
  }   


  return 0;

}


/*
  this function receives three arrays as parameters, promts the user for numbers,
  and store the numbers in each of the array according to the row
*/
void fillArray(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size)
{
    int row = 1; //each row in the square
    // the first row
    for (int col = 0; col < size; col ++)
    {
      // validates the input of each cell
        do {
         cout << "Enter the number for row " << row << " column " <<(col + 1) << ": ";
         cin >>  arrayRow1[col];  
         if(arrayRow1[col] < MIN || arrayRow1[col] > MAX)
            cout << "Number should be between "<< MIN << " and "<< MAX << endl;
        } while (arrayRow1[col] < MIN || arrayRow1[col] > MAX);

    }
    row++; // increments the row
    // the second row
    for (int col = 0; col < size; col ++)
    {
        do {
         cout << "Enter the number for row " << row << " column "<<(col + 1) << ": ";
         cin >>  arrayRow2[col];  
         if(arrayRow2[col] < MIN || arrayRow2[col] > MAX)
            cout << "Number should be between "<< MIN << " and "<< MAX << endl;
        } while (arrayRow2[col] < MIN || arrayRow2[col] > MAX);

    }
    
    row ++; // increments to the third row
    // the third row
    for (int col = 0; col < size; col ++)
    {
        do {
         cout << "Enter the number for row " << row << " column "<<(col + 1) << ": ";
         cin >>  arrayRow3[col];  
         if((arrayRow3[col] < MIN || arrayRow3[col] > MAX))
            cout << "Number should be between "<< MIN << " and "<< MAX << endl;
        } while (arrayRow3[col] < MIN || arrayRow3[col] > MAX);

    }
    
}


/*
 This function takes three arrays as parameters and displays them
 on the console
*/

void showArray(int arrayrow1[], int arrayrow2[], int arrayrow3[], int size)
{
  // displays the square to the screen
  for (int row = 0; row < size; row++)
  {
    for (int col = 0; col <size; col++){
      if(row == 0)
        cout << setw(5) << arrayrow1[col];
      else if(row == 1)
        cout << setw(5) << arrayrow2[col];
      else if(row == 2)
        cout << setw(5) << arrayrow3[col];
    }
    cout << endl;
  }
}

/*
  this function takes 3 one dimensional arry of numbers and the size of the arrays as parameters 
  it then test to see if all the numbers in an array meets the condition of a Lo Shu Square
  magic square
*/
bool isMagicSquare(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size)
{
  //checks if all the values in the arrays are within the range of MIN=1 and MAX=9
  bool isWithinRange = checkRange(arrayRow1, arrayRow2, arrayRow3, size, MIN, MAX);
  // checks if the arrays have unique values
  bool isUnique = checkUnique(arrayRow1, arrayRow2, arrayRow3, size);
  //checks if the sum of rows of the square are equal
  bool isRowSumEqual = checkRowSum(arrayRow1, arrayRow2, arrayRow3, size);
  //checks if the sum of the columns of the square are equal
  bool isColumnSumEqual = checkColSum(arrayRow1, arrayRow2, arrayRow3, size);
  //checks if the sum of the diagonals is the same
  bool isDiagonalSumEqual = checkDiagSum(arrayRow1, arrayRow2, arrayRow3, size);

  //returns true or false depending on whether the square meets the requirement of a magic square
  if(isWithinRange && isUnique && isRowSumEqual && isColumnSumEqual && isDiagonalSumEqual)
    return true;
  return false;

}

/*
  this function checks whether all the values in 3 arrays are within the rang of 1 and 9
  it returns true if the the values meet the requirement else it returns false
*/
bool checkRange(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size, int min, int max)
{
  // determines whether the arrays' values are within 1 and 9
  for(int row = 0; row < size; row++)
  {
    if(arrayRow1[row] < min || arrayRow1[row] > max)
      return false;
    else if (arrayRow2[row] < min || arrayRow2[row] > max)
      return false;
    else if (arrayRow3[row] < min || arrayRow3[row] > max)
      return false;
  }
  return true;
}


//this function checks whether the arrays have unique values
bool checkUnique(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size)
{
  // stores all the 3 array elements into one array
  int allValues[9] = {arrayRow1[0], arrayRow1[1], arrayRow1[2],
                              arrayRow2[0], arrayRow2[1], arrayRow2[2],
                              arrayRow3[0], arrayRow3[1], arrayRow3[2]};
  // the size of the bigger array
  size *= 3;
  //checks to see if the array values are unique
  for (int value1 =0; value1 < size; value1++)
  {
    for (int value2 = value1+1; value2 < size; value2++)
    {
      if(allValues[value1] == allValues[value2])
        return false;
    }
  }
  return true;
}

/*
  This function sums the values in 3 seperate arrays and returns true if their 
  sum are the same and vice versa
*/
bool checkRowSum(int arrayrow1[], int arrayrow2[], int arrayrow3[], int size)
{
  int rowSum1=0, //stores the sum of all the values in the first array
      rowSum2=0, //stores the sum of all the values in the second array
      rowSum3=0;//stores the sum of all the values in the third array

  for(int row = 0; row < size; row++)
  {
    rowSum1 += arrayrow1[row];
    rowSum2 += arrayrow2[row];
    rowSum3 += arrayrow3[row];
  }
  //ensures all the sum of each array is the same as the other
  if (rowSum1 == rowSum2 && rowSum2== rowSum3)
    return true;
  return false;

}

//this function checks whether the sum of each column in the squre corresponds
//to the other
bool checkColSum(int arrayrow1[], int arrayrow2[], int arrayrow3[], int size)
{
  int columnSum1=0, // stores the sum of the first column
      columnSum2=0, // sum of the second column
      columnSum3=0; // sum of the third column
  // loops through each column addiding the values to the respective columnSum variable
  for(int col = 0; col < size; col++)
  {
    // first column
    if(col ==0)
    {
      columnSum1 += arrayrow1[col];
      columnSum1 += arrayrow2[col];
      columnSum1 += arrayrow3[col];
    }
    //second column
    else if (col == 1)
    {
      columnSum2 += arrayrow1[col];
      columnSum2 += arrayrow2[col];
      columnSum2 += arrayrow3[col];
    }
    //third column
    else {
      columnSum3 += arrayrow1[col];
      columnSum3 += arrayrow2[col];
      columnSum3 += arrayrow3[col];
    }
  }
  // checks if the sum of each column corresponds to the other
  if(columnSum1 == columnSum2 && columnSum2 == columnSum3)
    return true;
  return false;
}


/*
  This function receives 3 arrays and their size as a parameter
  it then returns true if the sum of their diagonal is the sam else it
  returns false
*/
bool checkDiagSum(int arrayrow1[], int arrayrow2[], int arrayrow3[], int size)
{
  //the first diagonal of the 3 arrays as a square
  int diagonal_1[3] = {arrayrow1[0], arrayrow2[1], arrayrow3[2]};
  //the second diagonal of the arrays
  int diagonal_2[3] = {arrayrow1[2], arrayrow2[1], arrayrow3[0]};

  int diagSum1=0, // stores the sum of the first diagonal of the arrays
      diagSum2=0; // stores the sum of the second diagonal of the arrays
      
  //loops through the diagonal arrays and store their sum to the respective diagSum variable
  for(int diag = 0; diag < size; diag++)
  {
    diagSum1 += diagonal_1[diag];
    diagSum2 += diagonal_2[diag];
  }
  //ensures the sum of the diagonals are the same
  if(diagSum1 == diagSum2)
    return true;
  return false;
}
