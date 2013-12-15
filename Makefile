TARGET=ld28

BINDIR=bin
SRCDIR=src
OBJDIR=obj

CXXFLAGS=-g -MMD -Wall -Werror -std=c++11 -stdlib=libc++
LDFLAGS=-lentityx -ltermbox -llua

SRCS=$(wildcard $(SRCDIR)/*.cpp)
OBJS=$(subst $(SRCDIR),$(OBJDIR),$(subst .cpp,.o,$(SRCS)))
DEPENDS=${OBJS:.o=.d}

OUTPUT=$(BINDIR)/$(TARGET)

all: $(TARGET)

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@
-include $(DEPENDS)

$(OBJDIR):
	mkdir $(OBJDIR)

$(TARGET): $(OBJDIR) $(OBJS)
	$(CXX) -o $(OUTPUT) $(OBJS) $(LDFLAGS)

.PHONY: clean run

clean:
	rm -rf $(OBJDIR)
	rm -rf $(OUTPUT).dSYM
	rm -f $(OUTPUT)

run:
	cd $(BINDIR) && ./$(TARGET) &> debug.log
