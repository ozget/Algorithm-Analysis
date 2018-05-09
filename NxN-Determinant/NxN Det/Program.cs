using System;

namespace NxN_Det
{
    class Program
    {
        public static double determinant(double[,] array)
        {
            double det = 0,total=0;
            double[,] tempArray = new double[array.GetLength(0) - 1, array.GetLength(1) - 1];

            if (array.GetLength(0) == 2)
            {
                det = array[0, 0] * array[1, 1] - array[0, 1] * array[1, 0];
            }

            else
            {

                for (int i = 0; i < 1; i++)
                {
                    for (int j = 0; j < array.GetLength(1); j++)
                    {
                        if (j % 2 != 0) array[i, j] = array[i, j] * -1;
                        tempArray = fillNewArr(array, i, j);
                        det += determinant(tempArray);
                        total = total + (det * array[i, j]);
                    }
                }
            }
            return det;
        }

        public static double[,] fillNewArr(double[,] originalArr, int row, int col)
        {
            double[,] tempArray = new double[originalArr.GetLength(0) - 1, originalArr.GetLength(1) - 1];

            for (int i = 0, newRow = 0; i < originalArr.GetLength(0); i++)
            {
                if (i == row)
                    continue;
                for (int j = 0, newCol = 0; j < originalArr.GetLength(1); j++)
                {
                    if (j == col) continue;
                    tempArray[newRow, newCol] = originalArr[i, j];

                    newCol++;
                }
                newRow++;
            }
            return tempArray;

        }

        static void Main(string[] args)
        {
            double [,] matrix = new double[,] { { 1, 2,3 }, { 3, 4,5 },{ 2, 2,2 } };
           
            Console.WriteLine(determinant(matrix));
            Console.ReadLine();
        }
    }
}

