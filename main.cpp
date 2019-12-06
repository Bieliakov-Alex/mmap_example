#include <iostream>
#include <stdio.h>
#include <sys/mman.h>

int main(int argc, char *argv[]) {

  FILE *file_to_map = fopen("file.bin", "w+");

  int i = -1;

  while (i != 0) {
    std::cin >> i;
    if (i != 0) {
      fwrite(&i, sizeof(int), 1, file_to_map);
    }
  }

  fclose(file_to_map);

  file_to_map = fopen("file.bin", "r+");

  fseek(file_to_map, 0L, SEEK_END);

  long int length = ftell(file_to_map);

  fseek(file_to_map, 0, SEEK_SET);

  int file_decriptor = fileno(file_to_map);

  int *map = reinterpret_cast<int *>(
      mmap(0, length, PROT_READ | PROT_WRITE, MAP_SHARED, file_decriptor, 0));
  if (map == MAP_FAILED) {
    std::cout << "Map error!" << std::endl;
    fclose(file_to_map);
    return 0;
  }

  for (i = 0; i < length / sizeof(int); ++i) {
    std::cout << map[i] << std::endl;
  }

  // while (fread(&i, sizeof(int), 1, file_to_map) == 1) {
  //   std::cout << i << std::endl;
  // }

  munmap(map, length);

  fclose(file_to_map);

  std::cout << "End!" << std::endl;

  return 0;
}
