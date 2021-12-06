SRC = src
BUILD = build
EXE_DIR = exe

BIN = ${BUILD}/opengl_app
EXE = ${EXE_DIR}/opengl_app

all:
	g++ ${SRC}/main.cpp -o ${BIN} -lglut -lGLU -lGL

run:
	./${BIN}

build_exe:
	g++ ${SRC}/main.cpp -o ${BIN} -lglut -lGLU -lGL
	cp ${BIN} ${EXE}

run_exe:
	./${EXE}

clean:
	rm ${BIN}