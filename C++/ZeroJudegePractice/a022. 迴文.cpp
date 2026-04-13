#include<iostream>
#include<string>
int main(){
    using namespace std;
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    string input;
    while(cin >>input){
        int left =0;
        int right = input.length()-1;
        bool isPalindrome =true;
        while(left <right){
            if(input[left] != input[right]){
                isPalindrome = false;
                break;
            }
            left++;
            right--;
        }
        if(isPalindrome){
            cout<<"yes\n";
        }
        else{
            cout<<"no\n";
        }
    }
    return 0;
}