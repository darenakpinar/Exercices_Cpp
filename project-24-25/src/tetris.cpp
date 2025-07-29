#include "tetris.hpp"
// Helper method: Check power of two using  binary representation
bool piece::is_power_of_two(uint32_t s) const {
    return s && ((s & (s - 1)) == 0);
}

// Constructor 
piece::piece() : m_side(0), m_color(0), m_grid(nullptr) {}

piece::piece(uint32_t s, uint8_t c) : m_side(s), m_color(c), m_grid(nullptr) {
    if (!is_power_of_two(s) || c == 0)
        throw tetris_exception("Invalid side length or color.");

    allocate_grid();
}
// Grid 
void piece::allocate_grid() {
    m_grid = new bool*[m_side]; // new memory for the grid
    for (uint32_t i = 0; i < m_side; i++){
        m_grid[i] = new bool[m_side];
        for (uint32_t j = 0; j < m_side; j++){
            m_grid[i][j] = false; // all cells empty
        }
    }    
}

void piece::clear_grid() {
  if (!m_grid)return;
  for (uint32_t i = 0; i < m_side; i++){
    delete[] m_grid[i];
  }
  delete[] m_grid;
  m_grid = nullptr;
}

// copy constructor
piece::piece(const piece& rhs) : m_side(rhs.m_side), m_color(rhs.m_color), m_grid(nullptr) {
   if (rhs.m_grid){
    // allocate a new grid of the same size
    m_grid = new bool*[m_side]
    for (uint32_t i = 0; i < m_side; i++){
        m_grid[i] = new bool[m_side];
        for (uint32_t j = 0; j < m_side; j++){
            m_grid[i][j] = rhs.m_grid[i][j];
        }
    }
   }
}
piece::piece(piece&& rhs) 
    : m_side(rhs.m_side), m_color(rhs.m_color), m_grid(rhs.m_grid) {
    // remove ownership from rhs
    rhs.m_grid = nullptr;
    rhs.m_side = 0;
    rhs.m_color = 0;
}

// destructor
piece::~piece() {
    clear_grid();
}

// Accessors and mutators for ease of use
uint32_t piece::side() const { return m_side; }
int piece::color() const { return m_color; }

bool piece::operator()(uint32_t i, uint32_t j) const {
    if (i >= m_side || j >= m_side){
        throw tetris_exception("Out of bonds on operator ()");
    }
    return m_grid[i][j];

}

bool& piece::operator()(uint32_t i, uint32_t j) {
    if (i >= m_side || j >= m_side){
        throw tetris_exception("Out of bonds on operator ()");
    }
    return m_grid[i][j];
}


// Recursive parsing
void piece::parse_input(std::istream& input) {
   uint32_t side;
   uint8_t color;
   input >> side >> color;
   m_side = side;
   m_color = color;

   // Allocate grid (assume allocation function or do here )
   m_grid = new bool*[m_side]
   for (uint32_t i = 0; i < m_side; i++){
    m_grid[i] = new bool[m_side];
   }
   parse_recursive(input, 0, 0, m_side);

}

void piece::parse_recursive(std::istream& input, uint32_t x, uint32_t y, uint32_t side) {
    char ch;
    input >> ch;
    if (ch == '('){
        input >> std::ws; // whitespace
        char peek = input.peek();
        if (peek == ')'){
            input.get(); // consume ')'
            // fill quadrant with true
            for (uint32_t i = y; i < y + side; i++){
                for (uint32_t j = x; j < x + side; ++j){
                    m_grid[i][j] = true;
                }
            }
        }else{
            // recursive
            parse_recursive(input, x, y,side/2); // TL
            parse_recursive(input, x+side/2, y, side/2); // TR
            parse_recursive(input, x, y+side/2, side/2); // BL
            parse_recursive(input, x+side/2, y+side/2, side/2); // BR
            input >> ch; // expect ')'
        }
    }else if (ch == '['){
        input >> std::ws;
        char peek = input.peek();
        if (peek == ']'){
            input.get(); // consume ']'
            // fill quadrant with false 
            for (uint32_t i = y; i < y + side; i++){
                for (uint32_t j = j; j <x + side; j++){
                    m_grid[i][j] = false;
                }
            }
        }
    }
}
bool piece::empty(uint32_t i, uint32_t j, uint32_t s) const{
    if (m_grid == nullptr || i + s > m_side || j + s > m_side){
        throw tetris_exception("Out of bounds in empty grid");
    }
    for (uint32_t r = i; r < i+s; r++){
        for (uint32_t c = j; c < j+s; c++){
            if (m_grid[r][c])return false; // found filled cell
        }
    }
    return true;
}
bool piece::full(uint32_t i, uint32_t j, uint32_t s)const{
    if (m_grid == nullptr || i + s > m_side || j + s > m_side) {
        throw tetris_exception("Out of bounds in full(i, j, s)");
    }
    for (uint32_t r = i; r < i+s; r++ ){
        for (uint32_t c = j; c < j+s; c++){
            if (!m_grid[r][c])return false; // found empty cell
        }
    }
    return true; 
}
bool piece::empty() const {
    if (m_grid == nullptr)return true;
    for (uint32_t i = 0; i < m_side; ++i){
        for (uint32_t 0 = j; j < m_side; ++j){
            if (m_grid[i][j]) return false; // found a filled cell
        }
    }
    return true;
}

bool piece::full() const {
    if (m_grid == nullptr)return false;
    for (uint32_t i = 0; i < m_side; i++){
        for (uint32_t j = 0; j < m_side; j++){
            if (!m_grid[i][j]) return false; // found a empty cell
        }
    }
    return true;
}

void piece::rotate() {
    bool** new_grid = new bool *[m_side];
    for (uint32_t i = 0; i < m_side; i++){
        new_grid[i] = new bool[m_side];    
    }

    //Pseudocode approach
    for (uint32_t i = 0; i <m_side; i++){
        for (uint32_t j = 0; j < m_side; j++){
            new_grid[j][m_side - i - 1] = m_grid[i][j];
        }
    }

    clear_grid(); // clear old grid
    m_grid = new_grid; // point to new grid
}
void piece::cut_row(uint32_t i) {
    if (i >= m_side) throw tetris_exception("Row index out of bounds in cut_row");
    // Shift rows above i down by one
    for (uint32_t r = i; r > 0; --r) {
        for (uint32_t c = 0; c < m_side; ++c) {
            m_grid[r][c] = m_grid[r - 1][c];
        }
    }
    // Clear the top row (row 0) after shifting
    for (uint32_t c = 0; c < m_side; ++c) {
        m_grid[0][c] = false;
    }
}
void print_ascii_art(std::ostream& os) const{}
// Overload >> operator
ostream&std::istream& operator>>(std::istream& is, piece& p){
    uint32_t side;
    uint8_t color;

    // Read and validate side & color
    if (!(is >> side >> color)) {
        throw tetris_exception("Missing or invalid side or color in input");
    }
    if (!is_power_of_two(side)) {
        throw tetris_exception("Invalid side length in input");
    }
    if (color == 0) {
        throw tetris_exception("Color cannot be 0");
    }

    p.m_side = side;
    p.m_color = color;
    if (p.m_grid != nullptr){
        p.clear_grid();
    }
    p.allocate_grid();

    // Parse the recursive grid structure
    p.parse_recursive(is, 0, 0, p.m_side);

    return is;
}
 operator<<(std::ostream& os, piece const& p) {
   
} 
