#include<iostream>
using namespace std;
int main(){
    int b=0,A;
    int char;
    int arr[2][3] = {{4, 5, 6}, {7, 8, 9}};
    int* p = &arr[0][0];
    int result = (*p) * (*(p + 2)) * (*(p + 4));
    cout<<result;
    cin.get();
}