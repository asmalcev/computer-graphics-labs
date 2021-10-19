SRC = src
BUILD = build

BIN = ${BUILD}/opengl_app

all:
	g++ ${SRC}/main.cpp -o ${BIN} -lglut -lGLU -lGL

run:
	./${BIN}

clean:
	rm ${BIN}