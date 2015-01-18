print '\x1b[31m' + "\n--------------------L-System--------------------" + '\033[0m'

libs = Split("""
sfml-graphics
sfml-window
sfml-system
""")

sources = Split("""
src/application/main.cpp
src/application/Application.cpp
""")

Program(target = 'L-System', source = sources, LIBS = libs, CXXFLAGS = "-std=c++11")
