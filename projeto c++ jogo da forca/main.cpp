#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <ctime>
#include <cstdlib>
#include <cctype>
using namespace std;

class JogoForca {
private:
    vector<string> forcaAscii;
    vector<string> palavras;
    string palavra;
    string palavraOculta;
    set<char> letrasUsadas;
    int erros;

    void limparTela() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
        int i = 0;
        while (i < 30) { cout << "\n"; ++i; }
    #endif
    }

public:
    JogoForca() {
        srand((unsigned)time(NULL));

        
        forcaAscii.push_back("  +---+\n  |   |\n      |\n      |\n      |\n      |\n=======");
        forcaAscii.push_back("  +---+\n  |   |\n  O   |\n      |\n      |\n      |\n=======");
        forcaAscii.push_back("  +---+\n  |   |\n  O   |\n  |   |\n      |\n      |\n=======");
        forcaAscii.push_back("  +---+\n  |   |\n  O   |\n /|   |\n      |\n      |\n=======");
        forcaAscii.push_back("  +---+\n  |   |\n  O   |\n /|\\  |\n      |\n      |\n=======");
        forcaAscii.push_back("  +---+\n  |   |\n  O   |\n /|\\  |\n /    |\n      |\n=======");
        forcaAscii.push_back("  +---+\n  |   |\n  O   |\n /|\\  |\n / \\  |\n      |\n=======");

        palavras.push_back("cachorro"); palavras.push_back("banana");
        palavras.push_back("brasil");    palavras.push_back("carro");
        palavras.push_back("futebol");   palavras.push_back("azul");
        palavras.push_back("mesa");      palavras.push_back("medico");
        palavras.push_back("amor");      palavras.push_back("ouro");
        palavras.push_back("batman");    palavras.push_back("matrix");
        palavras.push_back("naruto");    palavras.push_back("computador");
        palavras.push_back("pizza");     palavras.push_back("piano");
        palavras.push_back("praia");     palavras.push_back("lua");
        palavras.push_back("fogo");      palavras.push_back("coruja");

        palavra = palavras[rand() % palavras.size()];
        palavraOculta = string(palavra.size(), '_');
        erros = 0;
    }

    void jogar() {
        while (erros < (int)forcaAscii.size() - 1 && palavraOculta != palavra) {
            limparTela();

            cout << "=== JOGO DA FORCA ===\n\n";
            cout << forcaAscii[erros] << "\n";
            cout << "Palavra: " << palavraOculta << "\n";

            cout << "Letras usadas: ";
            set<char>::iterator it = letrasUsadas.begin();
            while (it != letrasUsadas.end()) {
                cout << *it << ' ';
                ++it;
            }
            cout << "\n";

            cout << "Digite uma letra: ";
            char letra;
            if (!(cin >> letra)) break;
            letra = (char)tolower((unsigned char)letra);

            if (letrasUsadas.count(letra)) {
                cout << "Você já tentou essa letra!\n";
                
                int p = 0; while (p < 1) ++p;
                continue;
            }
            letrasUsadas.insert(letra);

            bool achou = false;
            int i = 0;
            while (i < (int)palavra.size()) {
                if (palavra[i] == letra) {
                    palavraOculta[i] = letra;
                    achou = true;
                }
                i++;
            }

            if (!achou) erros++;
        }

        
        if (palavraOculta == palavra) {
            cout << "\nParabéns! Você acertou: " << palavra << "\n";
        } else {
            cout << forcaAscii.back() << "\n";
            cout << "\nGame Over! A palavra era: " << palavra << "\n";
        }
    }
};

int main() {
    JogoForca jogo;
    jogo.jogar();
    return 0;
}

