#include <stdio.h>

void open_file(char *filename, FILE **file) {
  *file = fopen(filename, "r");
  if (!*file) {
    // Обработайте ошибку открытия файла
  }
}

void close_file(FILE *file) {
  if (file) {
    fclose(file);
  }
}

void read_file() {
  FILE *file;
  open_file(filename, &file);
  if (file) {
    // ... Читайте содержимое файла
    close_file(file);
  }
}

void write_file() {
  FILE *file;
  open_file(filename, &file);
  if (file) {
    // ... Запишите данные в файл
    close_file(file);
  }
}

int main() {
  read_file();
  write_file();
  return 0;
}
