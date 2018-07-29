#include <bits/stdc++.h>

using namespace std;

bool verifica_erro(char c){
    bool res = 0;
    for (char i=0; i<8; i++){
        res ^= (c >> i) & 1;
    }
    return res;
}

string binary_string(char c){
    char res[8];
    for (char i=0; i<8; i++){
        res[7-i] = ((c >> i) & 1)? '1' : '0';
    }
    return res;
}

int main() {
    char binary = 0b00001111;  

    cout << "A mensagem eh: "<<binary_string(binary)<<endl;

    if (verifica_erro(binary)) {
        cout << "Um erro foi encontrado na mensagem!" << endl;
    } else {
        cout << "Nenhum erro foi encontrado." << endl;
    }

    binary = 0b10101010;
    assert(!verifica_erro(binary));;

    binary = 0b00101010;
    assert(verifica_erro(binary));;

    binary = 0b00000111;
    assert(verifica_erro(binary));;

    binary = 0b10000111;
    assert(!verifica_erro(binary));;

    binary = 0b10010011;
    assert(!verifica_erro(binary));;

    binary = 0b10000011;
    assert(verifica_erro(binary));;

    return 0;
}