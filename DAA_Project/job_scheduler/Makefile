CXX      = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -O2
TARGET   = job_scheduler
SRCS     = main.cpp scheduler.cpp

all: $(TARGET)

$(TARGET): $(SRCS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRCS)

clean:
	rm -f $(TARGET) $(TARGET).exe
