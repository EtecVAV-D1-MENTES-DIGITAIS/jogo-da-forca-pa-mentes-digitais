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

        // Arte ASCII
        forcaAscii.push_back(
            "   _______\n"
            "  |/      |\n"
            "  |       \n"
            "  |       \n"
            "  |       \n"
            "  |       \n"
            " _|___    \n"
        );
        forcaAscii.push_back(
            "   _______\n"
            "  |/      |\n"
            "  |      (_)\n"
            "  |       \n"
            "  |       \n"
            "  |       \n"
            " _|___    \n"
        );
        forcaAscii.push_back(
            "   _______\n"
            "  |/      |\n"
            "  |      (_)\n"
            "  |       |\n"
            "  |       \n"
            "  |       \n"
            " _|___    \n"
        );
        forcaAscii.push_back(
            "   _______\n"
            "  |/      |\n"
            "  |      (_)\n"
            "  |      /|\n"
            "  |       \n"
            "  |       \n"
            " _|___    \n"
        );
        forcaAscii.push_back(
            "   _______\n"
            "  |/      |\n"
            "  |      (_)\n"
            "  |      /|\\\n"
            "  |       \n"
            "  |       \n"
            " _|___    \n"
        );
        forcaAscii.push_back(
            "   _______\n"
            "  |/      |\n"
            "  |      (_)\n"
            "  |      /|\\\n"
            "  |      / \n"
            "  |       \n"
            " _|___    \n"
        );
        forcaAscii.push_back(
            "   _______\n"
            "  |/      |\n"
            "  |      (_)\n"
            "  |      /|\\\n"
            "  |      / \\\n"
            "  |       \n"
            " _|___    \n"
        );

        // Palavras
        palavras.push_back("bolsonaro"); palavras.push_back("elizabeth");
        palavras.push_back("stalin");    palavras.push_back("socrates");
        palavras.push_back("hitler");   palavras.push_back("ronildo");
        palavras.push_back("napoleao");      palavras.push_back("jesus");
        palavras.push_back("trotsky");      palavras.push_back("salomao");
        palavras.push_back("gengis");    palavras.push_back("diogenes");
        palavras.push_back("cleopatra");    palavras.push_back("tchaikovsky");
        palavras.push_back("antonieta");     palavras.push_back("trump");
        palavras.push_back("darc");     palavras.push_back("francisco");
        palavras.push_back("galileu");      palavras.push_back("descartes");

        palavra = palavras[rand() % palavras.size()];
        palavraOculta = string(palavra.size(), '_');
        erros = 0;
    }

    void jogar() {
        while (erros < (int)forcaAscii.size() - 1 && palavraOculta != palavra) {
            limparTela();

            cout << "Bem vindo(a) ao jogo da forca sobre figuras historicas!\n\n";
            cout << forcaAscii[erros] << "\n";
            cout << "Palavra: " << palavraOculta << "\n";

            cout << "Letras ja usadas: ";
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
                cout << "Você ja tentou essa letra!\n";
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
            cout << "\nVoce ganhou, parabens! A palavra correta era: " << palavra << "\n";
        } else {
            cout << forcaAscii.back() << "\n";
            cout << "\nVoce perdeu! A palavra era: " << palavra << "\n";
        }
    }
};

int main() {
    char r = 's';
    while (r == 's' || r == 'S') {
        JogoForca jogo;
        jogo.jogar();

        cout << "Deseja jogar novamente? (s/n): ";
        cin >> r;
    }
    return 0;
}

