# Define o compilador (C++)
CXX = g++

# Flags de compilação: 
# -Wall mostra os avisos (warnings) de código mal feito
# -std=c++17 usa a versão moderna do C++
# -I include/ avisa onde estão os arquivos .hpp
CXXFLAGS = -Wall -std=c++17 -I include/

# Nome do programa final e onde ele vai ficar
TARGET = bin/blackjack_app

# Procura automaticamente todos os arquivos .cpp dentro da pasta src/
SRCS = $(wildcard src/*.cpp)

# Transforma a lista de .cpp em .o (arquivos objeto)
OBJS = $(SRCS:.cpp=.o)

# Regra principal (o que acontece quando você digita apenas 'make')
all: $(TARGET)

# Regra de linkagem: Junta todos os .o para criar o executável final
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)
	@echo "Sucesso! Para jogar, digite: ./$(TARGET)"

# Regra de compilação: Ensina como transformar um .cpp em um .o
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Comando auxiliar para limpar o projeto (make clean)
clean:
	rm -f src/*.o $(TARGET)
	@echo "A pasta está limpa!"
