#include<iostream>
#include <fstream>
#include <cstdlib>

/**
 * No entedí como leer un grafo, así que el programa 
 * tan solo lo lee y lo devuelve tal cual
 */

// ¿?
struct Pair {
  int first{0};
  int second{0};
};

class Graph {
  // ¿?
};

void CheckParameters(int argc, const char** argv);
void ReadGraphs(std::ifstream& inputFile, std::ofstream& outputFile);

int main(int argc, char const** argv) {
  CheckParameters(argc, argv);
  std::string input = argv[1];
  std::ifstream inputFile(input);
  if (!inputFile) {
    std::cerr << "Error al abrir el archivo de entrada\n";
    exit(EXIT_FAILURE);
  }
  std::ofstream outputFile("output.txt");
  ReadGraphs(inputFile, outputFile);
  return 0;
}

void CheckParameters(int argc, const char** argv) {
  if (argc != 2) {
    std::cerr << "Programa mal ejecutado\n";
    exit(EXIT_FAILURE);
  }
  std::string file = argv[1];
  if (file.find(".txt") == std::string::npos) {
    std::cerr << "El input debe ser un archivo de texto\n";
    exit(EXIT_FAILURE);
  }
}

void ReadGraphs(std::ifstream& inputFile, std::ofstream& outputFile) {
  int number;
  int count{0};
  while (inputFile >> number) {
    ++count;
    outputFile << number;
    if (count == 1) {
      outputFile << " ";
    } else if (count == 2) {
      outputFile << "\n";
      count = 0;
    }
  }
}