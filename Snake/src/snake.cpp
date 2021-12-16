#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <termios.h>
#include <stropts.h>
#include <stdio.h>
#include <iterator>

/// Debug mode
bool debug = false;
std::string garbage_input = "";
/// dimensions
const int width = 25;                      
const int height = 25;                      
const char border_char ='*';                      
const char block ='#';                      
const char* clearcommand = "clear";        

int read_s = 0;
/// global arrays for Data Records
int background[height][width];  
int snake[50][2];               
int food[2]={0,0};              
int score = 0;                  
int snakelen = 3;               
int speed = 1;   
int lap = 190;                    

/// temporary variables
int bytesWaiting, i;
int px,py,nx, ny;
char k;
int h,w;
int x,y;
int movementx = 0;            
int movementy = -speed;                


int _kbhit() {
    static const int STDIN = 0;
    static bool initialized = false;

    if (!initialized) {
        // Use termios to turn off line buffering
        termios term;
        tcgetattr(STDIN, &term);
        term.c_lflag &= ~ICANON;
        tcsetattr(STDIN, TCSANOW, &term);
        setbuf(stdin, NULL);
        initialized = true;
    }

    //int bytesWaiting;
    ioctl(STDIN, FIONREAD, &bytesWaiting);
    return bytesWaiting;
}

/// Initialise background borders Onto Array
void initialise_background(void){
    // insert top border
    for(i=0; i<width; i++){
        background[0][i]=3;
    }

    // insert left border
    for(i=0; i<height; i++){
        background[i][0]=3;
    }

    // insert right border
    for(i=0; i<height; i++){
        background[i][width-1]=3;
    }

    // insert bottom border
    for(i=0; i<width; i++){
        background[height-1][i]=3;
    }
}



/// Initialise Snake Coordinates
void initialise_snake(void){

    snake[0][0]=width/2; /// Coordinates x
    snake[0][1]=height/2; /// Coordinates y

    snake[1][0]=width/2; /// Coordinates x
    snake[1][1]=height/2 + 1; /// Coordinates y

    snake[2][0]=width/2; /// Coordinates x
    snake[2][1]=height/2 + 2; /// Coordinates y


    snake[3][0]=width/2; /// Coordinates x
    snake[3][1]=height/2 + 3; /// Coordinates y


    snake[4][0]=width/2; /// Coordinates x
    snake[4][1]=height/2 + 4; /// Coordinates y

}



/// Update Snake
void update_snake_coordination(void){
    //int px,py,nx, ny;
    px = snake[0][0];
    py = snake[0][1];
    snake[0][0] = px + movementx;
    snake[0][1] = py + movementy;
    nx = snake[0][0];
    ny = snake[0][1];

    for(i=1; i<snakelen; i++){
        nx = snake[i][0];
        ny = snake[i][1];
        snake[i][0] = px;
        snake[i][1] = py;
        px = nx;
        py = ny;
    }
}



/// Install Snake Coordinates Into Background Array rev = ( 1 To Draw And 0 To Erase)
void draw_snake_in_background(const int rev){
    //int x,y;

    for(i=0; i<snakelen; i++){
        x = snake[i][0];
        y = snake[i][1];
        if((x!=0)&&(y!=0)){
        	if(background[y][x] != 2) {
        		background[y][x]=rev;
			}
        }

    }

}


/// Print Array Frame
void print_array_frame(void) {
    for(h = 0; h < height; h++) {
        for(w = 0; w < width; w++) {
            i = background[h][w];
			if(snake[0][1] == h && snake[0][0] == w){
            	std::cout << "@ ";
            } else if(i == 1){
            	std::cout << block << " ";
            } else if(i == 2){
            	std::cout << "+ ";
            } else if(i == 3){
            	std::cout << border_char << " ";
            } else {
            	std::cout << "  ";
            }
        }
        std::cout << std::endl;
    }

	if(debug) {
		for (int i = 1; i < snakelen; i++) {
			std::cout << snake[i][0] << ":" << snake[i][1] << " ";
			if(snake[0][0] == snake[i][0] && snake[0][1] == snake[i][1]) {
				std::cout << "!!!!!!SELFATE!!!!!!";
			}
		}
		std::cout << '\n';
		std::cout << "food[" << food[0] << "][" << food[1] << "]\n";
		std::cout << "snake[" << snake[0][0] << "][" << snake[0][1] 
			<< "] = " << background[snake[0][0]][snake[0][1]] << "\n";
		std::cout << read_s << "Wrong input: " << garbage_input << '\n';
	}
}


