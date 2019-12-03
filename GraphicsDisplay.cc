#include "GraphicsDisplay.h"

GraphicsDisplay::GraphicsDisplay() {

    // Top Divider
    window.fillRectangle(0, 44, 500, 1, 9);

    // Center Divider
    window.fillRectangle(246, 0, 8, 500, 9);

    // Bottom Divider
    window.fillRectangle(0, 441, 500, 1, 9);

    // Left/Right Dividers

    window.fillRectangle(0, 0, 4, 500, 9);
    window.fillRectangle(496, 0, 4, 500, 9);

}


void GraphicsDisplay::notify(Player &whoFrom) {
    int playernum = whoFrom.getId();
    int x_base = 0;
    (playernum == 1)? x_base = 4 : x_base = 254;

    int y_base = 45;

    //clear the top part
    window.fillRectangle(x_base, 0, 242, 44, 0);

    string lev = to_string(whoFrom.getlevel());
    window.drawString(x_base + 1, 15, "Level:     " + lev);
    
    string sco = to_string(whoFrom.getscore());
    window.drawString(x_base + 1, 30, "Score:     " + sco);

    string hi = to_string(whoFrom.gethigh());
    window.drawString(x_base, 45, "High:      " + hi);

    // Clear the entire grid
    window.fillRectangle(x_base, y_base, 242, 396, 0);

    // Update the grid

    

    for (int i = 0; i < whoFrom.getHeight(); i++) {
        for (int j = 0; j < whoFrom.getWidth(); j++) {
            string display = whoFrom.getgrid()[i][j].get_display_value();
            int x_val = (j * 22) + x_base;
            int y_val = (i * 22) + y_base;

            if (whoFrom.getgrid()[i][j].getisblind() == true) {
                window.fillRectangle(x_val, y_val, 22, 22, 9);
            }
            else {

                if (display == "I") {
                    window.fillRectangle(x_val, y_val, 22, 22, 6);
                }
                else if (display == "J") {
                    window.fillRectangle(x_val, y_val, 22, 22, 4);
                }
                else if (display == "L") {
                    window.fillRectangle(x_val, y_val, 22, 22, 2);
                }
                else if (display == "O") {
                    window.fillRectangle(x_val, y_val, 22, 22, 3);
                }
                else if (display == "S") {
                    window.fillRectangle(x_val, y_val, 22, 22, 7);
                }
                else if (display == "Z") {
                    window.fillRectangle(x_val, y_val, 22, 22, 5);
                }
                else if (display == "T") {
                    window.fillRectangle(x_val, y_val, 22, 22, 1);
                }
                else if (display == "*") {
                    window.fillRectangle(x_val, y_val, 22, 22, 8);
                }
                else {
                }
            }
        }
    }

    for (int i = 0; i < whoFrom.getHeight(); i++) {
        window.fillRectangle(x_base, y_base + 22*i, 242, 1, 0);
    }
    for (int j = 0; j < whoFrom.getWidth(); j++) {
        window.fillRectangle(x_base + 22 *j, y_base, 1, 396, 0);
    }


    //clear the bottom part
    window.fillRectangle(x_base, 443, 242, 57, 0);

    

    window.drawString(x_base + 1, 457, "Next: ");

    Block *next = whoFrom.getnextblock();
    switch(next->getname()[0]){
        case 'I' : 
        for(int i = 0; i < 4; i++){
            window.fillRectangle(x_base + 100 + i * 22, 449, 22, 22, 1);
        }
        break;

        case 'J':
        window.fillRectangle(x_base + 100, 449, 22, 22, 4);
        window.fillRectangle(x_base + 100, 449 + 22, 22, 22, 4);
        window.fillRectangle(x_base + 100 + 22, 449 + 22, 22, 22, 4);
        window.fillRectangle(x_base + 100 + 44, 449 + 22, 22, 22, 4);
        break;

        case 'O':
        window.fillRectangle(x_base + 100, 449, 22, 22, 3);
        window.fillRectangle(x_base + 100, 449 + 22, 22, 22, 3);
        window.fillRectangle(x_base + 100 + 22, 449 + 22, 22, 22, 3);
        window.fillRectangle(x_base + 100 + 22, 449, 22, 22, 3);
        break;

        case 'S':
        window.fillRectangle(x_base + 100, 449, 22, 22, 7);
        window.fillRectangle(x_base + 100, 449 + 22, 22, 22, 7);
        window.fillRectangle(x_base + 100 + 22, 449, 22, 22, 7);
        window.fillRectangle(x_base + 100 - 22, 449 + 22, 22, 22, 7);
        break;
        
        case 'L':
        window.fillRectangle(x_base + 100 + 44, 449, 22, 22, 2);
        window.fillRectangle(x_base + 100, 449 + 22, 22, 22, 2);
        window.fillRectangle(x_base + 100 + 22, 449 + 22, 22, 22, 2);
        window.fillRectangle(x_base + 100 + 44, 449 + 22, 22, 22, 2);
        break;

        case 'Z':
        window.fillRectangle(x_base + 100, 449, 22, 22, 5);
        window.fillRectangle(x_base + 100 + 44, 449 + 22, 22, 22, 5);
        window.fillRectangle(x_base + 100 + 22, 449, 22, 22, 5);
        window.fillRectangle(x_base + 100 + 22, 449 + 22, 22, 22, 5);
        break;     

        case 'T':
        window.fillRectangle(x_base + 100, 449, 22, 22, 1);
        window.fillRectangle(x_base + 100 + 44, 449, 22, 22, 1);
        window.fillRectangle(x_base + 100 + 22, 449, 22, 22, 1);
        window.fillRectangle(x_base + 100 + 22, 449 + 22, 22, 22, 1);
        break;
    }
    for (int i = 0; i <= 2; i++) {
        window.fillRectangle(x_base + 100 - 44, 449 + 22*i, 110, 1, 0);
    }
    for (int j = -2; j <= 3; j++) {
        window.fillRectangle(x_base + 100 + 22*j , 449, 1, 50, 0);
    }
}
