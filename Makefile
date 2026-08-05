CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -Iinclude
SRCDIR = src
BUILDDIR = build
TARGET = $(BUILDDIR)/meteo

CFLAGS += -MMD -MP
DEPS    = $(OBJS:.o=.d)
-include $(DEPS)

SRCS = $(wildcard $(SRCDIR)/*.c)
OBJS = $(patsubst $(SRCDIR)/%.c, $(BUILDDIR)/%.o, $(SRCS))

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $@

$(BUILDDIR)/%.o: $(SRCDIR)/%.c | $(BUILDDIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILDDIR):
	mkdir -p $@

clean:
	rm -rf $(BUILDDIR)

re: clean all

.PHONY: all clean re