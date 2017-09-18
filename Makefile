run		:main.o
			g++ main.cpp util.cpp heap.cpp -o run

clean			:
				 rm *.o
			
cleanAll		:
				 rm *.o run