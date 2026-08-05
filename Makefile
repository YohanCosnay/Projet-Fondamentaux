CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -Iinclude
SRCDIR = src
BUILDDIR = build
TARGET = $(BUILDDIR)/meteo

CFLAGS += -MMD -MP
DEPS    = $(OBJS:.o=.d)
-include $(DEPS)

SRCS = $(SRCDIR)/main.c $(SRCDIR)/alerte.c $(SRCDIR)/stats.c $(SRCDIR)/saisie.c $(SRCDIR)/affichage.c
OBJS = $(SRCS:$(SRCDIR)/%.c=$(BUILDDIR)/%.o)

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