/// Clear Background
void clear_background(void){
    system(clearcommand);
}


/// Update loop
void mainloop(void){
    clear_background();          // clear background
    draw_snake_in_background(1); // Install Snake
    print_array_frame();         // Print Frame
    draw_snake_in_background(0); // Uninstall Snake
}



/// Waiting Function
void sleepcp(int milliseconds) {
    clock_t time_end;
    time_end = clock() + milliseconds * CLOCKS_PER_SEC/1000;
    while (clock() < time_end) {}
}


/// Reaction On Press Button Of Keyboard
void reaction_on_keyboard(const char k){
	
    if((k == 'd' || k == 'C' || k == '6') && movementx != -speed){
        // Right Turn
        movementx = speed;
        movementy = 0;
    } else if((k == 'a' || k == 'D' || k == '4') && movementx != speed){
        // Left Turn
        movementx = -speed;
        movementy = 0;
    } else if((k == 'w' || k == 'A' || k == '8') && movementy != speed){
        // Turn Up
        movementx = 0;
        movementy = -speed;
    } else if((k == 's' || k == 'B' || k == '2') && movementy != -speed){
        // Turn Down
        movementx = 0;
        movementy = speed;
    } else if(k == 'q' || k == 'z' || k == 'c'){
        std::cout << "[+] Exit Safely [+]" << std::endl;
        exit(0);
    } else {
		garbage_input = k;
	}
}

bool is_on_snake(int x, int y) {
	for (int i = 1; i < snakelen; i++) {
		if(x == snake[i][0] && y == snake[i][1]) {
			return true;
		}
	}
	return false;
}

void cook_food(void){
    if(food[0] == 0) {
        x = rand() % (width - 2) + 1;
        y = rand() % (height - 2) + 1;
		if(!is_on_snake(x, y)) {
    	    food[0] = x;
    	    food[1] = y;
	        background[y][x] = 2;
		} else {
			cook_food();
		}
    }
}

void capture_food(void){
    x = food[0];
	y = food[1];

    if((x == snake[0][0]) && (y == snake[0][1])){
        background[y][x] = 0;
        food[0] = 0;
        score++;
        snakelen++;
        cook_food();
    }
}

bool check_selfeating() {
    px = snake[0][0];
    py = snake[0][1];
	for (int i = 1; i < snakelen; i++) {
		if(px == snake[i][0] && py == snake[i][1]) {
			return true;
		}
	}
	return false;
}

void check_over_lapping(){
    px = snake[0][0];
    py = snake[0][1];
    if((px == 0) || (px == (width - 1)) || (py == 0) || (py == (height - 1))
		|| check_selfeating()){
    	std::cout << "  GAME OVER! SCORE:	" << score << std::endl;
    	exit(0);
    }
}

void loop(void){
    int frame = 0;
    x = 0;
    y = 0;

    while(x < 500){
        if(_kbhit()) {
        	std::cin >> k; //arrow - 3 iterations
			if (k == '^' || k == '[' || k == '') {
				std::cin >> k;
				continue; 
			}
			read_s++;
			reaction_on_keyboard(k);
        }
        sleepcp(lap);
        update_snake_coordination();
        mainloop();
        check_over_lapping();       
        cook_food();                
        capture_food();   
		std::string spaces(width - 15, ' ');
        std::cout << spaces << "< Frame : " << frame << "  | Score  : " << score << " > "<< std::endl;
        frame++;
    }
}

int main(int argc, char* argv[]){
	if(argc == 2) {
 		long arg = strtol(argv[1], NULL, 10);
		if (arg == 1) {
			debug = true;
		}
	}
    initialise_background();
    initialise_snake();
    loop();
}
