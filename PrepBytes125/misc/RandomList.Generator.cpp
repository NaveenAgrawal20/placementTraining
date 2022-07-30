/*
 * Create By Naveen
 * Created on Thu Feb 11 2021
 * Copyright © 2021
 */

/*This Program generates a list of 'n' random num in given range */
#include <iostream>
#include <time.h>
using namespace std;

void generateList(int n, int min_r = 1, int max_r = 10)
{
    while (n--)
        cout << (rand() % (max_r - min_r)) + min_r << " ";
}

int main()
{
    /* initialize random seed: */

    srand(time(NULL));
    generateList(100, 2, 12323250);
    return 0;
}