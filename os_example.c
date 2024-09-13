// os_example.c - A simple operating system example with bootloader, kernel, file system, and shell

#include <stdint.h>

// VGA text mode memory address
#define VIDEO_MEMORY ((volatile char*)0xb8000)
#define SCREEN_WIDTH 80
#define SCREEN_HEIGHT 25

// Simple file system data structures
#define SECTOR_SIZE 512

typedef struct {
    uint8_t  name[8];
    uint8_t  ext[3];
    uint8_t  attributes;
    uint8_t  reserved;
    uint8_t  creation_time;
    uint8_t  creation_date;
    uint8_t  last_access_date;
    uint8_t  high_cluster;
    uint8_t  modification_time;
    uint8_t  modification_date;
    uint8_t  low_cluster;
    uint32_t size;
} __attribute__((packed)) FAT12Entry;

// Kernel functions
void print_string(const char* str) {
    volatile char* video_memory = VIDEO_MEMORY;
    while (*str) {
        *video_memory++ = *str++;
        *video_memory++ = 0x07; // White text on black background
    }
}

void clear_screen() {
    volatile char* video_memory = VIDEO_MEMORY;
    for (int i = 0; i < SCREEN_WIDTH * SCREEN_HEIGHT; i++) {
        video_memory[i * 2] = ' ';
        video_memory[i * 2 + 1] = 0x07; // White text on black background
    }
}

void kernel_main() {
    clear_screen();
    print_string("Loading OS...\n");
    print_string("Simple Shell:\n");

    // Simple shell loop
    char* video_memory = (char*)VIDEO_MEMORY + 160; // Start after "Simple Shell:\n"
    while (1) {
        print_string("> ");
        // For demonstration, we only support a single command "hello"
        const char* command = "hello";
        print_string(command);
        print_string("\n");
        while (1);  // Halt CPU
    }
}

// File system functions (mock implementations)
void read_sector(uint32_t sector, void* buffer) {
    // Mock implementation for reading a sector
    // Replace with actual disk I/O code
}

void load_file(const char* filename, void* buffer) {
    // Mock implementation for loading a file
    print_string("Loading file: ");
    print_string(filename);
    print_string("\n");
}

// Execute on-disk executables (mock implementation)
void execute_file(const char* filename) {
    print_string("Executing file: ");
    print_string(filename);
    print_string("\n");
    // Load and execute file (mock implementation)
}
