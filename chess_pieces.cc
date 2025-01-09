#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <stdexcept>
#include <utility>

enum class Type { KING, QUEEN, KNIGHT, BISHOP, ROOK, PAWN };
enum class Color { WHITE, BLACK, };

class ChessPiece {
  public:
    ChessPiece(int row, int column, Type type, Color color)
      : row_{row}, column_{column}, type_{type}, color_{color} {}

    int GetRow() const { return row_;}
    int GetColumn() const { return column_;}
    void SetRow(int value) { row_ = value; }
    void SetColumn(int value) { column_ = value; }
    void PrintPiece() const;

  private:
    int row_;
    int column_;
    Type type_; 
    Color color_;
};

void RandomizePiece(int& row, int& column, Type& type, Color& color);
std::ostream& operator<<(std::ostream& stream, const ChessPiece& piece);
void CheckInput(int argc);

int main(int argc, char const** argv) {
  CheckInput(argc);
  srand(static_cast<unsigned>(time(nullptr)));
  int number_of_pieces = std::stoi(argv[1]);
  std::vector<ChessPiece> pieces;
  for (int i{0}; i < number_of_pieces; ++i) {
    int row, column; Type type; Color color;
    RandomizePiece(row, column, type, color);
    ChessPiece new_piece{row, column, type, color};
    pieces.push_back(new_piece);
  }
  std::vector<std::pair<int, int>> positions;
  for (const auto& piece : pieces) {
    positions.push_back(std::make_pair<int, int>(piece.GetRow(), piece. GetColumn()));
  }
  for (const auto& piece : pieces) {
    std::cout << piece << "\n";
  }
  bool relocate = false;
  for (size_t i{0}; i < positions.size(); ++i) {
    for (size_t j{0}; j < positions.size(); ++j) {
      if (positions[i] == positions[j]) {
        relocate = true;
        pieces[j].SetRow(1 + rand() % 8);
        pieces[j].SetColumn(1 + rand() % 8);
      }
    }
  }
  if (relocate) {
  std::cout << "\n" << "Relocating pieces\n" << "\n";
    for (auto& piece : pieces) {
      std::cout << piece << "\n";
    }  
  }
  return 0;
}

void CheckInput(int argc) {
  if (argc != 2) {
    std::cout << "You must introduce the number of pieces!\n";
    exit(EXIT_FAILURE);
  }
}

void RandomizePiece(int& row, int& column, Type& type, Color& color) {
  row = 1 + rand() % 8;
  column = 1 + rand() % 8;
  int piece = rand() % 6;
  switch (piece) {
    case 0: type = Type::KING; break;
    case 1: type = Type::QUEEN; break;
    case 2: type = Type::KNIGHT; break;
    case 3: type = Type::BISHOP; break;
    case 4: type = Type::ROOK; break;
    case 5: type = Type::PAWN; break;
  }
  int side = rand() % 2;
  switch (side) {
    case 0: color = Color::WHITE; break;
    case 1: color = Color::BLACK; break;
  }
}

void ChessPiece::PrintPiece() const {
  std::string piece;
  switch (type_) {
    case Type::KING: piece = "king";  break;
    case Type::QUEEN: piece = "queen"; break;
    case Type::KNIGHT: piece = "knight"; break;
    case Type::BISHOP: piece = "bishop"; break;
    case Type::ROOK: piece = "rook"; break;
    case Type::PAWN: piece = "pawn"; break;
  }
  std::cout << piece << " ";
  switch (color_) {
    case Color::WHITE: piece = "white"; break;
    case Color::BLACK: piece = "black"; break;
  }
  std::cout << piece << " ";
  std::cout << "row=" << row_ << " column="<< column_;
}

std::ostream& operator<<(std::ostream& stream, const ChessPiece& piece) {
  piece.PrintPiece();
  return stream;
}