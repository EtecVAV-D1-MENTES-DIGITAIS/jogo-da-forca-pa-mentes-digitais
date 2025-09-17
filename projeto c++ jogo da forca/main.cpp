#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>

void sortearPalavra(char destino[], const char lista[][20], int total) {
    int n = rand() % total;
    strcpy(destino, lista[n]); 
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
        "cleopatra", "hitler", "mussolini", "eistein", "maome",
        "jesus", "buddha", "bolsonaro", "kant", "diogenes",
        "socrates", "pele", "messi", "kafka", "Tesla",
        "aquiles", "pavarotti", "anubis", "zumbi", "ronildo"
    };
    
    char jogarNovamente = 's';
    while (jogarNovamente == 's' || jogarNovamente == 'S') {
    char palavra[20];
        sortearPalavra(palavra, palavras, 20);   
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
            std::cout << "\nBem vindo(a) ao Jogo da Forca sobre Figuras Hist�ricas!\n";
            mostrarForca(erros);
            std::cout << "Palavra: " << oculto << "\n";
            mostrarUsadas(usadas, qtdUsadas);

            std::cout << "Digite a letra desejada: ";
            char letra;
            std::cin >> letra;

            if (jaUsada(usadas, qtdUsadas, letra)) {
                std::cout << "Voc� j� tentou essa letra!\n";
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
            std::cout << "\nParabens, voc� ganhou! A palavra era: " << palavra << "\n";
        } else {
            mostrarForca(erros);
            std::cout << "\nVoce perdeu! A palavra era: " << palavra << "\n";
        }

		std::cout << "Deseja jogar novamente? (s/n): ";
        std::cin >> jogarNovamente;
    }

    return 0;
}
