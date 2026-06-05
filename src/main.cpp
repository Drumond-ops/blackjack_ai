#include <SFML/Graphics.hpp>
#include <iostream>

int main() {
    // 1. Cria a janela gráfica com resolução de 800x600
    std::cout << "estamos no 2 agora\n\n" << std::endl;
    sf::RenderWindow janela(sf::VideoMode(800, 600), "Blackjack IA - Mesa de Teste");
    
    // Trava em 60 quadros por segundo para não sobrecarregar o processador
    janela.setFramerateLimit(60);

    std::cout << "[Sistema] Iniciando motor grafico SFML..." << std::endl;

    // 2. O GAME LOOP (Roda continuamente até a janela ser fechada)
    while (janela.isOpen()) {
        
        sf::Event evento;
        
        // 3. Verifica os eventos do Sistema Operacional (Mouse/Teclado)
        while (janela.pollEvent(evento)) {
            // Se o usuário clicar no 'X' da janela ou apertar a tecla ESC
            if (evento.type == sf::Event::Closed || 
               (evento.type == sf::Event::KeyPressed && evento.key.code == sf::Keyboard::Escape)) {
                janela.close();
            }
        }

        // 4. Desenha o quadro (Update & Draw)
        // Limpa a tela inteira com a cor Verde escuro (RGB: 34, 139, 34)
        janela.clear(sf::Color(34, 139, 34));

        // Joga os pixels desenhados para o monitor
        janela.display();
    }

    std::cout << "[Sistema] Janela fechada com sucesso!" << std::endl;
    return 0;
}