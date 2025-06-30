# Компилятор и флаги
CC = clang
CFLAGS = -Wall -Wextra -Werror -std=c11 -g
INCLUDES = -I.
LDLIBS = -lm  # При необходимости добавьте другие библиотеки (-lpthread и т.д.)

# Исходные файлы и структура
SRCS = main.c type.c vm.c
OBJS = $(addprefix build/,$(SRCS:.c=.o))  # Все .o файлы в папке build
TARGET = GC  # Исполняемый файл тоже в build

# Создание папки build
$(shell mkdir -p build)

# Основной таргет
all: $(TARGET)

# Линковка
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@ $(LDLIBS)

# Правило для сборки .o файлов в build/
build/%.o: %.c type.h vm.h
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Очистка
clean:
	rm -rf build

# Пересборка
rebuild: clean all

.PHONY: all clean rebuild