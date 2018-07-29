#include <bits/stdc++.h>

using namespace std;

const bitset<14> gerador("00000000101101");

int primeiro_bit(const bitset<14> &a) {
    int i;
    for (i = 13; i >= 0; i--)
        if (a.test(i)) break;
    return i;
}

bitset<14> divisao_binaria(bitset<14> number, bitset<14> divisor){
    int bit = 0;

    int tam = primeiro_bit(divisor);
    while ((bit=primeiro_bit(number)) >= tam) {
        number ^= divisor << (bit - tam);
    }
    return number;
}

bitset<14> crc_encode(bitset<9> data) {
    bitset<14> res(data.to_ulong()<<5);
    bitset<14> resto = divisao_binaria(res, gerador);

    for (int i=0; i<5; i++){
        res[i] = resto[i];
    }

    return res;
}

int main() {
    bitset<9> dados("111100101");   
    bitset<14> enviados = crc_encode(dados);    
    cout << "A mensagem enviada foi "<<enviados << endl;

    if (divisao_binaria(enviados, gerador).to_ulong()) {    
        cout << "Encontramos um erro!" << endl;
    } else {
        cout << "Nenhum erro foi encontrado." << endl;
    }


    //Testes para validacao
    assert(divisao_binaria(enviados, gerador).to_ulong() == 0);

    enviados.flip(1);
    assert(divisao_binaria(enviados, gerador).to_ulong() != 0);

    enviados.flip(2);
    assert(divisao_binaria(enviados, gerador).to_ulong() != 0);

    enviados.flip(1);
    assert(divisao_binaria(enviados, gerador).to_ulong() != 0);

    enviados.flip(2);
    assert(divisao_binaria(enviados, gerador).to_ulong() == 0);

    return 0;
}
