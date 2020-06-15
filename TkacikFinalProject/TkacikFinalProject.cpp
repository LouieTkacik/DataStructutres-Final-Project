// TkacikFinalProject.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <ctime>
using namespace std;

//sorting methods
//bubble sort
void bubbleSort(int A[], int n)
{
    //call for multiuple passes
    for (int k = 0; k < n; k++)
    {
        //inside each passed the largest bubble is moved to the end of the array
            for (int i = 0; i < n - 1; i++)
            {
                if (A[i] > A[i + 1])
                {
                    //swap the elements
                    int temp = A[i];
                    A[i] = A[i + 1];
                    A[i + 1] = temp;
                }
            }
    }


}

//selection sort
void selectionSort(int A[], int n)
{
    //iterate through the array elements and find the minimum value.
    //select the value and place it in the correct position
    for (int i = 0; i <( n - 1); i++)
    {
        int iMin = i;//assign the index of the new minimum element
        for (int j = (i + 1); j < n; j++)
        {
            //search the rest of the array to the find the new min Index
            if (A[j] < A[iMin])
            {
                iMin = j;
            }
        }
        //swap the elements
        int temp = A[i];
        A[i] = A[iMin];
        A[iMin] = temp;
    }
}

//insertion sort
void insertionSort(int A[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int value = A[i];
        int hole = i; //positon of sorted subset
        while (hole > 0 && A[hole - 1] > value)
        {
            //inserts the unsorted subset in the correct position
            //in sorted subset
            A[hole] = A[hole - 1];
            hole = hole - 1;
        }
        A[hole] = value;
    }
}

//GNOME SORT!!!
void gnomeSort(int A[], int n)
{
    //OK I'm gonna be real-- I saw the name of this and wanted to implement it because I have garden gnomes and got excited
    //the idea is you start at the beginning and compare the two adjacent values.  The larger on the right than it is on the left, then good.
    //if it's bigger on the right, we swap it with the one to the left then move back with it to compare it to the one on the new left
    //we use the index rather than a counter because we move back and forth
    //This actually reminds me of how I organize when I'm bored and want something to do with my hands...
    //BENEGFITS in that it only has one while loop, but that while loop will iterate more often.
    int index = 0;

    while (index < n) {
        if (index == 0)
        {
            index++;  //move the index along
        }
        if (A[index] >= A[index - 1])
        {
            index++; //if it's bigger then move along.  We want it to be bigger
        }
        else 
        {  //if the left hand is bigger, then swap it with the one next to it
            swap(A[index], A[index - 1]);
            index--;  //take a step back and see if the one to the left of the left is bigger or smaller and start the loop over
        }
    }
  
}
void reverseGnomeSort(int A[], int n)
{
    //idk if it was only supposed to be done reverse or only the other way
    int index = 0;

    while (index < n) {
        if (index == 0)
        {
            index++;  //move the index along
        }
        if (A[index] <= A[index - 1])
        {
            index++; //if it's smaller then move along.  We want it to be smaller
        }
        else
        {  //if the left hand is smaller, then swap it with the one next to it
            swap(A[index], A[index - 1]);
            index--;  //take a step back and see if the one to the left of the left is bigger or smaller and start the loop over
        }
    }

}




//mathematical methods
//summation method
int summation(int A[], int n)
{
    int sum = 0;
    for (int counter = 0; counter < n; counter++)
    {
        sum = sum + A[counter];
    }
    return sum;
}
int averageOf(int s, int n)
{
    int average = s / n;
    return average;
}

int main()
{
    //declare and initialize an integer array of SIZE elements
    const int SIZE = 1000;
    int array[SIZE];
    //int array[SIZE] = { 1,5,2,4,3 };
    int tempRandom, intSum, intAvg;

    srand(time(NULL)); //seed the random

    for (int counter = 0; counter < SIZE; counter++)
    {
        tempRandom = rand() % 1000; //generate a random number
        array[counter] = tempRandom; //insert that generated number into the array
    }
    cout << "Generating an array: \n";
    //display contents
    for (int i = 0; i < SIZE; i++)
    {
        cout << array[i] << " || ";
        
    }

   
    cout << "After Gnome sorting: \n";
   
    gnomeSort(array, SIZE);
    for (int i = 0; i < SIZE; i++)
    {
        cout << array[i] << " ";
        cout << endl;
    }

    cout << "Reversing the sort" << endl;

    reverseGnomeSort(array, SIZE);
    for (int i = 0; i < SIZE; i++)
    {
        cout << array[i] << " ";
        cout << endl;
    }

    intSum = summation(array, SIZE);
    cout << "The sum of the numbers is: " << intSum <<endl;
    intAvg=averageOf(intSum, SIZE);
    cout << "The average of the array is: " << intAvg <<endl;

    //BELOW IS TO DEMONSTRATE THAT THE BUBBLESORT WORKS

    //cout << "Generating a new array... \n";

    //for (int counter = 0; counter < SIZE; counter++)
    //{
    //    tempRandom = rand() % 1000; //generate a random number
    //    array[counter] = tempRandom; //insert that generated number into the array
    //}

    ////display contents
    //for (int i = 0; i < SIZE; i++)
    //{
    //    cout << array[i] << " ";
    //    cout << endl;
    //}
    //cout << "Displaying bubble sort results... \n";
    //bubbleSort(array, SIZE);
    //for (int i = 0; i < SIZE; i++)
    //{
    //    cout << array[i] << " ";
    //    cout << endl;
    //}
    //intSum = summation(array, SIZE);
    //cout << "The sum of the numbers is: " << intSum << endl;
    //intAvg = averageOf(intSum, SIZE);
    //cout << "The average of the array is: " << intAvg << endl;
}

