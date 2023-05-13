#include <iostream>
#include <ctime>
#include <unordered_map>
#include <fstream>

char* generate_random_ip() {

    char* ip = (char*) malloc(sizeof(char) * 22);
    int a = rand() % 256;
    int b = rand() % 256;
    int c = rand() % 256;
    int d = rand() % 256;
    int e = rand() % 65535;
    sprintf(ip, "%d.%d.%d.%d:%d", a, b, c, d, e);
    return ip;
}

int main() {
    int i = 0;
    double time_spent = 0.0;
    clock_t begin = clock();
    using namespace std;
    unordered_map<string, int> test_map;
    char buff[50];
    ifstream fin("english_words.txt");
    while(i < 5000){
        fin >> buff;
        i++;
        test_map.emplace(fin,generate_random_ip());
    }




    clock_t end = clock();
    time_spent += (double)(end - begin) / CLOCKS_PER_SEC;

    printf("The elapsed time is %f seconds", time_spent);
    return 0;
}
