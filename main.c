/**
 * Coder Name: Jasleen Kaur
 * Date: 6 June, 2021
 * Description: This Sudoku code takes user input for first two rows and validate it based on some conditions.Rest of the rows are generated randomly.
 * Issues: I have commented the condition of validating number of integers user entered because it works sometime.
 */
// header files
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include <intrin.h>

#define SIZE 9

void printInstruction(int row);
void rowValidation(int valid[SIZE][SIZE], int row);
bool GridValidation(int testGrid[][9]);
/**
 *This functiom helps to print instructions.
 * @param row- Number of row user is going to give input for.
 */
void printInstruction(int row)
{
    printf("Enter row %d of your Sudoku grid, No duplicates Please\n", row);
    printf("Use Space/Tab/Return key to enter next values\n");
    printf("and press 'Return' after entering nine integers\n");
    printf("Remember, to make a valid row of Sudoku grid,\n");
    printf("all integers should be distinct and range from 1 to 9\n");
}
/**
 * This function/method is used for taking input from user.
 * @param valid
 * @param row- Number of row user is going to give input for.
 */
void askInput (int valid[SIZE][SIZE], int row)
{
    char input[20];
    fgets(input, sizeof(input), stdin);
    sscanf(input, "%d%d%d%d%d%d%d%d%d", & valid[row-1][0], & valid[row-1][1], & valid[row-1][2], & valid[row-1][3], & valid[row-1][4], &
            valid[row-1][5], & valid[row-1][6], & valid[row-1][7], & valid[row-1][8]);//reads input
}
/**
 * This function helps to validate input from user based on some conditions
 * @param valid
 * @param row Number of row user is going to give input for.
 */

void rowValidation(int valid[SIZE][SIZE], int row)
{
    bool isValid = false;
    while (!isValid) {

      /*  char input[1024]; //validating number of integers entered by user.
        for(int i=0;i<1;i++) {
            if (strlen(input) < 9) {
                fprintf(stderr, "", (unsigned int) strlen(input));
                printf("Please enter 9 integers.\n");

                printInstruction(row);//calling printInstruction function.
                askInput(valid, row);//calling askInput function for taking input again.
                break;
            } else {
                isValid = true;
            }
        }*/

        // Checking duplicate numbers entered by user.
        for (int i = 0; i < 9; i++)
        {
            for (int j = i + 1; j < 9; j++)
            {
                if (valid[row-1][i] == valid[row-1][j])
                {
                    printf("There is a duplicate entry.\n\n Enter nine distinct integers ");
                    for (int j = 0; j < 9; j++)
                    {
                        valid[row-1][j] = 0;
                    }

                    printInstruction(row);//calling printInstruction function.
                    askInput(valid, row);//calling askInput function for taking input again.
                    break;
                }
                else
                {
                    isValid = true;
                }
            }
        }



        //Checking range of numbers entered by user.
        for (int i = 0; i < 1; i++)
        {
            for (int j= 0; j < 9; j++)
            {
                if (valid[row-1][0] > 9 || valid[row-1][0] < 1)
                {
                    printf("One of more entries are outside the range 1 to 9 !\n");
                    for (int j = 0; j < 9; j++)
                    {
                        valid[row-1][j] = 0;
                    }

                    printInstruction(row);//calling printInstruction function.
                    askInput(valid, row);//calling askInput function for taking input again.
                    break;
                }
                else {
                    isValid = true;
                }
            }
        }
    }

}

/**
 * This function helps to validate grid based of three conditions.
 * @param ValidGrid- Final Grid which will be made after user input.
 * @return
 */
bool GridValidation(int ValidGrid[][9])//
{
//checking repetition of numbers in rows.
    for (int k= 0; k < 9; k++)
    {
        for (int i = 0; i < 9; i++)
        {
            for (int j = i + 1; j < 9; j++)
            {
                if (ValidGrid[k][i] == (ValidGrid[k][j]))
                {
                    return false;
                }
            }
        }
    }

    //checking repetition of numbers in columns.
    for (int k = 0; k < 9; k++)
    {
        for (int i = 0; i < 9; i++)
        {
            for (int j = i + 1; j < 9; j++)
            {
                if (ValidGrid[i][k] == (ValidGrid[j][k]))
                {
                    return false;
                }
            }
        }
    }
    //checking repetition of numbers in subsquares 3 * 3 grid.
    for (int row = 0; row < 9; row += 3)
    {
        for (int col = 0; col < 9; col += 3)
        { // row, col is start of the 3 by 3 grid
            for (int i = 0; i < 8; i++)
            {
                for (int j = i+ 1; j < 9; j++)
                {
                    if (ValidGrid[row + i % 3][col + i / 3] == ValidGrid[row + j % 3][col + j / 3]) {
                        return false;
                    }
                }
            }
        }
    }
    return true;

}


int main() //start of main method
{
    int testGrid[][9] = {{5, 3, 4, 6, 7, 8, 9, 1, 2}, // demo grid given in the assignment.
    {6, 7, 2, 1, 9, 5, 3, 4, 8},
    {1, 9, 8, 3, 4, 2, 5, 6, 7},
    {8, 5, 9, 7, 6, 1, 4, 2, 3},
    {4, 2, 6, 8, 5, 3, 7, 9, 1},
    {7, 1, 3, 9, 2, 4, 8, 5, 6},
    {9, 6, 1, 5, 3, 7, 2, 8, 4},
    {2, 8, 7, 4, 1, 9, 6, 3, 5},
    {3, 4, 5, 2, 8, 6, 1, 7, 9}};


    for (int i = 0; i < SIZE; i++) //loop to print testGrid on console.
    {
        for (int j = 0; j < SIZE; j++)
        {
            printf("%d ", testGrid[i][j]);
        }
        puts("");
    }

     //validating testGrid
    if(GridValidation(testGrid) == false)
    {
        printf("\nIt is an invalid solution.\n");
    }
    else{
        printf("\nGiven Sudoku grid is valid.\n");
    }

    int valid[SIZE][SIZE];

   //calling functions for first row.
    printInstruction(1);
    askInput(valid, 1);
    rowValidation(valid, 1);

    //calling functions for first row.
    printInstruction(2);
    askInput(valid,2);
    rowValidation(valid, 2);

    printf("\n---------------------Sudoku Grid-----------------\n");


    srand(time(NULL));
    // randomly generating the rest rows
    int a[10];

    for (int i = 0; i < 9; i++)
    {
        a[i] = i + 1;
    }

    for (int i = 2; i < 9; i++)
    {
        for (int k = 0; k < 9; k++)
        {
            int c = (rand() % 8)+1; // generating random integers between 1-9 using (rand() (upper - lower + 1)) + lower;
            int t = a[k];//interchanging values of a[k] and a[c] with help of third variable t
            a[k] = a[c];
            a[c] = t;
        }
        for (int j = 0; j< 9; j++) {
            valid[i][j] = a[j];
        }
    }

    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++) {

            printf("%d ", valid[i][j]);
        }
        printf("\n");
    }
    //validating the final grid generated
    if(GridValidation(valid) == false)
    {
        printf("\n It is an invalid solution.\n");
    }
    else{
        printf("\nGiven Sudoku grid is valid.\n");
       }

    return 0;

}

