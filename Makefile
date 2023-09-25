TARGET=minitwow-vsgenerator
TEST=csvtest
CXX=g++

.PHONY: defaulty
defaulty:
	@echo Wrong usage. You must type either \"make vsgenerator\", \"make vsshower\", or \"make resulter\".
	@echo \"make clean\" is also available!
	@echo By the way, \"make clean-clean\" deletes files ending ~ will be deleted too!

.PHONY: clean
clean:
	rm -f *.o $(TARGET) $(TEST)

.PHONY: clean-clean
clean-clean:
	rm -f *.o *~ $(TARGET)

vsgenerator:	vsgenerator.cpp vsgenerator.hpp vsoption.hpp
	$(CXX) vsgenerator.cpp -o $(TARGET)

.PHONY: vsshower
vsshower:
	@echo Sorry, vsshower is not available yet....

.PHONY: resulter
resulter:
	@echo Sorry, resulter is not available yet....

.PHONY: csvtest
csvtest:	csvtest.cpp
	$(CXX) csvtest.cpp -o $(TEST)
