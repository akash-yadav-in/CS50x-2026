#include <cs50.h>
#include <stdio.h>

int main(void)
{
    string answer = get_string("What's your name? ");  // get_String is the way to take a input in string form 
    printf("hello, %s\n", answer); // Here we have used %s referring to the string data from answer variable (which store the value when the get_string function is gonna run ) 
}
