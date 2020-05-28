main: fun.o
    g++ -o main main.cpp fun.o
fun:
    g++ -c fun.cpp
clean:
    rm *.o main
