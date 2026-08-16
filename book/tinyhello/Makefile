# 编译器与链接器定义
CC      := gcc
LD      := ld

# 编译选项：极致体积 + 禁绝对标准库依赖
CFLAGS  := -O3 \
           -Wall \
           -Wextra \
           -c \
           -fno-builtin \
           -fno-asynchronous-unwind-tables \
           -fno-ident \
           -ffreestanding

# 链接选项：剥离符号表 + 优化段对齐
LDFLAGS := -e nomain \
           -s \
           -z max-page-size=0x1000

TARGET  := tiny
OBJS    := tiny.o

all: $(TARGET)

# 1. 编译阶段：.c -> .o
%.o: %.c
	$(CC) $(CFLAGS) $< -o $@

# 2. 链接阶段：.o -> 可执行文件 (使用 ld)
$(TARGET): $(OBJS)
	$(LD) $(LDFLAGS) $^ -o $@

run: $(TARGET)
	@./$(TARGET)

clean:
	rm -f $(TARGET) *.o

.PHONY: all run clean