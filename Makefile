CC = gcc
CFLAGS = -Wall -Wextra -std=c11
TARGET = Station_meteo

SRCS = main.c alerte.c stats.c temperature_input.c affichage.c
OBJS = $(SRCS)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: clean