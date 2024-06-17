#include<bits/stdc++.h>
using namespace std;

//this is basically a brute force method having n^3 time and space complexity

void floydWarshall(vector<vector<int>> &matrix){
    //assuming, if no edge= infinity and i==j cells have weight as 0
    int n=matrix.size();
    for(int via=0; via<n; via++){
        for(int row=0; row<n; row++){
            for(int col=0; col<n; col++){
                matrix[row][col]= 
                min( matrix[row][col], (matrix[row][via] + matrix[via][col]) );
            }
        }
    }
}
//can be optimised but no