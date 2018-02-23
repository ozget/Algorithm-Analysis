using System;
using System.Diagnostics;

namespace fibonacci
{
    class Program
    {
        static int fib_recursive(int n)
        {
            if (n < 2)
                return n;
            else
                return fib_recursive(n - 1) + fib_recursive(n - 2);
        }

        static int fib_loop(int n)
        {
            int a = 0;
            int b = 1;

            for (int i = 0; i < n; i++)
            {
                int temp = a;
                a = b;
                b = temp + b;
            }
            return a;
        }


        static void Main(string[] args)
        {
            int num;

            Console.WriteLine("");
            Stopwatch sw = Stopwatch.StartNew();
            Console.WriteLine("enter a number");
            num = Convert.ToInt32(Console.ReadLine());
            fib_recursive(num);
            sw.Stop();
            Console.Write("miliseconds : " + sw.ElapsedMilliseconds);

            Console.WriteLine("\n-----------------------------------------------------\n");


            Console.WriteLine("");
            Stopwatch sw2 = Stopwatch.StartNew();
            Console.WriteLine("enter a number");
            num = Convert.ToInt32(Console.ReadLine());
            fib_loop(num);
            sw2.Stop();
            Console.Write("miliseconds : " + sw2.ElapsedMilliseconds);

            Console.ReadLine();
        }
    }
}
