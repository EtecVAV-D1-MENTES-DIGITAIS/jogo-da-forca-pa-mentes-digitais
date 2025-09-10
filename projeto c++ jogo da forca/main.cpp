#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>

int sortear(int max) {
    int n;
    n = rand() % max;
    return n;
}

bool jaUsada(char usadas[], int qtd, char letra) {
    int i = 0;
    while (i < qtd) {
        if (usadas[i] == letra) return true;
        i++;
    }
    return false;
}

void mostrarUsadas(char usadas[], int qtd) {
    std::cout << "Letras ja usadas: ";
    int i = 0;
    while (i < qtd) {
        std::cout << usadas[i] << " ";
        i++;
    }
    std::cout << "\n";
}

int main() {
    srand((unsigned)time(NULL));

    const char palavras[20][20] = {
        "nome1", "nome2", "nome3", "nome4", "nome5",
        "nome6", "nome7", "nome8", "nome9", "nome10",
        "nome11", "nome12", "nome13", "nome14", "nome15",
        "nome16", "nome17", "nome18", "nome19", "nome20"
    };

    
    }

    return 0;
}
