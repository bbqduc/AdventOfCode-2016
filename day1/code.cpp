// Task description at http://adventofcode.com/2016/day/1

#include <cstdio>
#include <cmath>
#include <set>

struct Vec2D {
  int x;
  int y;
  Vec2D(int x = 0, int y = 0) : x(x), y(y) {}
};

bool operator<(const Vec2D &v1, const Vec2D &v2) {
  return v1.x == v2.x ? v1.y < v2.y : v1.x < v2.x;
}

int main() {
  std::set<Vec2D> visited; // TODO : might be nicer to do some kind of line-segment intersection calculation instead of just storing all points
  Vec2D pos, dir(0, 1);
  bool repeated = false;

  while (true) {
    char turn;
    int distance;
    int values_read = scanf(" %c%d, ", &turn, &distance);
    if (values_read != 2) {
      break;
    }
    if (turn == 'L') {
      dir = Vec2D(-dir.y, dir.x);
    } else {
      dir = Vec2D(dir.y, -dir.x);
    }
    if (!repeated) {
      for (int i = 0; i < distance; ++i) {
        pos.x += dir.x;
        pos.y += dir.y;
        auto result = visited.insert(pos);
        if (!result.second) {
          repeated = true;
          visited.clear();
          printf("First repeat visit: (%d,%d)\n", pos.x, pos.y);
          printf("Manhattan distance: %d\n", std::abs(pos.x) + std::abs(pos.y));
        }
      }
    }
  }

  printf("Final position: (%d,%d)\n", pos.x, pos.y);
  printf("Manhattan distance: %d\n", std::abs(pos.x) + std::abs(pos.y));
}
