CXX := g++
CXXFLAGS := -std=c++11 -Wall -Iinclude

SRC_DIR := src
INC_DIR := include
SRCS := $(SRC_DIR)/main.cpp \
        $(SRC_DIR)/Car.cpp \
        $(SRC_DIR)/Renter.cpp \
        $(SRC_DIR)/RentalManager.cpp \
        $(SRC_DIR)/User.cpp \
        $(SRC_DIR)/AuthenticationManager.cpp
OBJS := $(SRCS:.cpp=.o)

TARGET := rental

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^
	@echo "Build successful! Run with: ./$(TARGET)"

$(SRC_DIR)/main.o: $(SRC_DIR)/main.cpp $(INC_DIR)/RentalManager.h $(INC_DIR)/AuthenticationManager.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(SRC_DIR)/Car.o: $(SRC_DIR)/Car.cpp $(INC_DIR)/Car.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(SRC_DIR)/Renter.o: $(SRC_DIR)/Renter.cpp $(INC_DIR)/Renter.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(SRC_DIR)/RentalManager.o: $(SRC_DIR)/RentalManager.cpp $(INC_DIR)/RentalManager.h $(INC_DIR)/Car.h $(INC_DIR)/Renter.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(SRC_DIR)/User.o: $(SRC_DIR)/User.cpp $(INC_DIR)/User.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(SRC_DIR)/AuthenticationManager.o: $(SRC_DIR)/AuthenticationManager.cpp $(INC_DIR)/AuthenticationManager.h $(INC_DIR)/User.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)
	@echo "Clean successful!"

run: $(TARGET)
	./$(TARGET)

rebuild: clean all

.PHONY: all clean run rebuild
