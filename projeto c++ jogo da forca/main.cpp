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

void mostrarForca(int erros) {
    const char* forca[7] = {
        "  +---+\n      |\n      |\n      |\n     ===\n",
        "  +---+\n  O   |\n      |\n      |\n     ===\n",
        "  +---+\n  O   |\n  |   |\n      |\n     ===\n",
        "  +---+\n  O   |\n /|   |\n      |\n     ===\n",
        "  +---+\n  O   |\n /|\\  |\n      |\n     ===\n",
        "  +---+\n  O   |\n /|\\  |\n /    |\n     ===\n",
        "  +---+\n  O   |\n /|\\  |\n / \\  |\n     ===\n"
    };
    std::cout << forca[erros] << "\n";
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
    
    char palavra[20];
        sortearPalavra(palavra, palavras, 20);   // usa a função aqui
        int tamanho = strlen(palavra);

        char oculto[20];
        int i = 0;
        while (i < tamanho) {
            oculto[i] = '_';
            i++;
        }
        oculto[tamanho] = '\0';

        char usadas[26];
        int qtdUsadas = 0;
        int erros = 0;
        int maxErros = 6;

        while (erros < maxErros && strcmp(oculto, palavra) != 0) {
            std::cout << "\nJogo da Forca\n";
            mostrarForca(erros);
            std::cout << "Palavra: " << oculto << "\n";
            mostrarUsadas(usadas, qtdUsadas);

            std::cout << "Digite uma letra: ";
            char letra;
            std::cin >> letra;

            if (jaUsada(usadas, qtdUsadas, letra)) {
                std::cout << "Você já tentou essa letra!\n";
                continue;
            }

            usadas[qtdUsadas] = letra;
            qtdUsadas++;

            bool acertou = false;
            int j = 0;
            while (j < tamanho) {
                if (palavra[j] == letra) {
                    oculto[j] = letra;
                    acertou = true;
                }
                j++;
            }

            if (!acertou) erros++;
        }

        if (strcmp(oculto, palavra) == 0) {
            std::cout << "\nParabéns, você ganhou! A palavra era: " << palavra << "\n";
        } else {
            mostrarForca(erros);
            std::cout << "\nVocê perdeu! A palavra era: " << palavra << "\n";
        }

    
    }

    return 0;
}
