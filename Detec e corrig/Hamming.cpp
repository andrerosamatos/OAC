#include <bits/stdc++.h>

using namespace std;


bitset<7> hamming_encode(bitset<4> data){
    bitset<7> encoded;

    encoded[2] = data[0];
    encoded[4] = data[1];
    encoded[5] = data[2];
    encoded[6] = data[3];

    encoded[0] = data[0] ^ data[1] ^ data[3];
    encoded[1] = data[0] ^ data[2] ^ data[3];
    encoded[3] = data[1] ^ data[2] ^ data[3];

    return encoded;
}

int checar_erro(bitset<7> data) {
    int error = 0;

    error |= (data[0] ^ data[2] ^ data[4] ^ data[6]);
    error |= (data[1] ^ data[2] ^ data[5] ^ data[6]) << 1;
    error |= (data[3] ^ data[4] ^ data[5] ^ data[6]) << 2;

    return error;
}

bitset<7> arrumar_erro(bitset<7> data, int pos){
    data ^= 1<<(pos-1);
    return data;
}

int main() {
    bitset<4> raw_data("1010");
    bitset<7> encoded = hamming_encode(raw_data);
    cout << "A informacao "<<raw_data<<" foi codificada para "<<encoded<<endl;

    encoded = 0b1110010;
    int erro = checar_erro
(encoded);
    if (erro) {
        cout << "A informacao ("<<encoded<<") teve um erro no bit "<<erro<<endl;
        cout << "A informacao foi corrigida para "<<arrumar_erro(encoded, erro) << endl;
    } else {
        cout << "Nenhum erro foi detectado" << endl;
    }

    encoded = 0b1010010;    
    bitset<7> expected = hamming_encode(bitset<4>("1010"));
    erro = checar_erro
(encoded);
    assert(!erro);

    encoded = 0b0010010;    
    erro = checar_erro
(encoded);
    assert(erro == 7);
    assert(expected == arrumar_erro(encoded, erro));

    encoded = 0b1110010;    
    erro = checar_erro
(encoded);
    assert(erro == 6);
    assert(expected == arrumar_erro(encoded, erro));

    encoded = 0b1000010;   
    erro = checar_erro
(encoded);
    assert(erro == 5);
    assert(expected == arrumar_erro(encoded, erro));


    return 0;
}
