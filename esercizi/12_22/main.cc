#include <iostream>

#include <cstring>  // for strstr

int indice (char *envp[], char *s){
    int i = 0;
    while(envp[i] != NULL){
        if(strstr(envp[i], s) != NULL){
            return i;  // return the index if s is found in envp[i]
        }
        i++;
    }
    return -1;  // return -1 if s is not found in any string
}

//need the enviroment variable passed to the program with envp
int main(int argc, char ** argv, char *envp[]) {
    //print the enviroment variables
    

    char s[256];

    //read a string from stdin
    std::cin >> s;


    //print the index of the string that has at least 4 characters in common with s
    std::cout << envp[indice(envp, s)] << std::endl;

    return 0;
}