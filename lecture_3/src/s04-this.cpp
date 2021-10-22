#include <iostream>

class Line {
   public:
      void setLength( double len );
      double getLength(void );
      Line(std::string msg);
 	  void print_via_this();
   private:
      std::string message;
};
 
Line::Line(std::string msg) {
	message = msg;
}
void Line::print_via_this() {
   std::cout << this->message << " " << (*this).message << "\n";
}

int main() {
	Line line = Line("I'm Hleb");
	line.print_via_this();
	return 0;
}
