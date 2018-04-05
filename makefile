all:
	$(shell mkdir -p build)
	g++ src/main.cpp src/memory.cpp src/instructions.cpp src/cpu_operator.cpp src/loggers.cpp -o build/main