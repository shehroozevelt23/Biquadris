XX = g++
CXXFLAGS = -std=c++14 -Wall -MMD -Werror=vla
EXEC = biquadris
OBJECTS = main.o block.o cell.o coordinate.o game.o iblock.o jblock.o lblock.o oblock.o sblock.o tblock.o zblock.o player.o level.o level0.o level1.o level2.o level3.o level4.o GraphicsDisplay.o window.o
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	                ${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC} -lX11

-include ${DEPENDS}

.PHONY: clean

clean:
	                rm ${OBJECTS} ${EXEC} ${DEPENDS}


