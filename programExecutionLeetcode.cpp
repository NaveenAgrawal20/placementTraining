#include<bits/stdc++.h>
#include<chrono>
using namespace std;

void init_code()
{
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
}
int main()
{
    init_code();

        auto start = chrono::high_resolution_clock::now();
        /*--------------------------------------------------*/
        /*--------------------------------------------------*/
        /*--------------------------------------------------*/
        /*--------------------------------------------------*/
        /*--------------------------------------------------*/
        
        /* MAIN FUNCTION */
        // Solution obj;
        // cout << obj.uniquePathsWithObstacles(grid) << endl;

        /*--------------------------------------------------*/
        /*--------------------------------------------------*/
        /*--------------------------------------------------*/
        /*--------------------------------------------------*/
        /*--------------------------------------------------*/
        /*--------------------------------------------------*/
        auto end = chrono::high_resolution_clock::now();

        // Calculating total time taken by the program.
        double time_taken =
            chrono::duration_cast<chrono::nanoseconds>(end - start).count();
        time_taken *= 1e-9;

        cout << "Time taken by program is : " << fixed
             << time_taken << setprecision(9);
        cout << " sec" << endl;
    }

}