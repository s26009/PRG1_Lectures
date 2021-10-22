#include <iostream>

class Line {
   public:
      void setLength( double len );
      double getLength(void );
      Line(std::string msg);   // This is the constructor declaration
      ~Line();  // This is the destructor: declaration
 
   private:
      std::string message;
};
 
// Member functions definitions including constructor
Line::Line(std::string msg) {
	message = msg;
}
Line::~Line(void) {
   std::cout << "DESTRUCTION! " << message << "\n";
}

// Main function for the program
int main() {
   Line line = Line("I'm Hleb");
 
   return 0;
}
