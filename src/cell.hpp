#ifndef CELL_HPP
#define CELL_HPP

enum cellStatus { Empty, Busy, Delete };

template <typename T, typename K>
struct Cell {
  cellStatus status;
  K key;
  T data;
};

#endif  // CELL_HPP
