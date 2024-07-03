export OPENCV_FLAGS=$(pkg-config --cflags --libs opencv4)

g++ codes/im_arith.cpp $OPENCV_FLAGS -o execs/arith.out
g++ codes/im_colour.cpp $OPENCV_FLAGS -o execs/colour.out 

cp execs/arith.out ../assignment/execs/arith.out
cp execs/colour.out ../assignment/execs/colour.out
